/* This is the file that has the implementation of the StackArray class*/

#include <iostream>
#include "StackArray.h"

template<typename DataType>
StackArray<DataType>::StackArray(int maxNumber) : top(-1) //param ctor; creates an empty stack; does not need to allocate because is array implementation
{

	if(maxNumber>0 && maxNumber<=MAX_STACK_SIZE)
	{
		dataItems = new DataType [maxNumber];
		maxSize=maxNumber;
	}
	else if(maxNumber==0)
	{
		cout<<"Cannot initialize a stack of size 0."<<endl;	
	}
	else if(maxNumber>MAX_STACK_SIZE)
	{
		cout<<"Cannot exceed max stack size."<<endl;
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
StackArray<DataType>::StackArray& operator=(const StackArray& other) //operator= overload sets stack to be equivalent to the other stack object and returns reference to modified stack.
{
	clear();
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

	clear();
	
}
	

template<typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{

	if(!isFull())
	{
	
		top++;
		dataItems[top] = newDataItem;
		
	}
	
}

template<typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{

	if(!isEmpty())
	{
		top--;
	}
	
}

template<typename DataType>
void StackArray<DataType>::clear()
{
	top=-1;
	maxSize=0;
	delete [] dataItems;
	dataItems=nullptr;
	
}

template<typename DataType>
bool StackArray<DataType>::isEmpty() const
{

	return top<0;
	
}

template<typename DataType>
bool StackArray<DataType>::isFull() const
{

	if(top==maxSize - 1)
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

if( isEmpty() ) {
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
