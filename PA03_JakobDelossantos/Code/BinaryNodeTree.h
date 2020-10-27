#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
    private:
        std::shared_ptr<BinaryNode<ItemType>> rootPtr;
    protected:
        int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
        int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

        auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr);
        virtual std::shared_ptr<BinaryNode<ItemType>> removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool & isSuccessful) const;

        virtual std::shared_ptr<BinaryNode<ItemType>> findNode(std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr, const ItemType& target) const;
        std::shared_ptr<BinaryNode<ItemType>> moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

        auto copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;

        void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

        void preorder(void visit (ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
        void inorder(void visit (ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
        void postorder(void visit (ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
    public:
        BinaryNodeTree();
        BinaryNodeTree(const ItemType & rootItem);
        BinaryNodeTree(const ItemType & rootItem, const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr, const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
        BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>> & tree);
        virtual ~BinaryNodeTree();

        bool isEmpty() const;
        int getHeight() const;
        int getNumberofNodes() const;
        ItemType getRootData() const throw(PrecondViolatedExcept);
        bool add(const ItemType & newData);
        bool remove(const ItemType & data);
        void clear();
        ItemType getEntry(const ItemType & anEntry) const throw(NotFoundException);
        bool contains(const ItemType & anEntry) const;

        void preorderTraverse(void visit(ItemType &)) const;
        void inorderTraverse(void visit(ItemType &)) const;
        void postorderTraverse(void visit(ItemType &)) const;
        BinaryNodeTree<ItemType> & operator = (const BinaryNodeTree<ItemType> & rightHandSide);    
};

#include "BinaryNodeTree.cpp"
#endif