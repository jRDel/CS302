#ifndef BINARY_NODE_
#define BINARY_NODE_
#include <memory>

template<class ItemType>
class BinaryNode
{
    private:
        ItemType item;
        std::shared_ptr<BinaryNode<ItemType>> leftChildPtr;
        std::shared_ptr<BinaryNode<ItemType>> rightChildPtr;

    public:
        BinaryNode();
        BinaryNode(const ItemType & anItem);
        BinaryNode(const ItemType & anItem, std::shared_ptr<BinaryNode<ItemType>> leftPtr, std::shared_ptr<BinaryNode<ItemType>> rightPtr);
        void setItem(const ItemType & anItem);
        ItemType getItem() const;

        bool isLeaf() const;

        auto getLeftChildPtr() const;
        auto getRightChildPtr() const;

        void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
        void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);

};

#include "BinaryNode.cpp"
#endif