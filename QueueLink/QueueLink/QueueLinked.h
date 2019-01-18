#pragma once
#include <stdexcept>
#include <iostream>

using namespace std;

#include "Queue.h"

template <typename DataType>
class LinkedList_Queue : public Queue<DataType> {
public:
	LinkedList_Queue(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE);
	LinkedList_Queue(const LinkedList_Queue& other);
	LinkedList_Queue& operator=(const LinkedList_Queue& other);
	~LinkedList_Queue();

	void enqueue(const DataType& newDataItem) throw (logic_error);
	DataType dequeue() throw (logic_error);

	void clear();

	bool isEmpty() const;
	bool isFull() const;

	DataType getRear() throw (logic_error);
	int getLength() const;

	void showStructure() const;

private:
	class QueueNode {
	public:
		QueueNode(const DataType& nodeData, QueueNode* nextPtr);

		DataType dataItem;
		QueueNode* next;
	};

	QueueNode* front;
	QueueNode* back;
};