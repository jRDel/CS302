//This is the implementation of the BinaryNode
#include <iostream>
#include "BinaryNode.h"

template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(){
    item=null; //signals a empty node
}

template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType & anItem){
    item=anItem;
}

template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType & anItem, std::shared_ptr<BinaryNode<ItemType>> leftPtr, std::shared_ptr<BinaryNode<ItemType>> rightPtr){  
    item=anItem;
    leftChildPtr=leftPtr;
    rightChildPtr=rightPtr;
}

template<typename ItemType>
void BinaryNode<ItemType>::setItem(const ItemType & anItem){
    item=anItem;
}

template<typename ItemType>
ItemType BinaryNode<ItemType>::getItem() const{
    return item;
}

template<typename ItemType>
bool BinaryNode<ItemType>::isLeaf() const{
    if(leftChildptr==nullptr&&rightChildPtr==nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

template<typename ItemType>
auto BinaryNode<ItemType>::getLeftChildPtr() const{
    if(leftChildPtr==nullptr)
    {
        return nullptr;
    }
    else
    {
        return leftChildPtr;
    }
    
}

template<typename ItemType>
auto BinaryNode<ItemType>::getRightChildPtr() const{
    if(rightChildPtr==nullptr)
    {
        return nullptr;
    }
    else
    {
        return rightChildPtr;
    }
    
}

template<typename ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr){
    leftChildPtr=leftPtr;
}

template<typename ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr){
    rightChildPtr=rightPtr;
}