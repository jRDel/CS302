//This is the class declaration for the SelectionSort algorithm to be used with the arrays in main.cpp

#include <iostream>
#include "SelectionSort.h"
#include <chrono>
#include <ctime>

using namespace std::chrono;

template<typename ItemType>
SelectionSort<ItemType>::SelectionSort(ItemType theArray[], int n)
{
    //selectionSort(theArray, n);
}

template<typename ItemType>
void SelectionSort<ItemType>::selectionSort(ItemType theArray[], int n)
{
    for(int last=n-1; last>=1; last--)
    {
        int largest = findIndexOfLargest(theArray, last+1);
        std::swap(theArray[largest], theArray[last]);
        swaps++;
    }
}
template<typename ItemType>
int SelectionSort<ItemType>::findIndexOfLargest(const ItemType theArray[], int size)
{
    int indexSoFar = 0;
    for(int currentIndex = 1; currentIndex < size; currentIndex++)
    {
        if(theArray[currentIndex] > theArray[indexSoFar])
        {
            indexSoFar = currentIndex;
        }
        comparisons++;
    }

    return indexSoFar;
}

template<typename ItemType>
unsigned long int SelectionSort<ItemType>::getComparisons()
{
    return comparisons;
}

template<typename ItemType>
unsigned long int SelectionSort<ItemType>::getSwaps()
{
    return swaps;
}

/*template<typename ItemType>
std::chrono::time_point<std::chrono::system_clock> SelectionSort<ItemType>::getTime()
{
    return time;    
}*/