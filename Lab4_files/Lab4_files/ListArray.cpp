
#ifndef LISTARRAY_CPP
#define LISTARRAY_CPP

using namespace std;

#include <iostream>
#include <stdexcept>
#include "ListArray.h"


template < typename DataType >
List<DataType>::List ( int maxNumber )
	: maxSize(maxNumber), cursor(-1), size(MAX_LIST_SIZE)
// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).
{
	dataItems = new DataType[maxNumber];
}

template < typename DataType >
List<DataType>::List ( const List& source )
	: maxSize(source.maxSize), cursor(source.cursor), size(source.size)
	
// Copy constructor. Creates a deep-copy list copied from 
// the provided model object, source.
{
	//If not present, create.
	if(dataItems == NULL)
		dataItems = new DataType[MAX_LIST_SIZE];

	//Copy.
	for (int i = 0; i <= size; i++)
	{
		dataItems[i] = source.dataItems[i];
	}
}
    
template < typename DataType >
List<DataType>& List<DataType>::operator= ( const List& source )
// Overloaded assignment operator. Resets a list object to contain a
// deep-copy of the provided model object, source.

//RESET VS CREATE
{
	//If not present, create.
	if (dataItems == NULL)
	{
		dataItems = new DataType[MAX_LIST_SIZE];
	}
		
	if (this != &source)
	{
		//If different, delete and remake.
		delete[] dataItems;
		maxSize = source.maxSize;
		size = source.size;
		cursor = source.cursor;
		dataItems = new DataType[maxSize];

		for (int i = 0; i<size; i++)
			dataItems[i] = source.dataItems[i];
	}
	return *this;
}

template < typename DataType >
// Frees the memory used by a list.
List<DataType>::~List ()
{
	//Delete Function
	delete[] dataItems;
}

template < typename DataType >
void List<DataType>::insert ( const DataType& newDataItem )
	throw ( logic_error )
// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.
{
	//Check for full
	if (isFull())
	{
		throw logic_error("List is full");
	}
	else
	{
		//If cursor hasn't been moved
		size++;
		if (cursor == -1)
		{
			cursor = 0;
		}
		//Else, start shifting.
		else
		{
			for (int i = size - 2; i>cursor; i--)
				dataItems[i + 1] = dataItems[i];
			cursor++;
		}
		dataItems[cursor] = newDataItem;
	}
}

template < typename DataType >
void List<DataType>::remove () throw ( logic_error )
// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	//Check empty
	if (isEmpty())
	{
		throw logic_error("List is empty");
	}	
	else
	{
		//Checking cursor location
		if (cursor == size - 1)
		{
			size--;
			gotoBeginning();
		}
		//Else, start shifting.
		else
		{
			for (int i = cursor; i<size; i++)
			{
				dataItems[i] = dataItems[i + 1];
			}
			size--;
		}
	}
}

template < typename DataType >
void List<DataType>::replace ( const DataType& newDataItem )
	throw ( logic_error )
// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	if (isEmpty())
	{
		throw logic_error("The list is empty.");
	}
	else
	{
		dataItems[cursor] = newDataItem;
	}
		
}

template < typename DataType >
void List<DataType>::clear ()
// Removes all the data items from a list.
{
	//Size = 0 removing all items and resetting cursor to default location
	size = 0;
	cursor = -1;
}

template < typename DataType >
bool List<DataType>::isEmpty () const
// Returns 1 if a list is empty. Otherwise, returns 0.
{
	//If empty, return 1
	if (size == 0) 
	{
		return true;
	}
	//Return 0
	return false;
}

template < typename DataType >
bool List<DataType>::isFull () const
// Returns 1 if a list is full. Otherwise, returns 0.
{
	//If size == current maxSize, is full. Return 1
	if (size == maxSize)
	{
		return true;
	}
	//Return 0
	return false;
}

template < typename DataType >
void List<DataType>::gotoBeginning ()
        throw ( logic_error )
// Moves the cursor to the beginning of the list.
{
	//iterator that makes cursor beginning.
	//If it can't be done, return false.
	if (isEmpty())
	{
		throw logic_error("The list is empty.");
		return;
		//Returning false is impossible due to void, ask instructor
	}
	else 
	{
		cursor = 0;
	}
}

template < typename DataType >
void List<DataType>::gotoEnd ()
        throw ( logic_error )
// Moves the cursor to the end of the list.
{
	//Same as Beginning.
	//If it can't be done, return false.
	if (isEmpty())
	{
		throw logic_error("The list is empty.");
		return;
		//Returning false is impossible due to void, ask instructor
	}
	//Check size, put cursor in front of last element
	else
	{
		cursor = size - 1;
	}
}

template < typename DataType >
bool List<DataType>::gotoNext()
throw (logic_error)
// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	if (isEmpty())
	{
		throw logic_error("The list is empty.");
	}
	else
	{
		//Move cursor assuming it's not at the end.
		if (cursor<size - 1)
		{
			cursor++;
			return true;
		}
	}
	return false;
}

template < typename DataType >
bool List<DataType>::gotoPrior ()
        throw ( logic_error )
// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.
{
	if (isEmpty())
	{
		throw logic_error("The list is empty.");
	}
	else
	{
		if (cursor != 0)
		{
			cursor--;
			return true;
		}
	}
	return false;
}

template < typename DataType >
DataType List<DataType>::getCursor () const
        throw ( logic_error )
// Returns the item marked by the cursor.
{
	if (isEmpty())
	{
		throw logic_error("The list is empty.");
	}
	else
	{
		return dataItems[cursor];
	}		
}

#include "show3.cpp"

template < typename DataType >
void List<DataType>::moveToNth ( int n )
        throw ( logic_error )
// Removes the data item marked by the cursor from a list and
// reinserts it as the nth data item in the list -- where the 
// data items are numbered from beginning to end, starting with 0.  
// Moves the cursor to the new position of the moved data
// item.
{
	if (size < n + 1)
		throw logic_error("The list does not have enough data items");
	else
	{
		DataType temp;
		temp = getCursor();
		remove();
		gotoBeginning();
		if (n == 0)
		{
			size++;
			for (int i = size - 1; i >= cursor; i--)
				dataItems[i + 1] = dataItems[i];
			dataItems[0] = temp;
		}
		else
		{
			for (int i = 0; i < n - 1; i++)
				gotoNext();
			insert(temp);
		}
	}
}

template < typename DataType >
bool List<DataType>::find ( const DataType& searchDataItem )
        throw ( logic_error )
// Searches a list for searchDataItem. Begins the search with the
// data items marked by the cursor. Moves the cursor through the list
// until either searchDataItem is found (returns true) or the end of the
// list is reached (returns false).
{
	if (isEmpty())
		throw logic_error("The list is empty.");
	else
	{
		for (int i = cursor; i<size; i++)
		{
			if (dataItems[i] == searchDataItem)
			{
				cursor = i;
				return true;
			}
		}
		cursor = size - 1;
	}
	return false;
}
#endif // ifndef LISTARRAY_CPP
