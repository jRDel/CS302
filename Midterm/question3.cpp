#include <iostream>

template <class ItemType>
void mergeSort(ItemType theArray[], int first, int last)
{
    if (first < last)
    {
        int mid = first + (last-first)/2;
        mergeSort(theArray,first,mid); // insert missing variable
        mergeSort(theArray,mid+1,last);   // insert missing variable 
        merge(theArray,first,mid,last);
    } // end if
} // end mergeSort

template <class ItemType>
void merge(ItemType theArray[], int first, int mid, int last)
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
            swaps++;
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
        swaps++;
    }

    while(first2<=last2)
    {
        tempArray[index] = theArray[first2];
        first2++;
        index++;
        swaps++;
    }

    for(index=first; index<=last; index++)
    {
        theArray[index] = tempArray[index];
        sortedArray[index] = tempArray[index];
    }

}


/*
If the array has to be sorted has total size n, the time complexity for the 
function is O(nlogn). This is derived from the comparisons, number of moves,
how deep recursion goes, and how many calls to merge take place. Merging the
total number of items compares at most n-1 times. To move every element from 
original to temp array and then back both take n moves. Therefore, each merge
takes 3 x n-1 operations.
One call to mergeSort will call itself twice, and with each mergeSort call the array
is halved, signifying a logn (base 2). The number of levels deep depends on if n
is a power of 2 or not. If it is, it will go logn levels deep, and if it isn't
it will go 1+ logn levels deep.
merge is called in the original mergesort once, and going back to above, 
merge takes 3 x n-1 operations (comparisons/moves). Putting these ideas together,
you can see that each level of recursion on its own requires O(n) and when combined
with the calls and halves of mergeSort, gives the total time complexity of
O(nlogn).
*/

/*The worst case complexity of mergeSort is nlogn, as it will always be halving arrays
and go through every element to compare or move (n). The halving is (logn). As for
quicksort, the worst case complexity is O(n^2). This happens when you choose
a pivot at the highest or lowest, where it partitions into n groups, which then
are gone through n times, therefore you get O(n^2).
*/