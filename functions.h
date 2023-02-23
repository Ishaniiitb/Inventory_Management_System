#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Defining a custom structure named "product" and giving it the alias "pro" */
typedef struct product
{
	int id;
	char name[30];
	int price;
	int quantity;
	char category[30];
}pro;

int no_of_products();
int read_file(pro *products);
void write_file(pro *products, int len);
int product_add();
int restock();
int refresh();
int shipping();
int REMOVE();
int price_change();
int save_file(pro *products, int len);
int id_search();
int name_search();
int display();
int Display(pro *products, int len, int c);
int quantity_display();
int price_display();
int id_display();
int name_display();
int category_display();
int filter_search();
