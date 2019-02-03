//
//	Most of the implementations from this file where taken directly from the book
//	and slides, however some of the functions I had to implement myself.
//
//

#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include <memory>
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"
#include <iostream>

template<class ItemType>
class BinaryNodeTree
{
private:
    std::shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------

    int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
    int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    // Recursively adds a new node to the tree in a left/right fashion to
    // keep the tree balanced.
    auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                     std::shared_ptr<BinaryNode<ItemType>> newNodePtr);

    // Recursively deletes all nodes from the tree.
    void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

    // Recursive traversal helper methods:
    void preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
    void inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
    void postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinaryNodeTree();
    BinaryNodeTree(const ItemType& rootItem);
    virtual ~BinaryNodeTree();

    //------------------------------------------------------------
    // Public BinaryTreeInterface Methods Section.
    //------------------------------------------------------------
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    bool add(const ItemType& newData); // Adds a node
    void clear();
    ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);
    bool contains(const ItemType& anEntry) const;

    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;
}; // end BinaryNodeTree


//////////////////////////////////////////////////////////////
//      Protected Methods Section
//////////////////////////////////////////////////////////////
template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if (subTreePtr == nullptr)
        return 0;
    else
        return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                            getHeightHelper(subTreePtr->getRightChildPtr()));
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const{
    if(subTreePtr == nullptr){
        return 0;
    }else{
        1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
    }
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                           std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    if (subTreePtr == nullptr)
        return newNodePtr;
    else
    {
        auto leftPtr = subTreePtr->getLeftChildPtr();
        auto rightPtr = subTreePtr->getRightChildPtr();

        if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
        {
            rightPtr = balancedAdd(rightPtr , newNodePtr);
            subTreePtr->setRightChildPtr(rightPtr );
        }
        else
        {
            leftPtr = balancedAdd(leftPtr, newNodePtr);
            subTreePtr->setLeftChildPtr(leftPtr);
        } 

        return subTreePtr;
    }  
} 

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) {
    if (subTreePtr != nullptr)
    {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        subTreePtr.reset();
    }
}

//////////////////////////////////////////////////////////////
//      Protected Tree Traversal
//////////////////////////////////////////////////////////////

template<class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
    if (treePtr != nullptr)
    {
        ItemType item = treePtr->getItem(); //get parent
        visit(item); // go to parent
        preorder(visit, treePtr->getLeftChildPtr()); //transverse through left sub tree
        preorder(visit, treePtr->getRightChildPtr()); //transverse through right sub tree
    }
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
    if (treePtr != nullptr) // check if empty
    {
        inorder(visit, treePtr->getLeftChildPtr()); //transverse through left sub tree
        ItemType item = treePtr->getItem(); // get parent
        visit(item); // go to parent
        inorder(visit, treePtr->getRightChildPtr()); //transverse through right sub tree
    }
}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
    if (treePtr != nullptr)
    {
        postorder(visit, treePtr->getLeftChildPtr()); // transverse through left sub tree
        postorder(visit, treePtr->getRightChildPtr()); // transverse through right sub tree
        ItemType item = treePtr->getItem(); // get parent
        visit(item); // go to parent
    }
}

//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(){

}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem){
    rootPtr = std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr);
}

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree() {
    destroyTree(rootPtr);
}

//////////////////////////////////////////////////////////////
//      Public Methods Section
//////////////////////////////////////////////////////////////

template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const {
    return rootPtr == nullptr;
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const {
    return getHeightHelper(rootPtr);
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const {
    return getNumberOfNodesHelper(rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::clear() {
    destroyTree(rootPtr);
    rootPtr.reset();
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData) {
    auto newPtr = std::make_shared<BinaryNode<ItemType>>(newData);
    rootPtr = balancedAdd(rootPtr, newPtr);
    return true;
}

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException) {
    bool success = false;
    auto NodePtr = findNode(rootPtr, anEntry, success);

    if (success)
        return NodePtr->getItem();
    else
        throw NotFoundException("Not found in tree!");
}

template<class ItemType>
bool BinaryNodeTree<ItemType>:: contains(const ItemType& anEntry) const {
    bool success = false;
    findNode(rootPtr, anEntry, success);
    return success;
}

template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {
    preorder(visit, rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
    inorder(visit, rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {
    postorder(visit, rootPtr);
}

#endif
