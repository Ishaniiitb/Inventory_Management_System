#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


/* To save the filter results into a file of the user's choice*/
int save_file(pro *products, int len)
{
	printf("\n");
	char file[30];
	printf("Enter the name of the file in which you want to save the filter results : \n");
	scanf("%s", file);						//Accepting the name of the file in which the user wants to store the filter results
	FILE *fptr;
        fptr = fopen(file, "w");					//Opening file
        int ID, price, quantity;
        for(int i = 0; i < len; i++)					//Writing contents of the array "prodcuts" into the file of the user's choice
        {
                char name[30]; char category[30];
                ID = (*(products+i)).id;
                price = (*(products+i)).price;
                quantity = (*(products+i)).quantity;
                strcpy(name, (*(products+i)).name);
                strcpy(category,(*(products+i)).category);
                fprintf(fptr, "%d %s %d %d %s", ID, name, price, quantity, category);
                fprintf(fptr, "%c", '\n');
        }
        fprintf(fptr, "%d", 0);
	printf("Filter results saved :) \n");
        fclose(fptr);
        return 0;
}


/* Searching a product with a matching ID in the inventory */
int id_search()
{
	pro *products;								//Declaring array "products"
	int len = no_of_products();
	if(len == -1)
		return 0;
	products = (pro *)malloc(len * sizeof(pro));
	read_file(products);							//Reading contents of file data.txt into array "products"
	printf("\n\n");
	printf("Enter the ID of the product you want to check : \n");
	int ID, flag = 0;							//Accepting ID of product
	scanf("%d", &ID);
	for(int i = 0; i < len; i++)						//Searching matching ID
	{
		if((*(products+i)).id == ID)
		{
			int price, quantity;
			char name[30];
			char category[30];
			printf("PRODUCT FOUND!\n");
			printf("\n");
			price = (*(products+i)).price;
			quantity = (*(products+i)).quantity;
			strcpy(name, (*(products+i)).name);
			strcpy(category, (*(products+i)).category);
			printf("ID of the product : %d\n", ID);
			printf("Name of the product : %s\n", name);
			printf("Price per unit of product : %d\n", price);
			printf("Quantity of product in inventory : %d\n", quantity);
			printf("Category of product : %s\n", category);				//Printing details of the matching product
			flag++;									//Updating flag
			break;
		}
	}
	if(flag == 0)										//Checking if the ID was present in the inventory or not
		printf("No such product with that ID exists in inventory!\n");
	printf("\n");
	return 0;
}


/* To search a product based on its name in the inventory */
int name_search()
{
	pro *products;
        int len = no_of_products();
	if(len == -1)
		return 0;
        products = (pro *)malloc(len * sizeof(pro));
        read_file(products);
	printf("\n\n");
        printf("Enter the name of the product you want to check : \n");
        char n[30]; int flag = 0;
        scanf("%s", n);										//Accepting name of the product
        for(int i = 0; i < len; i++)
        {
                if(strcmp((*(products+i)).name , n) == 0)					//Seaching for matching product name
                {
                        int ID, price, quantity;
                        char name[30]; char category[30];
                        printf("PRODUCT FOUND!\n");
			printf("\n");
			ID = (*(products+i)).id;
                        price = (*(products+i)).price;
                        quantity = (*(products+i)).quantity;
                        strcpy(name, (*(products+i)).name);
			strcpy(category, (*(products+i)).category);
			printf("ID of the product : %d\n", ID);
                        printf("Name of the product : %s\n", n);
                        printf("Price per unit of product : %d\n", price);
                        printf("Quantity of product in inventory : %d\n", quantity);
                        printf("Category of product : %s\n", category);				//Printing details of the matching product
                        flag++;									//Updating flag
			break;
                }
        }
        if(flag == 0)										//Check if a product with that name existed in inventory or not
                printf("No such product with that name exists in inventory!\n");
	printf("\n");
        return 0;
}


/* To display all the contents of the file as it is */
int display()
{
	printf("\n");
	pro *products;
	int len = no_of_products();
	if(len == -1)
		return 0;
	products = (pro *)malloc(len * sizeof(pro));
	read_file(products);									//Reading contents of the file data.txt into array "products"
	int ID, price, quantity;
	for(int i = len-1; i >= 0; i--)								//Displaying contents of array "products" one by one
	{
		char name[30]; char category[30];
		ID = (*(products+i)).id;
		price = (*(products+i)).price;
		quantity = (*(products+i)).quantity;
		strcpy(name, (*(products+i)).name);
		strcpy(category, (*(products+i)).category);
		printf("ID of the product : %d\n", ID);
                printf("Name of the product : %s\n", name);
                printf("Price per unit of product : %d\n", price);
                printf("Quantity of product in inventory : %d\n", quantity);
                printf("Category of product : %s\n", category);
		printf("\n");
	}
	printf("\n");
	return 0;
}


/* To display the contents of the array "products" with length "len" and in ascending order if c=0 or descending order for any other value of c */
int Display(pro *products, int len, int c)	
{
	printf("\n");
	int ID, price, quantity;
	if(c == 0)
	{
		for(int i = 0; i < len; i++)
		{
			char name[30]; char category[30];
			ID = (*(products+i)).id;
			price = (*(products+i)).price;
			quantity = (*(products+i)).quantity;
			strcpy(name, (*(products+i)).name);
			strcpy(category, (*(products+i)).category);
			printf("ID of the product : %d\n", ID);
                	printf("Name of the product : %s\n", name);
                	printf("Price per unit of product : %d\n", price);
                	printf("Quantity of product in inventory : %d\n", quantity);
                	printf("Category of product : %s\n", category);
                	printf("\n");
		}
	}
	else
	{
		for(int i = len-1; i >= 0; i--)
		{
			char name[30]; char category[30];
			ID = (*(products+i)).id;
			price = (*(products+i)).price;
			quantity = (*(products+i)).quantity;
			strcpy(name, (*(products+i)).name);
			strcpy(category, (*(products+i)).category);
			printf("ID of the product : %d\n", ID);
	                printf("Name of the product : %s\n", name);
	                printf("Price per unit of product : %d\n", price);
	                printf("Quantity of product in inventory : %d\n", quantity);
	                printf("Category of product : %s\n", category);
	                printf("\n");
		}
	}
	printf("\n");
	return 0;
}


/*Displaying the contents of data.txt on the basis of their quantity */
int quantity_display()
{
	pro *products;
	int len = no_of_products();
	if(len == -1)
		return 0;
	products = (pro *)malloc(len * sizeof(pro));
	read_file(products);								//Reading contents of data.txt into array "products"
	for(int i = 0; i < len-1; i++)							//Bubble sorting contents of "products" on basis of quantity
	{
		for(int j = 0; j < len-i-1; j++)
		{
			if((*(products+j)).quantity > (*(products+j+1)).quantity)
			{
				pro temp = products[j];
				products[j] = products[j+1];
				products[j+1] = temp;
			}
		}
	}
	int c;
	printf("For ascending order enter '0', otherwise enter any other number : \n");
	scanf("%d", &c);
	printf("\n");
	Display(products, len, c);							//Displaying contents of "products"
	return 0;
}


/* Disaplying the contents of data.txt on basis of their price */
int price_display()
{
        pro *products;
        int len = no_of_products();
	if(len == -1)
		return 0;
        products = (pro *)malloc(len * sizeof(pro));
        read_file(products);								//Reading contents of data.txt into array "products"
        for(int i = 0; i < len-1; i++)							//Bubble sorting contents of "products" on basis of price
        {
                for(int j = 0; j < len-i-1; j++)
                {
                        if((*(products+j)).price > (*(products+j+1)).price)
                        {
                                pro temp = products[j];
                                products[j] = products[j+1];
                                products[j+1] = temp;
                        }
                }
        }
        int c;
        printf("For ascending order enter '0', otherwise enter any other number : \n");
        scanf("%d", &c);
	printf("\n");
        Display(products, len, c);							//Displaying contents of "products"
        return 0;
}


/* Disaplying the contents of data.txt on basis of their id */
int id_display()
{
        pro *products;
        int len = no_of_products();
	if(len == -1)
		return 0;
        products = (pro *)malloc(len * sizeof(pro));
        read_file(products);									//Reading contents of data.txt into array "products"
        for(int i = 0; i < len-1; i++)								//Bubble sorting contents of "products" on basis of id
        {
                for(int j = 0; j < len-i-1; j++)
                {
                        if((*(products+j)).id > (*(products+j+1)).id)
                        {
                                pro temp = products[j];
                                products[j] = products[j+1];
                                products[j+1] = temp;
                        }
                }
        }
        int c;
        printf("For ascending order enter '0', otherwise enter any other number : \n");
        scanf("%d", &c);
	printf("\n");
        Display(products, len, c);								//Displaying contents of "products"
        return 0;
}


/* Disaplying the contents of data.txt on basis of their name */
int name_display()
{
        pro *products;
        int len = no_of_products();
	if(len == -1)
		return 0;
        products = (pro *)malloc(len * sizeof(pro));
        read_file(products);									//Reading contents of data.txt into array "products"
        for(int i = 0; i < len-1; i++)								//Bubble sorting contents of "products" on basis of name
        {
                for(int j = 0; j < len-i-1; j++)
                {
                        if(strcmp((*(products+j)).name, (*(products+j+1)).name) > 0)
                        {
                                pro temp = products[j];
                                products[j] = products[j+1];
                                products[j+1] = temp;
                        }
                }
        }
        int c;
        printf("For ascending order enter '0', otherwise enter any other number : \n");
        scanf("%d", &c);
	printf("\n");
        Display(products, len, c);								//Displaying contents of "products"
        return 0;
}


/* Disaplying the contents of data.txt on basis of their categor */
int category_display()
{
	pro *products;
        int len = no_of_products();
	if(len == -1)
		return 0;
        products = (pro *)malloc(len * sizeof(pro));
        read_file(products);									//Reading contents of data.txt into array "products"
        for(int i = 0; i < len-1; i++)								//Bubble sorting contents of "products" on basis of category
        {
                for(int j = 0; j < len-i-1; j++)
                {
                        if(strcmp((*(products+j)).category, (*(products+j+1)).category) > 0)
                        {
                                pro temp = products[j];
                                products[j] = products[j+1];
                                products[j+1] = temp;
                        }
                }
        }
        int c;
        printf("For ascending order enter '0', otherwise enter any other number : \n");
        scanf("%d", &c);
	printf("\n");
        Display(products, len, c);								//Displaying contents of "products"
        return 0;
}


int filter_search()
{
	printf("Enter '1' for yes and any other number for no for all the following questions.\n");
        pro *products;											//Declare array "products
        pro *items;											//Declare array "items"
        int len = no_of_products();
	if(len == -1)
		return 0;
        products = (pro *)malloc(len * sizeof(pro));							//Allocate memory to both arrays
        items = (pro *)malloc(len * sizeof(pro));
        read_file(products);										//Read contents of data.txt into array "products"
        int fprice = 500000; int fquantity = -1; int j = 0;						//Set filter quantity to -1
        char fcategory[30] = "NONE";									//Set filter category to NONE, filter price to 100000
        int choice;
        printf("Do you want to filter according to category : \n");
        scanf("%d", &choice);										//Accept category filter choice from user
        if(choice == 1)
        {
                char c[30];
                printf("Enter the category then : \n");
                scanf("%s", c);										//Set filter category to the category entered by user
                strcpy(fcategory, c);
        }
        printf("Do you want to filter according to price(all items less than or equal to entered price will be displayed) : ");
        scanf("%d", &choice);										//Accept price filter choice from user
        if(choice == 1)
        {
                printf("Enter the price then : \n");
                scanf("%d", &fprice);									//Set filter price to the price entered by user
                printf("Entered Price : %d\n", fprice);
        }
        printf("Do you want to filter according to quantity(all items with quantity greater than or equal to entered quantity will be displayed) : ");
        scanf("%d", &choice);										//Accept quantity filter choice from user
        if(choice == 1)
        {
                printf("Enter the quantity then : \n");
                scanf("%d", &fquantity);								//Set filter quantity to the quantity entered by user
                printf("Entered quantity : %d\n", fquantity);
        }
	if(strcmp(fcategory, "NONE") == 0)								//If no filter category is given
        {
                for(int i = 0; i < len; i++)
                {
                        if( ((*(products+i)).price <= fprice) && ((*(products+i)).quantity >= fquantity) ) //Check if filter conditions are satisfied
                        {
                                items[j] = products[i];				//If filter conditions are satisfied, store the product in array "items"
                                j++;
                        }
                }
        }
        else
        {
                for(int i = 0; i < len; i++)
                {
                        if( ((*(products+i)).price <= fprice) && ((*(products+i)).quantity >= fquantity) && (strcmp((*(products+i)).category, fcategory) == 0) )
                        {
                                items[j] = products[i];
                                j++;
                        }
                }
        }
        if(j == 0)										//To check if any products match filter parameters
                printf("No items found matching the filter parameters!\n");
        else
	{
                Display(items, j, 0);								//Display contents of array "items"
		printf("\n");
        	printf("Do you want to save the filter results in another file? Press 1 for yes and any other number for no \n");
		printf("Keep in mind, any pre-existing file with same file will get truncated : \n");
        	scanf("%d", &choice);								//Accept choice from user to save filter results or not
        	if(choice == 1 && j > 0)
                	save_file(items, j);							//Save filter results
	}
        return 0;
}
