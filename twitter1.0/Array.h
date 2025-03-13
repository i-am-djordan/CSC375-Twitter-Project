#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
using namespace std;

template <typename A>
class Array
{
public:
	Array(int size);
	inline A& operator[](int index);
	inline const A& operator[](int index) const;
	void changeSize(int newSize);
	inline int length() const;
	string err() const;

private:
	A* elements;
	A dud;
	int capacity;

	int errorCode;

};
template <typename A>
Array<A>::Array(int size)
{
	if (size < 1)
	{
		capacity = 1;
		errorCode = 1;
	}
	else
	{
		capacity = size;
		errorCode = 0;
	}

	elements = new A[capacity];
}

template <typename A>
inline A& Array<A>::operator[](int index)
{
#ifdef DEBUG_ARRAY
	if (index < 0 || index >= capacity)
	{
		errorCode |= 2;
		return dud;
	}

#endif 
	return elements[index];
}

template <typename A>
inline const A& Array<A>::operator[](int index) const
{
#ifdef DEBUG_ARRAY
	if (index < 0 || index >= capacity)
	{
		errorCode |= 2;
		return dud;
	}

#endif 
	return elements[index];
}

template <typename A>
void Array<A>::changeSize(int newSize)
{
	if (newSize < 1)
	{
		errorCode |= 4;
		return;
	}

	A* newArray = new A[newSize];
	int limit = (newSize > capacity) ? capacity : newSize;

	for (int i = 0; i < limit; i++)
		newArray[i] = elements[i];

	delete[]elements;
	elements = newArray;

	capacity = newSize;
}

template <typename A>
inline int Array<A>::length()const
{
	return capacity;
}

template <typename A>
string Array<A>::err()const
{
	if (errorCode == 0)
		return "No error.\n";

	string errorMessage = "";

	if (errorCode & 1)
	{
		errorMessage += "Nonpositive size passed into constructor, so \n";
		errorMessage += "the capacity was set to 1 by default.\n";
	}

	if (errorCode & 2)
	{
		errorMessage += "Index out of range.\n";
	}

	if (errorCode & 4)
	{
		errorMessage += "Nonpositive size passed into changeSize, so\n";
		errorMessage += "the size of the array was not changed.\n";
	}

	return errorMessage;

}

#endif
