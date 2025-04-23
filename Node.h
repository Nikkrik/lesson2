#pragma once

#include<iostream>

template <typename T>
class Node
{
private:
	T element;
	Node<T>* next;
	Node<T>* prev;
public:
	Node();
	Node(T& element, Node<T>* next, Node<T>* prev);
	Node(T& element);
	Node(const Node<T>& other);
	~Node();

	T& getElement();
	void setElement(T& element);
	Node<T>* getNext();
	Node<T>* getPrev();
	void setNext(Node<T>* next);
	void setPrev(Node<T>* prev);

	const Node<T>& operator=(const  Node<T>& other);

	T& operator*();
	Node<T>& operator++();
	bool operator!=(Node<T>& other);


};

template<typename T>
inline Node<T>::Node()
{
	element = T();
	next = nullptr;
	prev = nullptr;
}

template<typename T>
inline Node<T>::Node(T& element, Node<T>* next, Node<T>* prev)
{
	this->element = element;
	this->next = next;
	this->prev = prev;
}

template<typename T>
inline Node<T>::Node(T& element)
{
	this->element = element;
	next = nullptr;
	prev = nullptr;
}

template<typename T>
inline Node<T>::Node(const Node<T>& other)
{
	element = other.element;
	next = other.next;
	prev = other.prev;
}

template<typename T>
inline Node<T>::~Node()
{

}

template<typename T>
inline T& Node<T>::getElement()
{
	return element;
}

template<typename T>
inline void Node<T>::setElement(T& element)
{
	this->element = element;
}

template<typename T>
inline Node<T>* Node<T>::getNext()
{
	return next;
}

template<typename T>
inline Node<T>* Node<T>::getPrev()
{
	return prev;
}

template<typename T>
inline void Node<T>::setNext(Node<T>* next)
{
	this->next = next;
}

template<typename T>
inline void Node<T>::setPrev(Node<T>* prev)
{
	this->prev = prev;
}

template<typename T>
inline const Node<T>& Node<T>::operator=(const Node<T>& other)
{
	if (this == &other)
		return *this;

	element = other.element;
	next = other.next;
	prev = other.prev;
	return *this;
}

template<typename T>
inline T& Node<T>::operator*()
{
	return element;
}

template<typename T>
inline Node<T>& Node<T>::operator++()
{
	if (next != nullptr)
	{
		element = next->element;
		Node<T>* oldNext = next;
		next = next->next;
		prev = oldNext;
	}
	return *this;
}

template<typename T>
inline bool Node<T>::operator!=(Node<T>& other)
{
	return element != other.element
		&& next != other.next
		&& prev != other.prev;
}


