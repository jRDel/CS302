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
{
    int count = 1;
    if(subTreePtr->getLeftChildPtr() != NULL)
    {
        count += getNumberOfNodesHelper(subTreePtr->getLeftChildPtr());
    }
    if(subTreePtr->getRightChildPtr() != NULL)
    {
        count += getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
    }
    return count;
} //done

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
{
    if(subTreePtr == nullptr)
    {
        isSuccessful=false;
    }
    else if(subTreePtr ->getItem() == target)
    {
        std::shared_ptr<BinaryNode<ItemType>> tempPtr;
        tempPtr=moveValuesUpTree(subTreePtr); //returns the spot that should be deleted(rightmost node deepest)
        tempPtr=nullptr;
        isSuccessful=true;
    }
    else if(subTreePtr->getItem() > target)
    {
        std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful)
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
} //done

template<typename ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
    std::shared_ptr<BinaryNode<ItemType>> tempPtr=rootPtr;
    while(tempPtr->getRightChildPtr()!=nullptr)
    {
        tempPtr->setRightChildPtr(tempPtr->getRightChildPtr());
    }
    subTreePtr->setItem(tempPtr->getItem());
    return tempPtr; //deepest rightmost node
}

template<typename ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr, const ItemType& target) const //not done
{
    if(oldTreeRootPtr==nullptr) //empty tree or just not found
    {
        return nullptr;
    }
    else if(oldTreeRootPtr->getItem()==target) //found in root
    {
        return oldTreeRootPtr;
    }
    else if(oldTreeRootPtr->getItem()>target) //search the left subtree if the current position is greater than target
    {
        return findNode(oldTreeRootPtr->getLeftChildPtr(), target);
    }
    else
    {
        return findNode(oldTreeRootPtr->getRightChildPtr(), target);
    }    
}
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
{}  //default ctor done

template<typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType & rootItem) : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{}  //makes a node tree with a binary node root with left and right child as nullptr done


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
    clear();
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
{
    getNumberOfNodesHelper(rootPtr);
} //done

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
{
    bool isSuccessful=false;
    rootPtr=removeValue(rootPtr, data, isSuccessful);
    return isSuccessful;
} //done

template<typename ItemType>
void BinaryNodeTree<ItemType>::clear()
{
    destroyTree(rootPtr);
} //done

template<typename ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType & anEntry) const throw(NotFoundException)
{
    std::shared_ptr<BinaryNode<ItemType>> tempPtr=findNode(rootPtr, anEntry);
    if(tempPtr==nullptr)
    {
        throw(NotFoundException);
    }
    else
    {
        return tempPtr->getItem();
    }
    
} //done

template<typename ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType & anEntry) const
{
    std::shared_ptr<BinaryNode<ItemType>> tempPtr=findNode(rootPtr, anEntry);
    if(tempPtr==nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
    
} //done

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
    clear(); //destroy current tree
    rootPtr=rightHandSide.rootPtr;
    rootPtr->setItem(rightHandSide->getItem());
    std::shared_ptr<BinaryNode<ItemType>> leftTreePtr = rightHandSide->getLeftChildPtr();
    std::shared_ptr<BinaryNode<ItemType>> rightTreePtr = rightHandSide->getRightChildPtr();
    copyTree(leftTreePtr->rootPtr);
    copyTree(rightTreePtr->rootPtr);
    
    return *this;
} //NOT done