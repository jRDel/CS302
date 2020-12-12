#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <algorithm>
using namespace std;

//2 (there will be errors because the header is not included so won't compile, but implementation should be right)
/*
Method balanced add recursively adds a new node to the tree in a left-right fashion to ensure that the tree is balanced. The recursive is found where it traverses down each tree 
until it finds where it needs to balance, and then sets the right child equal to the right or left ptr to link the tree again
*/
template<typename ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> leftPtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
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
                leftPtr = balancedAdd(rightPtr, newNodePtr);
                subTreePtr->setLeftChildPtr(leftPtr);
            }
            return subTreePtr;
    }

}


/*
Method copyTree is called by the copy constructor to copy the tree rooted at oldTreeRootPtr and then return a pointer to the root of the copy. It is used to ensure a "deep-copy" of the tree.
*/
template<typename ItemType>
auto BinaryNodeTree<ItemType>::copyTree(std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
    std::shared_ptr<BinaryNode<ItemType>> newTreePtr;

    if(oldTreeRootPtr != nullptr) //preorder traversal
    {
        newTreePtr = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(), nullptr, nullptr);
        newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(oldTreeRootPTr->getRightChildPtr()));
    }
    return newTreePtr;

}