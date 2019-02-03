// Implementations for StackLinked.h

#include <iostream>
#include <stdexcept>
using namespace std;
#include "StackLinked.h"

//Name: constructor
//Purpose: constructor for node class
//param: nodeData, nextPtr
//Return: None
template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackLinked<DataType>::StackNode* nextPtr){
// Creates a stack node have nodeData and nextPtr
dataItem = nodeData;
next = nextPtr;

} 

//Name: constructor
//Purpose: constructor for stack list
//Param: maxNumber
//Result: none
template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber){
	top = 0;
	
}

//Name: copy constructor
//Purpose: copies one stack to another
//Param: reference to other stack
//Return: none
template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other){
	top = NULL;
	//use overloaded assignment operator
	*this = other;

}

//Name: assignment operator
//Purpose: copying stacks
//Param: reference to the other stack
//Return: pointer to stack
template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other){
	StackNode* otherStack = other.top; //pointer to other stack's top
	StackNode* previousNode = NULL; //pointer to previous node
	StackNode* newNode = NULL; //pointer to new node
	
	if(!other.isEmpty()){ //checks if other stack is empty
		top = new StackNode(other.top->dataItem, NULL); //mak top equal to other top
		previousNode = top; // making previous node top
		while(otherStack->next != NULL){ //iterate through entire stack
			otherStack = otherStack->next; // iterate other stack
			newNode = new StackNode(otherStack->dataItem, NULL); // copy over nodes 
			previousNode->next = newNode; // make newNode the node after the previous one
			previousNode = previousNode->next; //iterate previous node
		}
	}
	
	return *this;

}

//Name: destructor
//Purpose: deleting stack
//Param: none
//Return: none
template <typename DataType>
StackLinked<DataType>::~StackLinked(){
	clear(); // use clear function to deallocate entire stack

}

//Name: push
//Purpose: to add a node to the top of thhe stack
//Param: newDataItem
//Return: none
template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error){
	if(isFull()){
		throw logic_error("can't push while stack is full"); //throw error if full 
	}
	
	if(isEmpty()){
		top = new StackNode(newDataItem, 0); // create new node if stack is empty
	}else{
		StackNode* newNode = top; // make newNode as top 
		top = new StackNode(newDataItem, newNode); // allocate for new node
	}
}

//Name: pop
//Purpose: to remove the top node
//Param: none
//Return: topData
template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error){
	if(isEmpty()){
		throw logic_error("can't pop while stack is empty"); //throw error if empty
	}
	
	DataType topData = top -> dataItem; // save the value of the top node
	top = top->next; // make top equal the next node
	return topData; //return the data of the node deleted
}

//Name: clear
//Purpose: clear the stack
//Param: none
//Return: none
template <typename DataType>
void StackLinked<DataType>::clear(){
	while(!isEmpty()){
		pop(); // use pop function to delete entire stack
	}
}

//Name: isEmpty
//Purpose: checks if stack is empty
//Param: none 
//Return: true or false
template <typename DataType>
bool StackLinked<DataType>::isEmpty() const{
	return top == 0;

}

//Name: isFull()
//Purpose: checks if stack is full
//Param: none
//Return: false 
template <typename DataType>
bool StackLinked<DataType>::isFull() const{
	return false; //linked stack can never be full
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const 

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << '[' << temp->dataItem << ']'<<"\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}













