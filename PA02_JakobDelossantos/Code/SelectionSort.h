//This is the class declaration for the SelectionSort algorithm to be used with the arrays in main.cpp

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H


#include <iostream>
#include <stdexcept>


template <typename ItemType>
class SelectionSort {

    public:
        SelectionSort(ItemType theArray[], int n);
        ~SelectionSort();
        void selectionSort(ItemType theArray[], int n);
        int findIndexOfLargest(const ItemType theArray[], int size);
        unsigned long int getComparisons();
        unsigned long int getSwaps();
        ItemType * getSorted();

    private:
        unsigned long int comparisons=0;
        unsigned long int swaps=0;
        ItemType * sortedArray;

};

#endif 