#include <iostream>
#include "List.h"
using namespace std; 

int getOption(); // function to print out menu


int main(){ 	
	int i;
	int val;
	NodeList<int> nlist;

	for(;;){ //infinite for loop for menu
		i = getOption();
		switch(i){
			case 1:
				cout << "Enter a number you would like to add: ";
				cin >> val; //asks user for input and places that input into the list
				nlist.add(val);
				break;
			case 2:
				nlist.del(); // deletes the most recent item added to the list
				break;
			case 3:
				cout << "The amount of items in the list is: " << nlist.amount();
				break;
			case 4:
				cout << "List: " << nlist << endl; //prints out list
				break;
			case 5:
				return 0;
		}
	}
return 0;
}

//menu function the prints out options that the user can choose from
// the user can choose an option by entering the number associtated with 
// the description
int getOption(){
	int choice;

	cout << endl
	<< " 1 - Add an Item\n"
	<< " 2 - Delete an Item\n"
	<< " 3 - Print a number of items\n"
	<< " 4 - Print all items\n"
	<< " 5 - Exit Program\n"
	<< "Enter your choice: ";

	cin >> choice;
	return choice;
}

