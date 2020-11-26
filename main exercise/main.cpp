#include <iostream>
#include "Sales_data.h"


int main(){
	Sales_data a("hola");
	print(std::cout,a);




	/*
	Sales_data total; // main variable to hold data
	if (read(std::cin, total)) { //read the first book/transaction
		Sales_data trans; // new variable to hold the next transaction (or new)
			
			while(read(std::cin, trans)) { // read said transaction to trans variable
				if (total.isbn() == trans.isbn()) // check if the isbn is the same
					total.combine(trans); // combine both variables to get the total
				else {
					print(std::cout, total) << std::endl; //print the first variable
					total = trans; // change first variable for new (second) variable
				}
			}
			print(std::cout, total) << std::endl; // print the last transaction
	} else { // there was no input
		std::cerr << "No data?!" << std::endl; // notify the user
	}
*/
}