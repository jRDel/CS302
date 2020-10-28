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
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNode)
{
    if(subTreePtr==nullptr)
    {
        return newNode;
    }
    else if (subTreePtr->getItem() > newNode->getItem())
    {
        std::shared_ptr<BinaryNode<ItemType>> tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNode);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        std::shared_ptr<BinaryNode<ItemType>> tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNode);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}

// Removes the given target value from the tree while maintaining a
// binary search tree.
template<typename ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,const ItemType target, bool & isSuccessful)
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
        std::shared_ptr<BinaryNode<ItemType>> tempPtr=removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        std::shared_ptr<BinaryNode<ItemType>> tempPtr=removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
    
}

// Removes a given node from a tree while maintaining a binary search tree.
template<typename ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr)
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
        std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), inorderSuccessor);
        nodePtr->setRightChildPtr(tempPtr);
        nodePtr->setItem(inorderSuccessor);
        return nodePtr;
    }
    
}

// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
template<typename ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr, ItemType& inorderSuccessor)
{
    if(subTreePtr->getLeftChildPtr() == nullptr)
    {
        inorderSuccessor = subTreePtr->getItem(); //this is the node you want; no left child but it might have a right subtreeß
        return removeNode(subTreePtr);
    }
    else
    {
        std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor);
        subTreePtr->setLeftChildPtr(tempPtr);
        return subTreePtr;
    }
    
}
/*
// Returns a pointer to the node containing the given value,
// or nullptr if not found.
template<typename ItemType>
auto BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target) const{}
*/
 //------------------------------------------------------------
 // Constructor and Destructor Section.
 //------------------------------------------------------------
template<typename ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{}

template<typename ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{}

template<typename ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{
    rootPtr = this->copyTree(tree.rootPtr);
}

template<typename ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
    this->destroyTree(rootPtr);
    this->rootPtr.reset();
}
/*
//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
template<typename ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const{}
*/
template<typename ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
     int height=BinaryNodeTree<ItemType>::getHeightHelper(rootPtr);
     return height;
}

/*template<typename ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
    int count= getNumberOfNodesHelper(rootPtr);
    return count;
}*/

template<typename ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PrecondViolatedExcept)
{
    if(rootPtr==nullptr)
    {
        throw;
    }
    else
    {
        return rootPtr->getItem();
    }
}

template<typename ItemType>
bool BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
{
    rootPtr->setItem(newData);
    return true;
}

template<typename ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{
    std::shared_ptr<BinaryNode<ItemType>> newNodePtr = std::make_shared<BinaryNode<ItemType>>(newEntry);
   
    rootPtr = placeNode(rootPtr, newNodePtr);
    return true;
}

template<typename ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target)
{
    bool isSuccessful = false;
    rootPtr = removeValue(rootPtr, target, isSuccessful);
    return isSuccessful;
}

/*template<typename ItemType>
void BinarySearchTree<ItemType>::clear(){}

template<typename ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException){}
*/
template<typename ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{
    std::shared_ptr<BinaryNode<ItemType>> tempPtr = BinaryNodeTree<ItemType>::findNode(rootPtr, anEntry);
    if(tempPtr==nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------

template<typename ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{

    BinaryNodeTree<ItemType>::preorder(visit, rootPtr);
}

template<typename ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
    BinaryNodeTree<ItemType>::inorder(visit, rootPtr);
}

template<typename ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
    BinaryNodeTree<ItemType>::postorder(visit, rootPtr);
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
/*
template<typename ItemType>
BinarySearchTree<ItemType> & BinarySearchTree<ItemType>::operator= (const BinarySearchTree<ItemType>& rightHandSide){}*/


