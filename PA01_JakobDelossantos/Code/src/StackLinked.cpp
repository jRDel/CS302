//This file contains the implementation of the linked-list based stack class, StackLinked.

#include <iostream>
#include "StackLinked.h"
#include "Stack.h"

template<typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber) : top(nullptr)
{

DataType dataItem;

	for(int i=0; i<maxNumber; i++)
	{
		StackNode * newNode = new StackNode(dataItem, top);
		
		top=newNode;
	}

}

template<typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{

	for(StackNode * currOther=other.top; currOther!=nullptr; currOther=currOther->next)
	{
		StackNode* newNode = new StackNode(currOther->dataItem, top);
		top=newNode;
	}
	
}

template<typename DataType>
StackLinked<DataType> & StackLinked<DataType>::operator=(const StackLinked& other)
{

	StackNode * curr=top;

	while(curr!=nullptr)
	{
		StackNode * temp=curr->next;
		delete curr;
		curr=temp;
	}
	
	top=nullptr;
	
	for(StackNode * currOther=other.top; currOther!=nullptr; currOther=currOther->next)
	{
		
		StackNode * newNode = new StackNode(currOther->dataItem, top);
		top=newNode;
		
	}
	
return *this;

}
	

template<typename DataType>
StackLinked<DataType>::~StackLinked()
{

	StackNode * curr=top;

	while(curr!=nullptr)
	{
		StackNode * temp=curr->next;
		delete curr;
		curr=temp;
	}
	
	top=nullptr;
	
}

template<typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{

	if(top)
	{
	StackNode * newNode = new StackNode(newDataItem, top);
	top=newNode;
	}
	else
	{
	throw logic_error("Error shouldn't go off because linked-list stack never full.");
	}
}

template<typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{

	if(top==nullptr)
	{
		
		throw logic_error("Cannot pop from an empty stack.");
		
	}
	else
	{
	
		StackNode * delNode=top;
		StackNode * temp=top->next;
		
		delete [] delNode;
		delNode=nullptr;
		
		top=temp;
		
	}
	
}

template<typename DataType>
void StackLinked<DataType>::clear()
{

	StackNode * curr=top;
	
	while(curr!=nullptr) //sets all elements to null ptr
	{
	
		StackNode * temp=curr->next;
		
		curr=nullptr;
		
		curr=temp;
		
	}
	
	top=nullptr;
	
}

template<typename DataType>
bool StackLinked<DataType>::isEmpty() const
{

	return top==nullptr;
	
}

template<typename DataType>
bool StackLinked<DataType>::isFull() const
{

	return false;
	
}

template<typename DataType>
void StackLinked<DataType>::showStructure() const
{

	if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }
}
