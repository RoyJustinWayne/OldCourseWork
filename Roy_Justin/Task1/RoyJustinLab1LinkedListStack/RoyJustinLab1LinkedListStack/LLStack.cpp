#include <iostream>
#include <stdexcept>
using namespace std;

#include "LLStack.h"

//Constructor
template<typename DataType>
LLStack<DataType>::LLStack(int maxNumber)
{
	topItem = NULL;
}

//Decon
template<typename DataType>
LLStack<DataType>::~LLStack()
{
	//Simple clear
	clear();
}

//Push item to stack
template<typename DataType>
void LLStack<DataType>::push(const DataType & newDataItem)
{
	StackNode* create_node = NULL;
	//Check for full, arbitrary implementation. 
	if (!isFull()) 
	{
		//Check status, if empty create node at first location
		if (isEmpty())
		{
			create_node = new StackNode(newDataItem, NULL);
		}
		//Else, we have SOMETHING in the stack, create a data item and put it at top item.
		else 
		{
			create_node = new StackNode(newDataItem, topItem);
		}
		topItem = create_node;
		create_node = NULL;
		NumItems++;
	}
	else 
	{
		//Stack Full
	}
}

template<typename DataType>
DataType LLStack<DataType>::pop()
{
	DataType topItem_data;
	StackNode* TempPtr;

	//Check to make sure stack is not empty.
	if (isEmpty()) 
	{
		//If empty, return 0
		return 0;
	}
	//We are not empty. Continue.
	else 
	{
		//Get the current item, the data, keep a tempPtr to know what is being removed.
		//Use topItem->next to make sure we don't have a dangling list and can't access all elements after we pop.
		TempPtr = topItem;
		topItem_data = topItem->dataItem;
		topItem = topItem->next;

		delete TempPtr;
		TempPtr = NULL;
		
		//Return the popped value
		return topItem_data;
		NumItems--;
	}
}

template<typename DataType>
void LLStack<DataType>::clear()
{
	//Using this for clear and as a simple decon.
	while (!isEmpty()) 
	{
		pop();
	}
}

template<typename DataType>
bool LLStack<DataType>::isEmpty() const
{
	//Does a topItem exist?
	if (topItem == NULL)
	{
		return true;
	}
	//Does a topItem exist?
	else 
	{
		return false;
	}
}

template <typename DataType>
bool LLStack<DataType>::isFull() const
{
	//Arbritrary but for the future if we decided we want to check for this it will be here.
	return false;
}

template<typename DataType>
int LLStack<DataType>::numOfElements()
{
	//This is the easiest method, just keeping track of the number of items.
	cout<< "Items: " << NumItems;
	cout << "\n";
	return NumItems;
	//Additional solution: LLStack.size()

	//You could also go through your list and increment everytime this is called, just takes longer and can be solved easier other ways.
}

template<typename DataType>
void LLStack<DataType>::printElements() const
{
	//Check for empty.
	if (isEmpty())
	{
		cout << "Empty" << endl;
	}
	else
	{
		//We have items, print starting with the topItem and move down (to the next item).
		cout << "Stack: ";
		for (StackNode* TempPtr = topItem; TempPtr != 0; TempPtr = TempPtr->next)
		{
			if (TempPtr == topItem)
			{
				cout << TempPtr->dataItem << "\t";
			}
			else 
			{
				cout << TempPtr->dataItem << "\t";
			}
		}
	}
}

//For the LinkedList Implementation. Need the Node/pointer Structure.
template <typename DataType>
LLStack<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr) 
{
	dataItem = nodeData;
	next = nextPtr;
}

int main() 
{
	LLStack<int> ListStack(20);
	ListStack.push(1);
	ListStack.push(2);
	ListStack.push(3);
	ListStack.push(4);
	ListStack.isEmpty();
	ListStack.numOfElements();
	ListStack.printElements();
	ListStack.pop();
	ListStack.clear();


	cin.get();
}