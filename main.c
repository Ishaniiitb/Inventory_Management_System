#include <stdio.h>
#include "functions.h"			//Including the custom header file to make use of the functions defined in other source files.


void info()			//This function calls all the functions from info.c which are responsible ONLY FOR DISPLAYING information stored in data.txt
{
	printf("\n");
	printf("Choose the action you want to perform by entering its respective serial number\n");
	printf("1) Search a product(ID) \n2) Search a product(Name) \n3) Display items in inventory \n4) Search products based on a filter : \n");
	int c1,c2;				//Accepting the choice of the user in variable c1
	scanf("%d", &c1);
	switch(c1)
	{
		case 1: id_search();	//Calling id_search() from info.c
			break;

		case 2: name_search();	//Calling name_search() from info.c
			break;

		case 3:
			printf("\n");	
			printf("Display accoring to(sorted according to) : \n");
			printf("1) Recently added \n2) ID of Product \n3)Name of Product \n4)Price of Product \n5) Quantity of Product available\n");
			printf("6) Category of Products : \n");
			scanf("%d", &c2);	//Taking another choice from the user
			switch(c2)
			{
				case 1: display();	//Calling display() from info.c
					break;

				case 2: id_display();	//Calling id_display() from info.c
					break;

				case 3: name_display();	//Calling name_display() from info.c
					break;

				case 4: price_display();// Calling price_display() from info.c
					break;

				case 5: quantity_display();	//Calling quantity_display() from info.c
					break;

				case 6: category_display();	//Calling category_display() from into.c
					break;

				default : printf("Invalid option entered!\n");	//Displaying message if invalid choice is entered
			}
			break;

		case 4: filter_search();	//Calling filter_search() from info.c
			break;

		default : printf("Invalid option entered!\n");	// Displaying message if invalid choice is entered
	}
	printf("\n");
}


void edit()		//This function calls all the functions from edit.c which are responsible FOR EDITING OR ALTERING the information stored in data.txt
{
	printf("\n");
	int choice;
	printf("Choose the action you want to perform by entering its respective serial number\n");
	printf("1) Add a new product to inventory \n2) Restock an existing product in inventory \n3) Shipping/selling an item in inventory \n");
	printf("4) Remove a product from inventory \n5) Change the price of existing product in inventory : \n");
	scanf("%d", &choice);	//Inputing choice from the user
	switch(choice)
	{
		case 1: product_add();	//Calling product_add() from edit.c
			break;

		case 2: restock();	//Calling restock() from edit.c
			break;

		case 3: shipping();	//Calling shipping() from edit.c
			break;

		case 4: REMOVE();	//Calling REMOVE() from edit.c
			break;

		case 5: price_change();	//Calling price_change() from edit.c
			break;
		
		default: printf("Invalid option entered!\n");	//Displaying message is invalid choice is entered
	}
	printf("\n");
}


int main()
{
	printf("\n");
	printf("WELCOME TO THE SMART STORE INVENTORY MANAGEMENT SYSTEM!\n");
	printf("Please choose the corresponding serial number of the actions each time you want to perform it. Thank you!\n");
	printf("1) Check information about inventory \n2)Edit information about inventory \nEnter any other number to exit : \n");
	int ch;
	scanf("%d", &ch);	//Taking input from user(choice)
	while(ch == 1 || ch == 2)
	{
		switch(ch)
		{
			case 1: info();	//Calling info() function from main.c
				break;

			case 2: edit();	//Calling edit() function from main.c
				break;
		}
		printf("\n");
		printf("1) Check information about inventory \n2)Edit information about inventory \nEnter any other number to exit : \n");
                scanf("%d", &ch);	//Taking next choice from the user
	}
	printf("\n");
	printf("THANK YOU FOR USING THE SMART STORE INVENTORY MANAGEMENT SYSTEM! WISH TO SEE YOU SOON! THANK YOU AND GOOD-BYE!\n");
	return 0;
}
