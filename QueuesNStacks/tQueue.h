#pragma once
#include "tVector.h"

template<typename T>
class tQueue
{
	tVector<T> vec;

public:
	tQueue();
	tQueue(size_t count, const T& value);

	void push(const T& value);
	void pop();

	T& front();

	size_t size() const;
};

template<typename T>
inline tQueue<T>::tQueue()
{
}

template<typename T>
inline tQueue<T>::tQueue(size_t count, const T & value)
{
	for (int i = 0; i < count; i++)
	{
		vec.arr[i] = value;
		vec.arrSize++;
		vec.reserve(vec.arrSize);
	}
}

template<typename T>
inline void tQueue<T>::push(const T & value)
{
}

template<typename T>
inline void tQueue<T>::pop()
{
}

template<typename T>
inline T & tQueue<T>::front()
{
	// TODO: insert return statement here
}

template<typename T>
inline size_t tQueue<T>::size() const
{
	return size_t();
}
