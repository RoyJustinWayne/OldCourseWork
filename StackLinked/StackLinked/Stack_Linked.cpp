#include <iostream>
#include <stdexcept>

using namespace std;
#include "Stacked_Link.h"

template <typename DataType>
Stack_Linked<DataType>::Stack_Linked(int maxNumber)
{
	top = NULL;
}

template <typename DataType>
Stack_Linked<DataType>::Stack_Linked(const Stack_Linked& other_stack)
{
	top = NULL;

	StackNode* other_cursor = other_stack.top;
	StackNode* previous_node = NULL;
	StackNode* new_node = NULL;

	*this = other_stack;
}

template <typename DataType>
Stack_Linked<DataType>& Stack_Linked<DataType>::operator=(const Stack_Linked& other_stack)
{
	StackNode* other_cursor = other_stack.top;
	StackNode* previous_node = NULL;
	StackNode* new_node = NULL;

	if (this == &other_stack)
	{
		return *this;
	}

	if (other_stack.isEmpty())
	{
		throw (logic_error)
	}

	else 
	{
		top = new StackNode(other_stack.top->dataItem, NULL);

		previous_node = top;

		while (other_cursor->next != NULL)
		{
			other_cursor = other_cursor->next;
			new_node = new StackNode(other_cursor->dataItem, NULL);

			previous_node->next = new_node;
			previous_node = previous_node->next;
		}
	}
	return *this;
}


//Deconstruct
template <typename DataType>
Stack_Linked<DataType>::~Stack_Linked()
{
	clear();
}

//For push function
template <typename DataType>
Stack_Linked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr)
{
	dataItem = nodeData;
	next = nextPtr;
}

template <typename DataType>
void Stack_Linked<DataType>::push(const DataType& newDataItem)
throw (logic_error) 
{
	StackNode* new_node = NULL;

	if (!isFull())
	{
		if (isEmpty()) 
		{
			new_node = new StackNode(newDataItem, NULL);
		}
		else 
		{
			new_node = new StackNode(newDataItem, top);
		}
		top = new_node;
		new_node = NULL;
	}
	else 
	{
		throw("StackFull");
	}
}

template <typename DataType>
DataType Stack_Linked<DataType>::pop()
{
	DataType top_data;
	StackNode* temp;

	if (isEmpty()) 
	{
		return 0;
		throw("Empty");
	}
	else 
	{
		temp = top;
		top_data = top->dataItem;

		top = top->next; 

		delete temp;
		temp = NULL;

		return top_data;
	}
}

template <typename DataType>
void Stack_Linked<DataType>::clear()
{
	while (!isEmpty())
	{
		pop();
	}
}

template <typename DataType>
bool Stack_Linked<DataType>::isEmpty() const
{
	if (top == NULL) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

template <typename DataType>
bool Stack_Linked<DataType>::isFull() const
{
	if (isFull())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename DataType>
void Stack_Linked<DataType>::showStructure() const
{
	if (isEmpty())
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << "Top\t";
		for (StackNode* temp = top; temp != 0; temp = temp->next) 
		{
			if (temp == top)
			{
				cout << "" << temp->dataItem << "\t";
			}
			else 
			{
				cout << temp->dataItem << "\t";
			}
		}
		cout << "Bottom" << endl;
	}
}