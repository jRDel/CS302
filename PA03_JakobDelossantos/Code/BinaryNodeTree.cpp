//This is the implementation of BinaryNodeTree.
#include <iostream>
#include "BinaryNodeTree.h"
#include "BinaryNode.h"

template<typename ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{

    if(subTreePtr == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
    }

} //done

template<typename ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{} //NOT done

template<typename ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    if(subTreePtr == nullptr)
    {
        return newNodePtr;
    }
    else
    {
        auto leftPtr = subTreePtr->getLeftChildPtr();
        auto rightPtr = subTreePtr->getRightChildPtr();

        if(getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
        {
            rightPtr = balancedAdd(rightPtr, newNodePtr);
            subTreePtr->setRightChildPtr(rightPtr);
        }
        else
        {
            leftPtr = balancedAdd(leftPtr, newNodePtr);
            subTreePtr->setLeftChild(leftPtr);
        }
        return subTreePtr;
    }
} //done

template<typename ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool & isSuccessful) const
{} //NOT done
 
template<typename ItemType>
auto BinaryNodeTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
    std::shared_ptr<BinaryNode<ItemType>> newTreePtr;

    // Copy tree nodes during a preorder traversal
        if (oldTreeRootPtr != nullptr)
        {
            // Copy node
            newTreePtr = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(), nullptr, nullptr);
            newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
            newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
        } // end if
        // Else tree is empty (newTreePtr is nullptr)
    return newTreePtr;
} //done

template<typename ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
    if(subTreePtr != nullptr)
    {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        subTreePtr.reset(); //decrement reference count to node
    } //end if
} //done

template<typename ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit (ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
    if(treePtr != nullptr)
    {
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
    }
} //done

template<typename ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit (ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
    if(treePtr != nullptr)
    {
        inorder(visit, treePtr->getLeftChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        inorder(visit, treePtr->getRightChildPtr());
    }
} //done

template<typename ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit (ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
    if(treePtr != nullptr)
    {
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
    }
} //done

template<typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{}  //default ctor

template<typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType & rootItem) : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{}  //makes a node tree with a binary node root with left and right child as nullptr


template<typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType & rootItem, const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr, const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
: rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr)))
{} //done

template<typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>> & tree)
{
    rootPtr = copyTree(treePtr.rootPtr);
} //done

template<typename ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
    destroyTree(rootPtr);
} //done

template<typename ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
    if (rootPtr==nullptr){
        return true;
    }
    else{
        return false;
    }
} //done

template<typename ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
     return getHeightHelper(rootPtr);
} //done

template<typename ItemType>
int BinaryNodeTree<ItemType>::getNumberofNodes() const
{} //NOT done

template<typename ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw(PrecondViolatedExcept)
{
    if(rootPtr==nullptr)
    {
        throw(PrecondViolatedExcept);
    }
    else
    {
        return rootPtr->item;
    }
} //done

template<typename ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType & newData)
{
    auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);
    return true;
} //done

template<typename ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType & data)
{} //NOT done

template<typename ItemType>
void BinaryNodeTree<ItemType>::clear()
{} //NOT done

template<typename ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType & anEntry) const throw(NotFoundException)
{} //NOT done

template<typename ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType & anEntry) const
{} //NOT done

template<typename ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType &)) const
{
    preorder(visit, rootPtr);
} //done


template<typename ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType &)) const
{
    inorder(visit, rootPtr);
}//done

template<typename ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType &)) const
{
    postorder(visit, rootPtr)
} //done

template<typename ItemType>
BinaryNodeTree<ItemType> & BinaryNodeTree<ItemType> :: operator = (const BinaryNodeTree<ItemType> & rightHandSide)
{
    //this will contain the implementation
} //NOT done