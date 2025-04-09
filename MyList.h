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
	void addFront(T&& element);

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
	tail = new Node<T>(element, nullptr);
	size = 1;
}

template<typename T>
inline MyList<T>::MyList(const MyList<T>& other)
{
	
	head = other.head;
	tail = other.tail;
	size = other.size;
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
	++size;
	Node<T>* newNode = new Node<T>(element, nullptr);
	Node<T>* iter = head;
	while (iter->getNext())
	{
		iter = iter->getNext();
	}
	iter->setNext(newNode);
}

template<typename T>
inline void MyList<T>::addFront(T&& element)
{
	++size;
	Node<T>* newNode = new Node<T>(element, nullptr);
	newNode->setNext(head);
	head = newNode;
}

