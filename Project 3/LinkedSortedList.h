/******************************
	File gotten directly from the book
*********************************/
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 12-2

/** ADT sorted list: Link-based implementation.
 @file LinkedSortedList.h */

#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedSortedList 
{
private:
   Node<ItemType>* headPtr; // Pointer to first node in the chain
   int itemCount;           // Current count of list items
   
   // Locates the node that is before the node that should or does
   // contain the given entry.
   // @param anEntry  The entry to find.
   // @return  Either a pointer to the node before the node that contains
   //    or should contain the given entry, or nullptr if no prior node exists.
   Node<ItemType>* getNodeBefore(const ItemType& anEntry) const;
   
   // Locates the node at a given position within the chain.
   Node<ItemType>* getNodeAt(int position) const;
   
   // Returns a pointer to a copy of the chain to which origChainPtr points.
   Node<ItemType>* copyChain(const Node<ItemType>* origChainPtr);
   
public:
   LinkedSortedList();
   LinkedSortedList(const LinkedSortedList<ItemType>& aList);
   virtual ~LinkedSortedList();   

   void insertSorted(const ItemType& newEntry);
   bool removeSorted(const ItemType& anEntry);
   int getPosition(const ItemType& newEntry) ;
   
   // The following methods are the same as given in ListInterface:
   bool isEmpty() const;
   int getLength() const;
   bool remove(int position);
   void clear();
   ItemType getEntry(int position) const ;
}; // end LinkedSortedList

//constructor
template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(){
	headPtr = nullptr;
	itemCount = 0; 
}

//copy constructor
template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList){
	headPtr = copyChain(aList.headPtr);
}

//destructor
template<class ItemType>
LinkedSortedList<ItemType>:: ~LinkedSortedList(){
	clear();
}

//copychain
template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>:: copyChain(const  Node<ItemType>* origChainPtr){
	Node<ItemType>* copyChainPtr;
	
	if(origChainPtr == nullptr){
		copyChainPtr = nullptr;
		
	}else{
		copyChainPtr = new Node<ItemType>(origChainPtr->getItem());
		copyChainPtr-> setNext(copyChain(origChainPtr->getNext()));
		
	}
	
	return copyChainPtr;
}

//getNodeBefore
template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const{
   Node<ItemType>* curPtr = headPtr;
   Node<ItemType>* prevPtr = nullptr;
   
   while ( (curPtr != nullptr) && (anEntry > curPtr->getItem()) )
   {
      prevPtr = curPtr;
      curPtr = curPtr->getNext();
   } 
   
   return prevPtr;
}

//getNodeAt
template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeAt(int position) const{
	Node<ItemType>* temp = headPtr;
	
	for(int i = 1; i < position; i++){
		temp = temp-> getNext();
	}
	return temp;
}

//insertSorted 
template<class ItemType>
void LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry){
   Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
   Node<ItemType>* prevPtr = getNodeBefore(newEntry);
   
   if (isEmpty() || (prevPtr == nullptr)) 
   {
      newNodePtr->setNext(headPtr);
      headPtr = newNodePtr;
   }
   else 
   {
      Node<ItemType>* aftPtr = prevPtr->getNext();
      newNodePtr->setNext(aftPtr);
      prevPtr->setNext(newNodePtr);
   } 
   
   itemCount++;
	delete newNodePtr;
	newNodePtr = nullptr;

}

//remove sorted
template<class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry){
	return remove (getPosition(anEntry));
}

//get position
template<class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& anEntry){
	Node<ItemType>* temp = headPtr;
	int index = 1;
	
	while(temp != nullptr && !(anEntry == temp -> getItem())){
		index++;
		temp = temp->getNext(); 
	}
	
	return index; 
}

//isEmpty
template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const{
	return headPtr == nullptr;
}

//getLength
template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const{
	return itemCount;
}

//remove
template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position){

	bool canRemove = (position > 1) && (position <= itemCount);
	if(canRemove){
		Node<ItemType>* currNode = nullptr;
	
		if(position == 1){
			currNode = headPtr;
			headPtr = headPtr -> getNext();
		}else{
		    Node<ItemType>* prevPtr = getNodeAt(position - 1);
		    
		    currNode = prevPtr->getNext();
		    prevPtr->setNext(currNode->getNext());
		}
		currNode->setNext(nullptr);

		delete currNode;
		currNode = nullptr;
		itemCount-- ; // Decrease count of entries
	    	} 
    return canRemove;
}

//clear
template<class ItemType>
void LinkedSortedList<ItemType>::clear(){
	while (!isEmpty())
		remove (1);
}

//getEntry
template<class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const{
	Node<ItemType>* temp = headPtr;
	
	while(position > 1){
		temp = temp->getNext();
		position--;
	}
	return temp->getItem();
}

#endif
