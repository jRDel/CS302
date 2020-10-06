//This cpp file contains the class implementation of the MergeSort algorithm

#include <iostream>
#include "MergeSort.h"

template<typename ItemType>
MergeSort<ItemType>::MergeSort(ItemType theArray[], int first, int last)
{
    sortedArray = new ItemType[last];
    for(int i=0;i<last;i++)
    {
        sortedArray[i]=theArray[i];
    }
    originalSize=last;
}

template<typename ItemType>
MergeSort<ItemType>::~MergeSort()
{
    delete [] sortedArray;
}

template<typename ItemType>
void MergeSort<ItemType>::mergeSort(ItemType theArray[], int first, int last)
{
    
    if(first<last)
    {
        int mid = first + (last-first)/2;
        mergeSort(theArray, first, mid);
        mergeSort(theArray, mid+1, last);
        merge(theArray, first, mid, last);
    }
    
}

template<typename ItemType>
void MergeSort<ItemType>::merge(ItemType theArray[], int first, int mid, int last)
{
    int first1=first;
    int last1=mid;
    int first2=mid+1;
    int last2=last;

    ItemType tempArray[last];

    int index=first1;
    while((first1<=last1)&&(first2<=last2))
    {
        if(theArray[first1]<=theArray[first2])
        {
            tempArray[index] = theArray[first1];
            first1++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            first2++;
            swaps++; 
        }
        index++;
        comparisons++;
    }

    while(first1<=last1)
    {
        tempArray[index]=theArray[first1];
        first1++;
        index++;
    }

    while(first2<=last2)
    {
        tempArray[index] = theArray[first2];
        first2++;
        index++;
    }

    for(index=first; index<=last; index++)
    {
        theArray[index] = tempArray[index];
        sortedArray[index] = tempArray[index];
    }

}

template<typename ItemType>
unsigned long int MergeSort<ItemType>::getComparisons()
{
    return comparisons;
}

template<typename ItemType>
unsigned long int MergeSort<ItemType>::getSwaps()
{
    return swaps;
}

template<typename ItemType>
ItemType * MergeSort<ItemType>::getSorted()
{
    return sortedArray;
}