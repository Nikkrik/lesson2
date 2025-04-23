#pragma once

#include<iostream>

template <typename T>
class Node
{
private:
	T element;
	Node<T>* next;
public:
	Node();
	Node(T& element, Node<T>* next);
	Node(const Node<T>& other);
	~Node();

	T& getElement();
	void setElement(T& element);
	Node<T>* getNext();
	void setNext(Node<T>* next);

	const Node<T>& operator=(const  Node<T>& other);

	T& operator*();
	Node<T>& operator++();
	bool operator!=(Node<T>& other);

	friend std::ostream& operator<<(std::ostream& os, const Node<T>& node)
	{
		return os << node.element;
	}
};

template<typename T>
inline Node<T>::Node()
{
	element = T();
	next = nullptr;
}

template<typename T>
inline Node<T>::Node(T& element, Node<T>* next)
{
	this->element = element;
	this->next = next;
}

template<typename T>
inline Node<T>::Node(const Node<T>& other)
{
	element = other.element;
	next = other.next;
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
inline void Node<T>::setNext(Node<T>* next)
{
	this->next = next;
}

template<typename T>
inline const Node<T>& Node<T>::operator=(const Node<T>& other)
{
	if (this == &other)
		return *this;

	element = other.element;
	next = other.next;
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
		next = next->next;
	}
	return *this;
}

template<typename T>
inline bool Node<T>::operator!=(Node<T>& other)
{
	return element != other.element && next != other.next;
}
