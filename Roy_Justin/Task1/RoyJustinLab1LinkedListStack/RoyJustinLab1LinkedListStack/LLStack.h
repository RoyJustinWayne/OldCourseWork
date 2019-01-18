#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType>
class LLStack  {
public:

	LLStack(int maxNumber = 20);
	~LLStack();

	void push(const DataType& newDataItem);
	DataType pop();

	void clear();
	bool isEmpty() const;
	bool isFull() const;
	int numOfElements();

	void printElements() const;

	int NumItems = 0;

private:

	class StackNode 
	{
	public:
		StackNode(const DataType& nodeData, StackNode* nextPtr);
		DataType dataItem;
		StackNode* next;
	};
	StackNode* topItem;
};

