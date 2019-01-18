#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType>
class Queue 
{
public:
	static const int MAX_QUEUE_SIZE = 8;

	virtual ~Queue();

	virtual void enqueue(const DataType& newDataItem) throw (logic_error) = 0;
	virtual DataType dequeue() throw (logic_error) = 0;

	virtual void clear() = 0;

	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;

	virtual void showStructure() const = 0;
};

template <typename DataType>
Queue<DataType>::~Queue()
{
}

#endif	