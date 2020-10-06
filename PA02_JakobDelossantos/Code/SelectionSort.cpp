//This is the class declaration for the SelectionSort algorithm to be used with the arrays in main.cpp

#include <iostream>
#include "SelectionSort.h"
#include <chrono>
#include <ctime>

using namespace std::chrono;

template<typename ItemType>
SelectionSort<ItemType>::SelectionSort(ItemType theArray[], int n)
{
    sortedArray = new ItemType[n];
    for(int i=0; i<n;i++)
    {
        sortedArray[i]=theArray[i];
    }

}

template<typename ItemType>
SelectionSort<ItemType>::~SelectionSort()
{
    delete [] sortedArray;
}

template<typename ItemType>
void SelectionSort<ItemType>::selectionSort(ItemType theArray[], int n)
{
    swaps=0;
    comparisons=0;
    for(int last=n-1; last>=1; last--)
    {
        int largest = findIndexOfLargest(sortedArray, last+1);
        std::swap(sortedArray[largest], sortedArray[last]);
        swaps++;
    }

}
template<typename ItemType>
int SelectionSort<ItemType>::findIndexOfLargest(const ItemType theArray[], int size)
{
    int indexSoFar = 0;
    for(int currentIndex = 1; currentIndex < size; currentIndex++)
    {
        if(sortedArray[currentIndex] > sortedArray[indexSoFar])
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

template<typename ItemType>
ItemType * SelectionSort<ItemType>::getSorted()
{
    return sortedArray;
}

