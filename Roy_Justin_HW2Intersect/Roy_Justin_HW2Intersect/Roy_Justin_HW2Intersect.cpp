#include<iostream>
#include<list>
using namespace std;

//I wanted to make an exception handler but didn't get it working properly. If the index is too high it crashes.
std::list<int> intersection(std::list<int> first, std::list<int> second)
{
	//Store results
	std::list<int> result;

	//For each element in the first list, iterate through the second list and check for any matching values.
	//First list iterator
	for (std::list<int>::iterator it1 = first.begin(); it1 != first.end(); it1++) 
	{
		//Second list iterator
		for (std::list<int>::iterator it2 = second.begin(); it2 != second.end(); it2++) 
		{ 
			if (*it1 == *it2) 
			{
				result.push_back(*it1);
				break;
			}
		}
	}
	return result;
}

int main()
{
	int firstSet[] = { 5, 2, 1, 4 };
	std::list<int> first(firstSet, firstSet + sizeof(firstSet) / sizeof(int)); //create first list
	int secondSet[] = { 4, 5, 7 };

	std::list<int> second(secondSet, secondSet + sizeof(secondSet) / sizeof(int)); //create second list

	std::list<int> result = intersection(first, second);
	cout << "Intersection: ";

	for (std::list<int>::iterator it = result.begin(); it != result.end(); it++) 
	{
		cout << *it << ",";
	}
	cin.get();
	cout << "\n";
}