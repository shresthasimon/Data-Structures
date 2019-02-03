// Name: QueueArray.cpp
// Purpose: Cpp file for QueueArray.h
//Author: Simon Shrestha 

#ifndef QUEUEARRAY_CPP
#define QUEUEARRAY_CPP

#include <iostream>

#include "QueueArray.h"

//creates an empty array
template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber)
{
	maxSize = maxNumber;
	front = -1;
	back = -1;
    dataItems = new DataType[maxNumber];
}

//deletes the array
template <typename DataType>
QueueArray<DataType>::~QueueArray() 
{
    delete[] dataItems;
}

//copy constructor
template <typename DataType>
QueueArray<DataType>::QueueArray(const QueueArray& other) {
  maxSize = NULL;
  front = -1;
  back = -1;  // reset all values
  dataItems = NULL;

  // use the overloaded = operator
  *this = other;
}

//operator = overload
template <typename DataType>
QueueArray<DataType>& QueueArray<DataType>::operator=(const QueueArray<DataType>& other) {
  int cursor = -1;
  if( this == &other ) {
	// check if the queues are the same
    return *this;
  }
  else {
    if( maxSize != other.maxSize ) {
      // copy max size
      maxSize = other.maxSize;

      if( dataItems != NULL ) {
        delete [] dataItems; // delete any items that may still be in teh array
      }

      dataItems = new DataType [maxSize];
    }

    // copy both front and back
    front = other.front;
    back = other.back;
    cursor = front;

    if( (front == back) && (front > -1) ) {
      // if there is only one element
      dataItems[cursor] = other.dataItems[cursor];
    }
	// if there are more than one element
    else if( front > -1 ) {
      do {
        if( cursor == maxSize ) {
          cursor = 0;
        }
        dataItems[cursor] = other.dataItems[cursor];
        ++cursor;

      } while( cursor != (back + 1) );
    }
  }
  return *this;
}

//inserts a node at the end the queue
template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error) 
{
    if (isFull()) {
	throw logic_error("enqueue() while queue full");
    }

    back = (++back) % maxSize; //create a circular array
    dataItems[back] = newDataItem;
    if ( front == -1 )
       front = 0;
}

//removes the node that is at the front of the list
template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error) 
{
    if (isEmpty()) {
	throw logic_error("dequeue() while queue empty");
    }

    int retIndex = front;
    if ( front == back )
    {
       front = -1;
       back  = -1;
    }
    else
       front = ( ++front ) % maxSize; // iterate the array to the next value

    return dataItems[retIndex]; // return the data that was deleted
}

//deletes all array from the queue
template <typename DataType>
void QueueArray<DataType>::clear() 
{
    front = -1;
    back = -1;
}

//checks if the array is empty
template <typename DataType>
bool QueueArray<DataType>::isEmpty() const 
{
    return front == -1;
}

//checks if the array is full
template <typename DataType>
bool QueueArray<DataType>::isFull() const 
{
    return front == (back + 1) % maxSize;
}

template <typename DataType>
void QueueArray<DataType>::showStructure() const 
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue".

{
    int j;   // Loop counter

    if ( front == -1 )
       cout << "Empty queue" << endl;
    else
    {
       cout << "Front = " << front << "  Back = " << back << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       if ( back >= front )
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) && ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       else
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) || ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       cout << endl;
    }
}

#endif		//#ifndef QUEUEARRAY_CPP
