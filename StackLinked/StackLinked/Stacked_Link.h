#ifndef STACKLINK_H
#define STACKLINK_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class Stack_Linked : public Stack<DataType>
{
public:
	Stack_Linked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
	Stack_Linked(const Stack_Linked& other_stack);
	Stack_Linked& operator=(const Stack_Linked& other_stack);
	~Stack_Linked();

	void push(const DataType& newDataItem) throw (logic_error);
	DataType pop() throw (logic_error);

	void clear();

	bool isEmpty() const;
	bool isFull() const;

	void showStructure() const;

private:
	class StackNode 
	{
	public:
		StackNode(const DataType& nodeData, StackNode* nextPtr);

		DataType dataItem;
		StackNode* next;
	};
	StackNode* top;
};

#endif	