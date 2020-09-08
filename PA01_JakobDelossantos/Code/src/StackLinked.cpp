//This file contains the implementation of the linked-list based stack class, StackLinked.

#include <iostream>
#include "StackLinked.h"

template<typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE)
{}

	

template<typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other);

template<typename DataType>
StackLinked<DataType>::StackLinked& operator=(const StackLinked& other);

template<typename DataType>
StackLinked<DataType>::~StackLinked();

template<typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error);

template<typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error);

template<typename DataType>
void StackLinked<DataType>::clear();

template<typename DataType>
bool StackLinked<DataType>::isEmpty() const;

template<typename DataType>
bool StackLinked<DataType>::isFull() const;

template<typename DataType>
void StackLinked<DataType>::showStructure() const;
