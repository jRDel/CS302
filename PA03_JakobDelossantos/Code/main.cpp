//This is the main driver for Project 3 on Binary Search Trees. - Jakob Delossantos

#include <iostream>
#include <random>
#include "BinarySearchTree.cpp"
#include "BinaryNodeTree.cpp"
#include "BinaryNode.cpp"
#include "BinaryTreeInterface.h"


using namespace std;

template<typename ItemType>
void visit (ItemType & number)
{
    cout<<number<<"\t";
}

int main()
{

srand((unsigned)time(0)); //seed the rand function
BinarySearchTree<int> tree1;

int addNumber=0;
for(int i=0; i<100; i++)
{
    addNumber= rand() % 200+1; //range 0-200
    if(tree1.contains(addNumber)==false)
    {
        tree1.add(addNumber);
    }
    else
    {
        i--; //try again with different number
    }
}


int height=tree1.getHeight();
cout<<"The height of the tree is: "<<height<<endl;

cout<<"---------INORDER---------"<<endl;
tree1.inorderTraverse(visit);

cout<<"---------PREORDER---------"<<endl;
tree1.preorderTraverse(visit);

cout<<"---------POSTORDER---------"<<endl;
tree1.postorderTraverse(visit);

cout<<"---------END TESTING---------"<<endl;

return 0;

}

