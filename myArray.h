
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

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <class T>
void boobleSort(T* a, int n) {
	int flag = 1;
	T t;
	while (flag) {
		flag = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[i + 1] < a[i]) {
				t = a[i]; a[i] = a[i + 1]; a[i + 1] = t;
				flag = 1;
			}
		}
	}
}

template <class T>
void insert(T* a, int n) {
	int j;
	T t;
	for (int i = 1; i < n; i++) {
		t = a[i];
		for (j = i - 1; j >= 0 && t < a[j]; j--)a[j + 1] = a[j];
		a[j + 1] = t;
	}
}

template <class T>
void select(T* a, int n) {
	int j, c;
	T t;
	for (int i = 0; i < n - 1; i++) {
		t = a[i]; c = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < t) {
				t = a[j];
				c = j;
			}
		a[c] = a[i];
		a[i] = t;
	}
}

template <class T>
void shell(T* a, int n) {
	int steps[5] = { 121,40,13,4,1 };
	int j;
	T t;
	for (int k = 0; k < 5; k++) {
		int step = steps[k];
		for (int i = step; i < n; i++) {
			t = a[i];
			for (j = i - step; j >= 0 && t < a[j]; j -= step)a[j + step] = a[j];
			a[j + step] = t;
		}
	}

}

template <class T>
void qs(T* a, int left, int right) {
	int i = left;
	int j = right;
	T x = a[(left + right) / 2];
	T t;
	do {
		while (i < right && a[i] < x)i++;
		while (j > left && a[j] > x)j--;
		if (i <= j) {
			t = a[i]; a[i] = a[j]; a[j] = t;
			i++; j--;
		}

	} while (i <= j);
	if (j > left)qs(a, left, j);
	if (i < right)qs(a, i, right);
}

template <class T>
int binary_search(T* a, int n, T key)
{
	int low = 1;
	int high = 1;
	int mid = 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < a[mid])high = mid - 1;
		else if (key > a[mid])low = mid + 1;
		else return mid;
	}
	return -1;
}



