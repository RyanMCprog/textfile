#pragma once

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 10;

	
	T *arr;
	size_t arrSize;
	size_t arrCapacity;

public:
	tVector();

	~tVector()
	{
		delete[] arr;
	}

	T *data();

	void reserve(size_t newCapacity);

	void push_back(const T &value);
	void pop_back();

	T &at(size_t index);

	size_t size() const;
	size_t capacity() const;

};

template<typename T>
inline tVector<T>::tVector()
{
	T *temp = new T[10];
	arr = new T[10];
	arrSize = 0;
	arrCapacity = 10;
	
}

template<typename T>
inline T * tVector<T>::data()
{
	return arr;
}

template<typename T>
inline void tVector<T>::reserve(size_t newCapacity)
{
	T *temp;
	if (arrCapacity =< newCapacity)
	{
		arrCapacity += GROWTH_FACTOR;
		temp = new T[arrCapacity];
		for (int i = 0; i < arrsize; i++)
		{
			temp[i] = arr[i];
		}
		
		delete[] arr;
		arr = temp;
	}
}

template<typename T>
inline void tVector<T>::push_back(const T & value)
{
	arr[arrSize] = value;
	arrSize++;
	reserve(arrSize);
}

template<typename T>
inline void tVector<T>::pop_back()
{

}
