/* This is the file that has the implementation of the StackArray class*/

#include <iostream>
#include "StackArray.h"
#include "Stack.h"

template<typename DataType>
StackArray<DataType>::StackArray(int maxNumber) : top(-1) //param ctor; creates an empty stack; does not need to allocate because is array implementation
{

	if(maxNumber>0)
	{
		dataItems = new DataType [maxNumber];
		maxSize=maxNumber;
	}
	else if(maxNumber==0)
	{
		cout<<"Cannot initialize a stack of size 0."<<endl;	
	}
	
	
}

template<typename DataType>
StackArray<DataType>::StackArray(const StackArray& other) //copy ctor; initializes the stack to be equivalent to the other stack object passed as parameter
{

	dataItems = new DataType [other.maxSize];
	maxSize=other.maxSize;
	top=other.top;
	
	for(int i=top; i>=0; i--)
	{
		dataItems[i]=other.dataItems[i];
	}
	
}

template<typename DataType>
StackArray<DataType> & StackArray<DataType>::operator=(const StackArray& other) //operator= overload sets stack to be equivalent to the other stack object and returns reference to modified stack.
{
	
	top=other.top;
	maxSize=other.maxSize;
	dataItems = new DataType [other.maxSize];
	
	for(int i=top; i>=0; i--)
	{
		dataItems[i]=other.dataItems[i];
	}

return *this;

}

template<typename DataType>
StackArray<DataType>::~StackArray()
{

	top= 0;
	//maxSize=0;
	delete [] dataItems;
	dataItems=nullptr;
	
}
	

template<typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{

	if(!isFull())
	{
	
		top++;
		dataItems[top] = newDataItem;
		
	}
	
	else
	{
	
		throw logic_error("Cannot push onto stack; Stack is full.");
		
	}
}

template<typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{

	if(!isEmpty())
	{
		
		return dataItems[top--];
	}
	else
	{
	
		throw logic_error("Cannot pop from an empty stack.");
		
	}
	
}

template<typename DataType>
void StackArray<DataType>::clear()
{
	
	top=-1;
	
}

template<typename DataType>
bool StackArray<DataType>::isEmpty() const
{
	if (top==-1)
	{
		
	return true;
	
	}
	else
	{
	
	return false;
	
	}
	
	
}

template<typename DataType>
bool StackArray<DataType>::isFull() const
{

	if(top==(maxSize-1))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
		

template<typename DataType>
void StackArray<DataType>::showStructure() const
{

if( isEmpty() ) { //The problem is here, if you clear the function and try adding again, it won't show up!!!!
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
    
}
