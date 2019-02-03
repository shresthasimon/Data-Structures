//Name: StackArray.cpp
//Purpose: implementations for StackArray.h
//Author: Simon Shrestha
#include <iostream>
#include <stdexcept>
using namespace std;

#include "StackArray.h"

//Name: Parameterized Constructor
//Purpose: Initalize a stack array
//Param: max array of 8
//Return: None
template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber){
	maxSize = maxNumber; //set maxSize to 8
	top = -1; //intialize top
	dataItems = new DataType[maxNumber]; // allocate for array
}

//Name: Copy constructor
//Purpose: copies one array stack to another
//Param: refrence to a stack
//Return: None
template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other){
	maxSize = other.maxSize; //copy size
	top = other.top; // copy top
	dataItems = new DataType[maxSize]; // allocate 
	for(int i = 0; i <= top; i++){ //copy over items
		dataItems[i] = other.dataItems[i];
	}
}

//Name: Operator Overload for =
//Purpose: make two stacks the same
//Param: refrence to stack
//Return: newly copied stack
template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other){
	if(this != &other){ //if the stacks are different
		if(maxSize < other.maxSize){ 
			delete[] dataItems; //if the other stack has more spaces, allocate more space for our stack
			dataItems = new DataType[other.maxSize]; 
		}
		
		maxSize = other.maxSize; // copy size
		top = other.top; //copy top
		for(int i = 0; i <= top; i++){ //copy elements
			dataItems[i] = other.dataItems[i];
		}
	}
	
	return *this;
}

//Name: Destructor
//Purpose: deallocate stack
//Param: none
//Return: none
template <typename DataType>
StackArray<DataType>::~StackArray(){
	delete[] dataItems; // deallocate array
}

//Name: push
//Purpose: add elemen to stack
//Param: item to push
//Return: none
template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error){
	if(isFull()){ //checks if full, otherwise spit out warning
		throw logic_error("Can't push if stack is full");
	}
	
	dataItems[top+1] = newDataItem; //create a new top
	top++; // move top
	
}

//Name: pop
//Purpose: remove top of stack
//Param: none
//Return: most recent item removed
template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error){
	if(isEmpty()){ // checks of empty
		throw logic_error("Can't pop if stack is empty");
	}
	
	DataType temp = dataItems[top]; //save the item being removed 
	top--; //remove top
	
	return temp; // return item removed
	
}

//Name: clear
//Purpose: clear stack
//Param: none
//Return: none
template <typename DataType>
void StackArray<DataType>::clear(){
	top = -1; //make top a garbage value
}

//Name: isEmpty
//Purpose: Checks if stack is empty
//Param: none
//Return: True or False
template <typename DataType>
bool StackArray<DataType>::isEmpty() const{
	return top == -1; //returns boolean for whether stack is empty
}

//Name: isFull
//Purpose: Checks if stack is full
//Param: none
//Return: True or False
template <typename DataType>
bool StackArray<DataType>::isFull() const{
	return top == maxSize-1;//returns boolean for whether stack is empty
}

template <typename DataType>
void StackArray<DataType>::showStructure() const 

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}










