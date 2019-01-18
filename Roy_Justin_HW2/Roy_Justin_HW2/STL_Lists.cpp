#include <iostream>
#include <list>
#include <iterator>
using namespace std;
//I wanted to make an exception handler for this one. I couldn't get it working properly. If index is out of range it crashes.
int main()
{
	list<int> P = { 10 , 11, 12, 13, 14};
	list<int> X = { 1, 3, 4 };
	int x;

	for (std::list<int>::const_iterator iterator = X.begin(), end = X.end(); iterator != end; ++iterator) 
	{
			std::list<int>::const_iterator iterator1 = P.begin();
			x = *iterator;
			if (*iterator + 1 > P.size())
			{
				cout << "Element doesn't exist";
				break;
			}
			std::advance(iterator1, x);
			{
				std::cout << *iterator1 << "\n";
				x = -1;
			}
	}
	cin.get();
	return 0;
}

