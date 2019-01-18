#include<iostream>
#include"QueueLinked.h"
#include "QueueLinkedList.cpp"
using namespace std;

int main()
{
	LinkedList_Queue<int> queue(8);
	queue.enqueue(3);
	queue.enqueue(2);
	queue.enqueue(1);
	queue.enqueue(9);
	queue.enqueue(7);
	queue.showStructure();
	system("pause");
	return 0;
}