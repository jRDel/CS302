#include <iostream>

#include "Stack.h"
#include "StackLinked.h"

template<typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
    bool go=true;
	if(go)
	{
	StackNode * newNode = new StackNode(newDataItem, top);
	top=newNode;
	}
	else
	{
	throw logic_error("Error shouldn't go off because linked-list stack never full.");
	}
}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{

	if(top==nullptr) //signifies the stack is empty; could also use isEmpty()
	{
		
		throw logic_error("Cannot pop from an empty stack.");
		
	}
	else
	{
	
		StackNode * delNode=top;
		StackNode * temp=top->next;
		
		DataType tempItem=delNode->dataItem;
		
		delete [] delNode;
		delNode=nullptr;
		
		top=temp;
		return tempItem;
		
	}
	
}

bool delimitersOk ( const string &expression )
{
    StackLinked<char> stackOne;
    char check1;
    char check2;

    for(unsigned int i=0; i<expression.length(); i++)
    {
        if(expression[i]=='[' || expression[i]=='(') //if its an opening you can push onto the stack
        {

            stackOne.push(expression[i]);
        }
        else if(expression[i]==']' || expression[i]==')') //if its a closing you can pop off the stack because that means matched
        {
            stackOne.pop();
        }
        else{
            //do nothing
        }
    }

    if(stackOne.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
    

}



