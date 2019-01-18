#include<iostream>
#include <list>
using namespace std;

//I used an int list. I tried a few things about template use but didn't work out as I hoped.

//template <typename Object>
class ListStack
{
private:
	list<int> List1;
	list<int> List2;
public:
	void push_back(int);
	void pop_front();
};

void ListStack::push_back(int x)
{
	List2.push_back(x);

	while (!List1.empty())
	{
		List2.push_back(List1.front());
		List1.pop_front();
	}
	list<int> TempList;

	TempList = List1;
	List1 = List2;
	List2 = TempList;
}
void ListStack::pop_front()
{
	if (!List1.empty())
	{
		int x = List1.front();
		cout << x << endl;
		List1.pop_front();
	}
}
//Test Main
int main()
{
	ListStack ListStack1;

	ListStack1.push_back(20);
	ListStack1.push_back(50);
	ListStack1.push_back(4);
	ListStack1.push_back(111);

	//Pop everything.
	ListStack1.pop_front();
	ListStack1.pop_front();
	ListStack1.pop_front();
	ListStack1.pop_front();
	
	cin.get();
	return 0;
}


