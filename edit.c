#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

/* This function returns the number of rows(no of unique products) that are present in the inventory */
int no_of_products()
{
	FILE *fptr;				//Declaring a file pointer
	fptr = fopen("data.txt", "r");		//Opening file
	if(fptr == NULL)			//Checking if file exists or not
	{
		printf("No file found!\n");
		return -1;
	}
	int id, price, quantity;
	int len = 0;
	fscanf(fptr, "%d ", &id);		//Reading the first number of the file(first ID)
	if(id == 0)
		return 0;
	do{
		char name[30];
		char category[30];
		fscanf(fptr, "%s %d %d %s", name, &price, &quantity, category);	//Reading the name, price, quantity, category of the product in the current row
		len++;								//Increasing len by 1
		fscanf(fptr, "%d ", &id);					//Reading the first number of the next line
	}while(id != 0);							//Keep reading as long as the first number of the line is not '0' zero(EOF)
	fclose(fptr);								//Close file
	return len;								//Return number of products in the file(inventory)
}


/* This function is used to read all the contents of the file data.txt into the array "products" of custom data type "product" with alias "pro" */
int read_file(pro *products)
{
	FILE *fptr;
	fptr = fopen("data.txt", "r");
	if(fptr == NULL)
	{
		printf("No file found!\n");
		return -1;
	}
	int id, price, quantity;
	int i = 0;
	fscanf(fptr, "%d ", &id);							//Reading ID of the first row in the file data.txt
	do{
		char name[30];
		char category[30];
		fscanf(fptr, "%s %d %d %s", name, &price, &quantity, category);		//Reading name, price, quantity and category of product in i^th row of file
		(*(products+i)).id = id;						//Assigning id to ID of products[i]
		(*(products+i)).price = price;						//Assigning price to price of products[i]
		(*(products+i)).quantity = quantity;					//Assigning quantity to quantity of products[i]
		strcpy((*(products+i)).name, name);					//Assigning name to name of products[i]
		strcpy((*(products+i)).category, category);				//Assigning category to category of products[i]
		i++;									//Increasing i by 1
		fscanf(fptr, "%d ", &id);						//Reading ID of next line
	}while(id != 0);
	fclose(fptr);
	return 0;
}


/* This function is used to write all the contents of the array "products" of length "len" into the file data.txt */
void write_file(pro *products, int len)
{
	FILE *fptr;
	fptr = fopen("data.txt", "w");
	int rows = 0;
	while(rows < len)
	{
		int id, price, quantity;
		char name[30];
		char category[30];
		id = (*(products+rows)).id;							//Assiging ID of products[i] to variable id
		price = (*(products+rows)).price;						//Assiging price of products[i] to variable price
		quantity = (*(products+rows)).quantity;						//Assiging quantity of products[i] to variable quantity
		strcpy(name, (*(products+rows)).name);						//Assiging name of products[i] to variable name
		strcpy(category, (*(products+rows)).category);					//Assiging category of products[i] to variable category
		fprintf(fptr, "%d %s %d %d %s", id, name, price, quantity, category);	//Writing the variables id, name, price, quantity, category into data.txt
		fprintf(fptr, "%c", '\n');							//Writing new line character into data.txt
		rows++;										//Increasins rows by 1
	}
	fprintf(fptr, "%d", 0);									//Writing 0 at the last line of the data.txt
	fclose(fptr);
}


/* This function is used to add another product with a unique non-pre-existing ID into the file data.txt */
int product_add()
{
	printf("\n");
	pro *products;									//Declare array "products"
	int len = no_of_products();							//Recieving number of rows currently in data.txt into variable len
	if(len == -1)
		len++;
	products = (pro *)malloc((len+1) * sizeof(pro));				//Dynamically allocating memory to array "products"
	read_file(products);								//Reading contents of file into array "products"
	int id, price, quantity;
	char name[30]; char category[30];
	printf("Enter the ID of the product : \n");
	scanf("%d", &id);								//Accepting ID of new product into variable id
	int flag = 0;
	for(int i = 0; i < len; i++)                                                   //Checking if there already exists a product with same ID
        {
                if((*(products+i)).id == id)
                {
                        flag++;
                        break;
                }
        }
        if(flag)
	{
                printf("ITEM CANNOT BE ADDED TO INVENTORY BECAUSE ANOTHER ITEM WITH SIMILAR ID IS ALREADY PRESENT IN INVENTORY!\n");
		return -1;
	}
	printf("Enter the name of the product : \n");
	scanf("%s", name);								//Accepting name of new product into variable name
	printf("Enter the price of a unit of the product : \n");
	scanf("%d", &price);								//Accepting price of new product into variable price
	printf("Enter the quantity of the product to be stocked : \n");
	scanf("%d", &quantity);								//Accepting quantity of new product into variable quantity
	printf("Enter the category of the product : \n");
	scanf("%s", category);								//Accepting category of new product into variable category
	(*(products+len)).id = id;							//Assigning id to id of products[len]
	(*(products+len)).price = price;						//Assigning price to price of products[len]
	(*(products+len)).quantity = quantity;						//Assigning quantity to quantity of products[len]
	strcpy((*(products+len)).name, name);						//Assigning name to name of products[len]
	strcpy((*(products+len)).category, category);					//Assigning category to category of products[len]
	write_file(products, (len+1));							//Writing contents of array "products" into data.txt
	printf("ITEM ADDED TO INVENTORY!\n\n");
	free(products);
	return 0;
}


/* This is to restock a particular product in the inventory accoring to its ID */
int restock()
{
	printf("\n");
	int n;
	printf("Enter the number of unique items you want to restock : \n");			//Accepting nunmber of unique products user wants to restock
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("\n");
		pro *products;									//Declaring variable "products" of data type "product"
		int len = no_of_products();
		if(len == -1)
			return 0;
		products = (pro *)malloc(len * sizeof(pro));
		read_file(products);								//Reading contents of file into array "products"
		printf("Enter the ID of the product you want to restock : ");
		int ID, flag = 0;
		scanf("%d", &ID);								//Accepting ID of product which the user wants to restock
		for(int j = 0; j < len; j++)							//Searching for the matching ID in the file		
		{
			if((*(products+j)).id == ID)
			{
				int quantity;
				printf("Enter the quantity of the item shipped in : ");
				scanf("%d", &quantity);						//Accepting the additional quantity of product to be restocked
				(*(products+j)).quantity += quantity;				//Increasing quantity of product
				write_file(products, len);					//Writing modified "products" into file data.txt
				flag++;
				break;
			}
		}
		free(products);
		if(flag == 0)									//Giving message to indicate no such product with entered ID exits
			printf("No item with that ID exists in inventory\n");
	}
	printf("RESTOCKING COMPLETE\n\n");
	return 0;
}


/* To remove any product with quantity = 0 from the inventory */
int refresh()
{
	pro *products;										//Declaring array "products" containing all the items in data.txt
	pro *new;										//Declaring a new array "new"
	int len = no_of_products();
	products = (pro *)malloc(len * sizeof(pro));
	read_file(products);									//Reading contents of data.txt into array "products"
	new = (pro *)malloc(len * sizeof(pro));
	int j = 0;
	for(int i = 0; i < len; i++)
	{
		if((*(products+i)).quantity != 0)						//If quantity of product is not 0, the adding it to array "new"
		{
			new[j] = products[i];
			j++;
		}
	}
	write_file(new, j);									//Writing contents of array "new" into file data.txt
	free(products);
	free(new);
	return 0;
}


/* To sell items from the inventory */
int shipping()
{
	printf("\n");
	int n;
	printf("Enter the number of unique products you want to ship out : \n");		//Accept number of unique products user wants to purchase
	scanf("%d", &n);
	int total = 0;										//To store the total cost of purchasing all the products
	for(int i = 0; i < n; i++)
	{
		printf("\n");
		pro *products;									//Declaring array "products"
		int len = no_of_products();
		if(len == -1)
			return 0;
		products = (pro *)malloc(len * sizeof(pro));
		read_file(products);								//Reading contents of file data.txt into array "products"
		int ID, flag = 0;
		printf("Enter the ID of the item to be shipped : \n");
		scanf("%d", &ID);								//Accepting ID of product which user wants to purchase
		for(int j = 0; j < len; j++)
		{
			if((*(products+j)).id == ID)						//Searching for matching ID
			{
				int ship;
				printf("Enter the quantity of the item to be shipped : \n");
				scanf("%d", &ship);						//Accepting quantity to be purchased
				if((*(products+j)).quantity < ship)				//Checking if quantity to be purchased is available in inventory?
					printf("Shipment not possible. Not enough quantity available!\n");
				else
				{
					(*(products+j)).quantity -= ship;			//Reducing quantity of products[j] 
					total += ((*(products+j)).price * ship);		//Increasing "total" by appropriate amount
				}
				write_file(products, len);					//Writing modified data of "products" into file data.txt
				flag++;								//Updating flag
				break;
			}
			
		}
		if(flag == 0)									//Checking if ID entered by user existed or not
			printf("No item with that ID exists in inventory!\n");
	}
	printf("SHIPPING COMPLETE\n");
	printf("GRAND TOTAL OF SHIPPING : %d\n", total);					//Displaying grand total of shipping
	printf("\n");
	refresh();										//Removing all products from data.txt with quantity = 0
	return 0;
}

/* To remove a product from inventory completely */
int REMOVE()
{
	printf("\n");
	pro *products;										//Declaring array "products"
	int len = no_of_products();
	if(len == -1)
		return 0;
	products = (pro *)malloc(len * sizeof(pro));
	read_file(products);									//Reading contents of file data.txt into array "products"
	int ID, flag = 0;
	printf("Enter ID of the product you want to completely remove from inventory : \n");
	scanf("%d", &ID);									//Accepting ID of product to be removed from inventory
	for(int i = 0; i < len; i++)								//Searching for the ID
	{
		if((*(products+i)).id == ID)
		{
			(*(products+i)).quantity = 0;						//Setting quantity of product with matching ID to 0
			write_file(products, len);						//Writing modified "products" into data.txt
			flag++;									//Updating flag
			break;
		}
	}
	if(flag == 0)										//Checking if ID entered by user even exits or not
		printf("No item with such ID exists in inventory!\n");
	else
		refresh();									//Removing all products in data.txt with quantity = 0
	printf("ITEM REMOVAL COMPLETE!\n");
	return 0;
}


/* To change the price of a product in inventory */
int price_change()
{
	printf("\n");
	pro *products;										//Declaring an array "products"
	int len = no_of_products();
	if(len == -1)
		return 0;
	products = (pro *)malloc(len * sizeof(pro));
	read_file(products);									//Reading contents of file into array "products"
	int ID, flag = 0;
	printf("Enter ID of the product who's price is to be changed : \n");
	scanf("%d", &ID);									//Accepting ID of the products who's price is to be changed
	for(int i = 0; i < len; i++)								//Searching for matching ID
	{
		if((*(products+i)).id == ID)
		{
			int new_price;
			printf("Enter the new price of the product : \n");
			scanf("%d", &new_price);						//Accepting new price of product from user
			(*(products+i)).price = new_price;					//Setting new price of product
			write_file(products, len);						//Writing contents of modified "products" into data.txt
			flag++;									//Updatin flag
			break;
		}
	}
	if(flag == 0)										//Checking if ID entered by user even existed or not
		printf("No such product with that ID exists in inventory!\n");
	else
		printf("Price changed!\n");							
	printf("\n");
	return 0;
}
