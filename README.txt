Smart Inventory Management System

This project has been designed by 6 students of the International Institute of Information technology Bangalore. The six students are as follows:-
1) Ishan Jha IMT2022562 (Ishan.Jha@iiitb.ac.in)
2) Ajitesh Kumar Singh IMT2022559 (Ajitesh.Kumar@iiitb.ac.in)
3) Pratham Chawdhry IMT2022068 (Pratham.Chawdhry@iiitb.ac.in)
4) Abhinav Kumar IMT2022079 (Abhinav.Kumar@iiitb.ac.in)
5) Ketan Ghungralekar IMT2022058 (Ketan.Ghungralekar@iiitb.ac.in)
6) Krish Dave IMT2022043 (Krish.Dave@iiitb.ac.in)

Our entire application depends broadly on 6 files (3 .c source files, 1 .h header file, 1 .txt text file and 1 'make' file) and consists of a total of 20 functions being used(23 if we include all the functions int the main.c source file as well) :-

1) main.c :- This is main body of the program, to use the product this code is to be executed. "main.c" uses functions which have been defined in "edit.c" or
	     "info.c" (which we shall discuss later on). 
	     
	     It contains the following functions:-

		i) info() :- This function is used to call the various functions which displays certain information about the information of the products stored in the inventory at that moment.

		ii) edit() :- This function is used to call the various functions which are used to bring about changes in the information of the products stored in the inventory at that moment.

		iii) main() :- It is the main function of the entire project and accepts inputs from the users(serial number of the choices) to run the execute the desired command of the user.

2) edit.c :- This source file contains all the functions which are to be used to change the information about the products stored in the inventory at that moment.
	     The various functions (and their uses) declared and defined in this source file are :-

		i) int no_of_products() :- The main purpose of this function is to read and return the number of rows(no of unique products) that are present in
					   the inventory at that moment.

		ii) int read_file() :- This function is used to store all the contents of the file (all the products along with their names, price, quantity, ID,
				       and category) into a single array of a custom data type named "product" (aliased as "pro").

		iii) void write_file() :- This function is used to write all the elements of an array of the custom data-type "product" into a text file named	 
					  "data.txt", which stores information about all the products in the inventory, at all times.

		iv) int product_add() :- This function is used to accept the ID, name, quantity, price and category of a new product and add it into the	
					 inventory(write it into data.txt), provided that the ID doesn't already exist.

		v) int restock() :- This function is used to restock(increase the quantity) one or more products which alread exist in the inventory.

		vi) int refresh() :- This function scans all the products in inventory and removes them if their quantity in the inventory is zero.

		vii) int shipping() :- This function is used to place an order for items/products in the inventory(and then reduce their quantity accordingly).
				       It also generates the final bill of all the purchases.

		viii) int REMOVE() :- This function is used to remove any product from the inventory.

		ix) int price_change() :- This function is used to change the price of any product present in the inventory at that moment.


3) info.c :- This source file contains all the functions which are to be used to view details regarding any product/s that are present in the inventory.
	     The various functions(and their uses) declared and defined in the this source file are:-

		i) int save_file() :- This function is used to save the filtered results(filters given by user) into a .txt file of the user's choice.

		ii) int id_search() :- This function is used to search for a product in the inventory on the basis of its ID.

		iii) int name_search() :- This function is used to search for a product in the inventory on the basis of its name.

		iv) int display() :- Just to display the contents of the file "data.txt".

		v) int Display(pro *products, int len, int c) :- To display all the items in the array "products" of length "len", and depending on the value of
								 "c", it will print in an ascending/descending order of some factor.

		vi) int quantity_display() :- Display products on the basis of their quantity in the inventory.

		vii) int id_display() :- Display products on the basis of their ID in the inventory.

		viii) int price_display() :- Display products on the basis of their price in the inventory.

		ix) int name_display() :- Display products on the basis of their name in the inventory.

		x) int category_display() :- Display products on the basis of their category in the inventory.

		xi) int filter_search() :- Display all the items matching the filter parameters(such as price, quantity and/or category) as entered by the user.


4) functions.h :- This header file contains the definition of all the functions used accross all the three source files. It also contains the definition of the
		  custom data-type "product" which has been given the alias "pro".


5) data.txt :- This text file contains all the information(ID, name, price, quantity, category) of all the products that is present in the inventory at that
	       moment. The last line of the text file contains a '0' (zero) which is used to signify the end of the file.


6) Makefile :- This "make" file aids in simplifying building(compiling) all the program executables that may need various modules.
