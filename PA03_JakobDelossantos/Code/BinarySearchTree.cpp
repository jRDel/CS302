//This source file includes the class implementations of the binarysearchtree
#include <iostream>
#include <stdexcept>
#include "BinarySearchTree.h"
#include "BinaryNodeTree.h"

//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
// Places a given new node at its proper position in this binary
// search tree.
template<typename ItemType>
auto BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNode){}

// Removes the given target value from the tree while maintaining a
// binary search tree.
template<typename ItemType>
auto BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,const ItemType target, bool & isSuccessful) override{}

// Removes a given node from a tree while maintaining a binary search tree.
template<typename ItemType>
auto BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr){}

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
ItemType BinarySearchTree::getEntry(const ItemType& anEntry) const throw(NotFoundException){}

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


