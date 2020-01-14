#pragma once

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
};

template<typename T>
inline tStack<T>::tStack()
{

}
