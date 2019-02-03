//Nane: BinarySearchTree.h
//Prupose: implementation for BinarySearchTree class
//Author: Simon Shrestha

// Some of the functions where removed from the header as they were not needed
// to complete the assignment. Dr. Kostas stated in class that we only really needed
// to implement the functions that were required to complete the assignment.

#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include <memory>
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"
#include <iostream>

template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
private:
    std::shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
    // Recursively finds where the given node should be placed and
    // inserts it in a leaf at that point.
    auto placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                   std::shared_ptr<BinaryNode<ItemType>> newNode);

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinarySearchTree();
    BinarySearchTree(const ItemType& rootItem);
    BinarySearchTree(const BinarySearchTree<ItemType>& tree);
    virtual ~BinarySearchTree();

    //------------------------------------------------------------
    // Public Methods Section.
    //------------------------------------------------------------
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    bool add(const ItemType& newEntry);
    void clear();
    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;
}; // end BinarySearchTree

//placeNode function
template<class ItemType>
auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNode){
    if(subTreePtr == nullptr){
        return newNode; //return newNode if the sub tree points to null
    }else{
        if(subTreePtr->getItem() > newNode->getItem()){
            //if the new node is greater than transverse through the left sub tree
            subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), newNode));
        }else{
            //else transverse through the right sub tree
            subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr(),newNode));
        }

        return subTreePtr;
    }
}

//defualt constructor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() {

}
//parameterized constructor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) {
    rootPtr = std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr); //create a node for root
}
//copy constrcutor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree) {
    rootPtr = this->copyTree(tree.rootPtr); //use copy tree function to copy the tree
}

//destructor
template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
    this->destroyTree(rootPtr); // use destroy tree function
}

//check if tre is empty
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const{
    return rootPtr == nullptr;
}

//obtain height of tree
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
    return this->getHeightHelper(rootPtr); //use function from BinaryNodeTree.h
}

//obtain the number of nodes within the tree
template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
    return this->getNumberOfNodesHelper(rootPtr); //use function from BinaryNodeTree.h
}
//add a new node to the tree
template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
    auto newPtr = std::make_shared<BinaryNode<ItemType>>(newData);
    rootPtr = placeNode(rootPtr, newPtr);
    return true;
}

//clear the tree
template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
    destroyTree(rootPtr);
    rootPtr.reset();
}

//pre order transverse
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
    this->preorder(visit, rootPtr); //function in BinaryNodeTree.h
}

//in order transverse
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
    this->inorder(visit, rootPtr); //function in BinaryNodeTree.h
}

//post order transverse
template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
    this->postorder(visit, rootPtr); //function in BinaryNodeTree.h
}



#endif
