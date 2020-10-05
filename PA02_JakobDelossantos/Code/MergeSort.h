//This is the class declaration for the MergeSort algorithm to be used with the arrays in main.cpp
#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <stdexcept>


template <typename ItemType>
class MergeSort {
    public:
        MergeSort(ItemType theArray[], int first, int last);
        void mergeSort(ItemType theArray[], int first, int last);
        void merge(ItemType theArray[], int first, int mid, int last);
        unsigned long int getComparisons();
        unsigned long int getSwaps();
    private:
        unsigned long int comparisons=0;
        unsigned long int swaps=0;
};

#endif 