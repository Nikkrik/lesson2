#pragma once

#include<iostream>
#include"Node.h"


template <typename T>
class MyList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	MyList();
	MyList(T& element);
	MyList(const MyList<T>& other);
	~MyList();

	void add(T&& element);
	void add(const T& element);
	void addFront(T&& element);
	void addFront(const T& element);
	Node<T>& begin();
	Node<T>& end();

	T& operator[](int index);
	const T operator[](int index) const;

	T& delBack();
	T& delFront();


	friend std::ostream& operator<<(std::ostream& os, const MyList<T>& myList)
	{
		Node<T>* iter = myList.head;
		while (iter)
		{
			os << iter->getElement() << " ";
			iter = iter->getNext();
		}
		return os;
	}
};

template<typename T>
inline MyList<T>::MyList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
inline MyList<T>::MyList(T& element)
{
	head = new Node<T>(element, nullptr);
	tail = head;
	size = 1;
}

template<typename T>
inline MyList<T>::MyList(const MyList<T>& other)
{
	size = other.size;
	head = new Node<T>(other.head->getElement(), nullptr);
	Node<T>* newIter = head;
	Node<T>* iter = other.head;
	while (iter)
	{
		Node<T>* copyElment = new Node<T>(iter->getElement(), nullptr);
		newIter->setNext(copyElment);
		newIter = newIter->getNext();
		iter = iter->getNext();
	}
	tail = newIter;
}

template<typename T>
inline MyList<T>::~MyList()
{
	while (head != nullptr) {
		Node<T>* next = head->getNext();
		delete head;
		head = next;
	}
}

template<typename T>
inline void MyList<T>::add(T&& element)
{
	const T newElement = element;
	add(newElement);
}

template<typename T>
inline void MyList<T>::add(const T& element)
{
	++size;
	T copyElement = element;
	Node<T>* newNode = new Node<T>(copyElement, nullptr);
	tail->setNext(newNode);
	tail = newNode;
}


template<typename T>
inline void MyList<T>::addFront(T&& element)
{
	const T newElement = element;
	addFront(newElement);
}

template<typename T>
inline void MyList<T>::addFront(const T& element)
{
	++size;
	T copyElement = element;
	Node<T>* newNode = new Node<T>(copyElement, nullptr);
	newNode->setNext(head);
	head = newNode;
}

template<typename T>
inline T& MyList<T>::operator[](int index)
{
	if (index >= size) return head->getElement();
	if (index < 0) return tail->getElement();
	Node<T>* result = head;
	for (int i = 0; i < index; ++i) {
		result = result->getNext();
	}
	return result->getElement();
}

template<typename T>
inline const T MyList<T>::operator[](int index) const
{
	if (index >= size) return tail->getElement();
	if (index < 0) return head->getElement();
	Node<T>* result = head;
	for (int i = 0; i < index; ++i) {
		result = result->getNext();
	}
	return result->getElement();
}

template<typename T>
inline Node<T>& MyList<T>::begin()
{
	return *head;
}

template<typename T>
inline Node<T>& MyList<T>::end()
{
	return *tail;
}

template<typename T>
inline T& MyList<T>::delBack() {
	if (head == tail)
	{
		throw std::invalid_argument("empty list");
	}
	Node<T>* tmp = head;
	while (tmp->getNext() != tail) {
		tmp = tmp->getNext();
	}
	tmp->setNext(nullptr);
	T tp = tail->getElement();
	delete tail;
	tail = tmp;
	return tp;
}

template<typename T>
inline T& MyList<T>::delFront()
{
	if (head == tail)
	{
		throw std::invalid_argument("empty list");
	}
	Node<T>* tmp = head;
	head = head->getNext();
	T tp = tmp->getElement();
	delete tmp;
	return tp;

}


