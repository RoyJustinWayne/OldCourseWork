#include "QueueLinked.h"
#include <iostream>
using namespace std;

template <typename DataType>
LinkedList_Queue<DataType>::LinkedList_Queue(int maxNumber)
{
	front = NULL;
	back = NULL;
}

template <typename DataType>
LinkedList_Queue<DataType>::LinkedList_Queue(const LinkedList_Queue& other)
{
	front = NULL;
	back = NULL;

	*this = other;
}

template <typename DataType>
LinkedList_Queue<DataType>& LinkedList_Queue<DataType>::operator=(const LinkedList_Queue& other)
{
	QueueNode* other_cursor = other.front;

	if (this == &other) 
	{
		return *this;  
	}
	else 
	{
		clear();
		if (other.isEmpty()) 
		{
			return *this;
		}
		else
		{
			while (other_cursor != NULL)
			{
				enqueue(other_cursor->dataItem);
				other_cursor = other_cursor->next;
			}
		}
	}
	return *this;
}

template <typename DataType>
LinkedList_Queue<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
{
	dataItem = nodeData;
	next = nextPtr;
}

template <typename DataType>
LinkedList_Queue<DataType>::~LinkedList_Queue()
{
	clear();
}

template <typename DataType>
void LinkedList_Queue<DataType>::enqueue(const DataType& newDataItem)
{
	QueueNode* new_node = NULL;

	if (isFull()) 
	{
		cout << "Full" << endl;
	}
	else 
	{
		new_node = new QueueNode(newDataItem, NULL);
		if (isEmpty()) 
		{
			front = new_node;
			back = new_node;
		}
		else 
		{
			back->next = new_node;
			back = new_node;
		}
		new_node = NULL;
	}
}

template <typename DataType>
DataType LinkedList_Queue<DataType>::dequeue()
{
	QueueNode* delete_cursor = NULL;
	DataType data;

	if (isEmpty()) 
	{
		cout << "Empty." << endl;
	}
	else 
	{
		delete_cursor = front;
		data = front->dataItem;

		if (front == back) 
		{
			front = NULL;
			back = NULL;
		}
		else 
		{
			front = front->next;
		}
		
		delete delete_cursor;
		delete_cursor = NULL;

		return data;
	}
}

template <typename DataType>
void LinkedList_Queue<DataType>::clear()
{
	while (!isEmpty()) 
	{
		dequeue();
	}
}

template <typename DataType>
bool LinkedList_Queue<DataType>::isEmpty() const
{
	//returns true or false
	return (front == NULL);
}

template <typename DataType>
bool LinkedList_Queue<DataType>::isFull() const
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
DataType LinkedList_Queue<DataType>::getRear()
{
	QueueNode* delete_cursor = NULL;
	QueueNode* prev = NULL;
	DataType data;
	
	if (isEmpty()) 
	{
		cout << "Empty." << endl;
	}
	else
	{
		delete_cursor = back;
		data = back->dataItem;

		if (front == back) 
		{
			front = NULL;
			back = NULL;
		}
		else 
		{
			prev = front;
			while (prev->next != back)
			{
				prev = prev->next;
			}
			back = prev;
			back->next = NULL;
		}
		delete delete_cursor;
		delete_cursor = NULL;

		return data;
	}
}

template <typename DataType>
int LinkedList_Queue<DataType>::getLength() const
{
	QueueNode* cursor = NULL;
	int length = 0;

	for (length = 0, cursor = front; cursor != NULL;
		++length, cursor = cursor->next) 
	{
	}
	return length;
}

template <typename DataType>
void LinkedList_Queue<DataType>::showStructure() const
{
	QueueNode* cursor; 

	if (isEmpty())
		cout << "Empty" << endl;
	else
	{
		cout << "Front\t";
		for (cursor = front; cursor != NULL; cursor = cursor->next)
		{
			if (cursor == front)
			{
				cout << '[' << cursor->dataItem << "] ";
			}
			else
			{
				cout << cursor->dataItem << " ";
			}
		}
		cout << "\tRear" << endl;
	}
}




