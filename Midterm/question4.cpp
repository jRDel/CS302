#include <iostream>
/*
NOTE:
I didn't include the linkedlist header because it would then require that I
implement a node.h and a LinkedInterface.h
*/

//4.1
template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   deallocate(headPtr);
   headPtr = nullptr;
   itemCount = 0;
}  // end destructor

template<class ItemType>
LinkedList<ItemType>::deallocate(Node<ItemType> * headPtr)
{
    Node<ItemType> * curr=headPtr;
	
	while(curr!=nullptr) //sets all elements to null ptr (technically deleting)
	{
	
		Node<ItemType> * temp=curr->next;
		
		delete [] delNode;
        curr=nullptr;
    
		curr=temp;
		
	}

delete [] headPtr; //will be set to null in destructor

}

/*
The computational complexity of deallocate is O(n) because you have to go through 
every node (n) and deallocate and assign as a major operation.
*/

//4.2 (Using an external helper method copyChain to implement the copying functionality
template<typename ItemType>
SortedListHasA::SortedListHasA(const SortedListHasA<ItemType>& sList) :listPtr(std::make_unique<LinkedList<ItemType>>())
{
    for (int position = 1; position <= sList.getLength(); position++)
    {
    listPtr->insert(position, sList.getEntry(position));
    }
}

/*The computational complexity of getPosition is O(n), because you have to traverse
the list and at the worst case the position of the element you are trying to find
is n. removeSorted would likely use getPosition to find the element that you 
wish to remove, which takes O(n) on its own, and then to remove it would take another
major operation, giving a worst case complexity of O(n^2).