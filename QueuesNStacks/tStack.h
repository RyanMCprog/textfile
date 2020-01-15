#pragma once
#include "tVector.h"

template<typename T>
class tStack
{
	tVector<T> vec;

public:
	tStack();

	void push(const T& value);
	void pop();

	T& top();

	size_t size() const;

	bool empty() const;
};

template<typename T>
inline tStack<T>::tStack()
{
	
}

template<typename T>
inline void tStack<T>::push(const T & value)
{
	vec.arr[vec.arrSize] = value;
	vec.arrSize++;
	vec.reserve(vec.arrSize);
}

template<typename T>
inline void tStack<T>::pop()
{
	vec.arrSize--;
	vec.arr[vec.arrSize] = 0;
}

template<typename T>
inline T & tStack<T>::top()
{
	return vec.arr[vec.arrSize];
}

template<typename T>
inline size_t tStack<T>::size() const
{
	return vec.arrSize;
}

template<typename T>
inline bool tStack<T>::empty() const
{
	if (vec.arrSize == 0)
	{
		return true;
	}

	return false;
}
