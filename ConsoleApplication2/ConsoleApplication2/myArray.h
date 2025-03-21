
#pragma once

#include<iostream>

template<typename T>
class MyArray
{
private:
	T* arr;
	int size;

public:
	MyArray();
	MyArray(int size);
	MyArray(const MyArray<T>& other);
	~MyArray();

	MyArray<T>& operator=(const MyArray<T>& other);

	const T operator[](int index) const;
	T& operator[](int index);

	friend std::ostream& operator<<(std::ostream& os, const MyArray<T>& myArr)
	{
		os << "{ ";
		for (int i = 0; i < myArr.size; i++)
		{
			os << "[" << myArr.arr[i] << "] ";
		}
		return os << "} ";
	}

	T max()const;
	T min()const;
	void reverse();

	int getSize() const;
	T* getArr() const;
};

template<typename T>
inline MyArray<T>::MyArray()
{
	arr = nullptr;
	size = 0;
}

template<typename T>
inline MyArray<T>::MyArray(int size)
{
	arr = new T[size];
	this->size = size;
}

template<typename T>
inline MyArray<T>::MyArray(const MyArray<T>& other)
{
	size = other.size;
	arr = new T[other.size];
	for (int i = 0; i < other.size; i++)
	{
		arr[i] = other.arr[i];
	}
}

template<typename T>
inline MyArray<T>::~MyArray()
{
	delete[] arr;
}

template<typename T>
inline MyArray<T>& MyArray<T>::operator=(const MyArray<T>& other)
{
	if (this == &other)
		return *this;
	if (arr != nullptr)
		delete[] arr;

	size = other.size;
	arr = new T[other.size];
	for (int i = 0; i < other.size; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}

template<typename T>
inline const T MyArray<T>::operator[](int index) const
{
	return arr[index];
}

template<typename T>
inline T& MyArray<T>::operator[](int index)
{
	return arr[index];
}


template<typename T>
inline T MyArray<T>::max() const
{
	if (arr == nullptr)
		return T();
	T max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

template<typename T>
inline T MyArray<T>::min() const
{
	if (arr == nullptr)
		return T();
	T min = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

template<typename T>
inline void MyArray<T>::reverse()
{
	for (int i = 0; i < this->size / 2; i++) {
		T bubble = this->arr[this->size - i - 1];
		this->arr[this->size - i - 1] = arr[i];
		this->arr[i] = bubble;
	}
}

template<typename T>
inline int MyArray<T>::getSize() const
{
	return size;
}

template<typename T>
inline T* MyArray<T>::getArr() const
{
	return arr;
}