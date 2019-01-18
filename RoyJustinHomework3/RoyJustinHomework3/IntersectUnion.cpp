#include<iostream>
#include<set>

using namespace std;

//Find/Print Union
set<int> unionSet(set<int> set1, set<int> set2)
{
	set<int> result;
	std::set<int>::iterator iterator1; //Iterator
	for (iterator1 = set1.begin(); iterator1 != set1.end(); ++iterator1)
	{
		result.insert(*iterator1);
	}
	for (iterator1 = set2.begin(); iterator1 != set2.end(); ++iterator1)
	{
		result.insert(*iterator1);
	}
	return result;
}
//Find/Print intersect.
set<int> intersectionSet(set<int> set1, set<int> set2)
{
	set<int> result;
	std::set<int>::iterator iterator1;
	for (iterator1 = set1.begin(); iterator1 != set1.end(); ++iterator1)
	{
		set<int>::iterator iterator2;

		iterator2 = set2.find(*iterator1);
		if (iterator2 != set2.end())
		{
			result.insert(*iterator1);
		}
	}
	return result;
}

//Main()
int main()
{
	set<int> set1;
	set<int> set2; 
	int sizeSet1;
	int sizeSet2;

	cout << "Enter the number of elements in set 1: " << endl;
	cin >> sizeSet1;
	int tracker;

	cout << "\nEnter Elements: \n";
	for (tracker = 0; tracker< sizeSet1; tracker++)
	{
		int number;
		cin >> number;
		set1.insert(number);
	}

	cout << "Enter the number of elements in set 2: " << endl;
	cin >> sizeSet2;
	cout << "\nEnter Elements: \n";
	for (tracker = 0; tracker< sizeSet2; tracker++)
	{
		int number;
		cin >> number;
		set2.insert(number);
	}

	set<int> unionOfBoth;
	unionOfBoth = unionSet(set1, set2);
	set<int>::iterator iterator;

	cout << "\nUnion=\n";
	for (iterator = unionOfBoth.begin(); iterator != unionOfBoth.end(); ++iterator)
	{
		cout << *iterator << " ";
	}
	set<int> intersectOfBoth;
	intersectOfBoth = intersectionSet(set1, set2);
	cout << "\nIntersect=\n";
	for (iterator = intersectOfBoth.begin(); iterator != intersectOfBoth.end(); ++iterator)
	{
		cout << *iterator << " ";
	}
	return 0;
}