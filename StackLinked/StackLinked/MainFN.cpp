#include<iostream>
#include"Stacked_Link.h"
#include "Stack_Linked.cpp"

using namespace std;

int main()
{
	Stack_Linked<int> stack(8);
	stack.push(3);
	stack.push(2);
	stack.push(1);
	stack.push(9);
	stack.push(7);
	stack.showStructure();
	system("pause");
	return 0;
}