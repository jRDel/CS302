//This source file includes the class implementations of the binarysearchtree
#include <iostream>
#include <stdexcept>
#include "BinarySearchTree.h"
#include "BinaryNodeTree.h"
#include "BinaryNode.h"

using namespace std;
//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
// Places a given new node at its proper position in this binary
// search tree.
template<typename ItemType>
auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNode)
{
    if(subTreePtr==nullptr)
    {
        return newNode;
    }
    else if (subTreePtr->getItem() > newNode->getItem())
    {
        std::shared_ptr<BinarySearchTree<ItemType>> tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNode);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        std::shared_ptr<BinarySearchTree<ItemType>> tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNode);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
    
}

// Removes the given target value from the tree while maintaining a
// binary search tree.
template<typename ItemType>
auto BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,const ItemType target, bool & isSuccessful)
{
    if(subTreePtr == nullptr)
    {
        isSuccessful = false;
    }
    else if(subTreePtr->getItem() == target)
    {
        subTreePtr = removeNode(subTreePtr);
        isSuccessful = true;
    }
    else if (subTreePtr->getItem() > target)
    {
        tempPtr=removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        tempPtr=removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
    
}

// Removes a given node from a tree while maintaining a binary search tree.
template<typename ItemType>
auto BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr)
{
    if(nodePtr->isLeaf()) //if the node is a leaf, case 1
    {
        nodePtr=nullptr;
        return nodePtr;
    }
    else if(nodePtr->getLeftChildPtr()==nullptr||nodePtr->getRightChildPtr()==nullptr)
    {
        if(nodePtr->getLeftChildPtr()!=nullptr)
        {
            std::shared_ptr<BinaryNode<ItemType>> tempPtr = nodePtr;
            nodePtr=nodePtr->getLeftChildPtr(); //child takes place of parent
            tempPtr=nullptr; //deleting that node
        }
        else
        {
            
            std::shared_ptr<BinaryNode<ItemType>> tempPtr = nodePtr;
            nodePtr=nodePtr->getRightChildPtr(); //child takes place of parent
            tempPtr=nullptr; //deleting that node
        }
        return nodePtr;
    }
    else
    {   
        ItemType inorderSuccessor;
        std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), inorderSuccessor)
        nodePtr->setRightChildPtr(tempPtr);
        nodePtr->setItem(newNodeValue)
        return nodePtr;
    }
    
}

// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
template<typename ItemType>
auto BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr, ItemType& inorderSuccessor){}

// Returns a pointer to the node containing the given value,
// or nullptr if not found.
template<typename ItemType>
auto BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target) const{}

 //------------------------------------------------------------
 // Constructor and Destructor Section.
 //------------------------------------------------------------
template<typename ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(){}

template<typename ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem){}

template<typename ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree){}

template<typename ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree(){}

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
template<typename ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const{}

template<typename ItemType>
int BinarySearchTree<ItemType>::getHeight() const{}

template<typename ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const{}

template<typename ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PrecondViolatedExcept){}

template<typename ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData){}

template<typename ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry){}

template<typename ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target){}

template<typename ItemType>
void BinarySearchTree<ItemType>::clear(){}

template<typename ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException){}

template<typename ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const{}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------

template<typename ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const{}

template<typename ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const{}

template<typename ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const{}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------

template<typename ItemType>
BinarySearchTree<ItemType> & BinarySearchTree<ItemType>::operator= (const BinarySearchTree<ItemType>& rightHandSide){}


