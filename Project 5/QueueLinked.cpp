//Name: QueueLinked.cpp
//Purpose: cpp file for QueueLinked.h
//Author: Simon Shrestha 

#ifndef QUEUELINKED_CPP
#define QUEUELINKED_CPP

#include <iostream>

#include "QueueLinked.h"

//constructor for node class
template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& newDataItem, QueueLinked<DataType>::QueueNode* nextPtr)
{
	dataItem = newDataItem;
	next = nextPtr;
}

//creates an empty queue
template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber)
{
	front = NULL;
	back = NULL;
}

//copy constructor
template <typename DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked& other){
	front = NULL;
	back = NULL;
	
	*this = other; // use operator overload
}

// operator = overload
template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other) {
  QueueNode* other_cursor = other.front;

  if( this == &other ) {
    return *this; 
  }else{
    // clear *this to start fresh
    clear();

    if( other.isEmpty() ) {
      // nothing to copy, return empty queue
      return *this;
    }
    else {
      while( other_cursor != NULL ) {
    	// copy over data 
        enqueue( other_cursor->dataItem );
        other_cursor = other_cursor->next;
      }
    }
  }

  return *this;
}

//free any memory that is being used by the queue.
template <typename DataType>
QueueLinked<DataType>::~QueueLinked()
{
    clear();
}

// Inserts newDataItem at the end of the queue.
template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error) 
{
    if (isFull()) {
	throw logic_error("push() while queue full");
    }

    QueueNode* temp = new QueueNode(newDataItem, 0);

    if (isEmpty()) {
	front = temp; //make front the new node
    }else{
	back->next = temp; // add node to back of the queue
    }
    back = temp;
}

//removes node from the front of the queue
template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error) 
{
    if (isEmpty()) {
	throw logic_error("dequeue() while queue empty");
    }

    DataType temp = front->dataItem;
    QueueNode* delPtr = front;
    front = front->next;
    delete delPtr;

    return temp;
}

//Removes all nodes from queue 
template <typename DataType>
void QueueLinked<DataType>::clear() 

{
    while( !isEmpty() ) {
    // dequeue the current node
    dequeue();
	}
}

//checkw whether the queue is empty 
template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const 
{
    return front == NULL;
}

template <typename DataType>
bool QueueLinked<DataType>::isFull() const 

{
    return false;
}

template < typename DataType >
void QueueLinked<DataType>:: showStructure () const

// Linked list implementation. Outputs the elements in a queue. If
// the queue is empty, outputs "Empty queue".

{
    QueueNode* p;   // Iterates through the queue

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != 0 ; p = p->next )
	{
	    if( p == front ) 
	    {
		cout << "[" << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}

#endif		// #ifndef QUEUELINKED_CPP

