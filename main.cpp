#include <iostream>

struct Sales_data {
	// new members: operations on Sales_data objects
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
	// data members are unchanged from § 2.6.1 (p. 72)
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

int main(){

Sales_data a;

	Sales_data total; // variable to hold the running sum
	if (read(std::cin, total)) { // read the first transaction
		Sales_data trans; // variable to hold data for the next transaction
			
			while(read(std::cin, trans)) { // read the remaining transactions
				if (total.isbn() == trans.isbn()) // check the isbns
					total.combine(trans); // update the running total
				else {
					print(std::cout, total) << std::endl; // print the results
					total = trans; // process the next book
				}
			}
			print(std::cout, total) << std::endl; // print the last transaction
	} else { // there was no input
		std::cerr << "No data?!" << std::endl; // notify the user

}