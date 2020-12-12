#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <algorithm>
using namespace std;
//1.1
/*
The relation between heaps and binary search trees is mainly their ordering of elements. In a heap, the higher you go up on its levels (for a max heap) the higher the values will be,
and the opposite for min heaps (the higher level, the smaller the value). In a BST, elements are ordered where the left child or subtree of a root is less than the root value and the
elements in the right child or right subtree of a root are greater than the root value.
*/

//1.2 - 1.5
int main(){
    std::vector<int> v1;
    int mean = 0;
    v1.reserve(100);
    
    srand(time(0)); //seeding the rand() function, for random numbers

    for(int i=0; i<100; i++) //putting in 100 different integers randomly
    {
       int value=rand() % 1000; //value to be inserted
        v1.push_back(value);
        mean=mean+value; //for getting the mean
    }
    cout<<"Heap before sort and inserting mean: "<<endl;
    for(int i=0; i<100; i++)
    {
        cout<<v1[i]<<"\t";
    }

    make_heap(v1.begin(), v1.end()); //making the 100 random integers a heap
    std::cout<<"Max element of heap: "<<v1.front()<<endl; //getting the maximum element of the heap

    mean = mean/100; //getting the true mean.

    v1.push_back(mean); //push the mean onto heap
    push_heap(v1.begin(), v1.end()); //reorder elements to maintain heap structure


    pop_heap(v1.begin(), v1.end()); //delete the maximum element of the heap
    v1.pop_back();

    sort_heap(v1.begin(), v1.end()); //sorting the heap
    cout<<"Heap after sort and inserting mean: "<<endl;
    for(int i=0; i<100; i++)
    {
        cout<<v1[i]<<"\t";
    }
return 0;

}
//Commenting on the big-o for each major step...

/*
For inserting into a heap, first the element is inserted then the heap has to go through the process of reordering the elements to maintain the heap property. This means
how much the element has to rise in a heap in order to satisfy the heap property. At worst, this can be O(logn). For sorting, the STL implementation of sort or sort_heap is
O(nlogn).
*/




