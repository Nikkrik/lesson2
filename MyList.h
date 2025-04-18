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
	void addBack(T&& element);

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
	tail = new Node<T>(element, nullptr);
	size = 1;
}

template<typename T>
inline MyList<T>::MyList(const MyList<T>& other)
{
	// Доделать до полной копии
	
	head = new Node<T>(other.head->getElement(), nullptr);
	Node<T>* iter = other.head->getNext();
	while (iter)
	{
		Node<T>* newNode = new Node<T>(iter->getElement(), nullptr);
		iter->setNext(newNode);
		iter = iter->getNext();
	}
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

template<typename T>
inline void MyList<T>::addBack(T&& element)
{

}


template<typename T>
inline T& MyList<T>::delBack()
{
	if (head == tail)
	{
		return head->getElement();
	}
	Node<T>* tmp = head;
	for (int i = 0; i < size - 1; i++)
	{
		tmp = tmp->getNext();
	}
	tmp->setNext(nullptr);
	T tp = tail->getElement();
	delete tmp;
	tail = tmp;
	return tp;
}

template<typename T>
inline T& MyList<T>::delFront()
{
	if (head == tail)
	{
		return head->getElement();
	}
	Node<T>* tmp = head;
	head = head->getNext();
	T tp = head->getElement();
	delete tmp;
	return tp;
}


