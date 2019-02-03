//--------------------------------------------------------------------
//
//  Laboratory 7                                               Queue.h
// 
//  Class declaration of the abstract class interface to be used as
//  the basis for implementations of the Queue ADT.
//
//--------------------------------------------------------------------

#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include <iostream>

using namespace std;

//--------------------------------------------------------------------

template <typename DataType>
class Queue {
  public:
    static const int MAX_QUEUE_SIZE = 8;

    virtual ~Queue();

    virtual void enqueue(const DataType& newDataItem) throw (logic_error) = 0;
    virtual DataType dequeue() throw (logic_error) = 0;

    virtual void clear() = 0;

    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual void showStructure() const = 0;
};

template <typename DataType>
Queue<DataType>::~Queue() 
// Not worth having a separate class implementation file for the destuctor
{}

#endif		// #ifndef QUEUE_H
