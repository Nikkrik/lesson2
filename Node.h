
#pragma once

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
	Node<T>* getNext() const;
	void setNext(Node<T>* next);
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
inline Node<T>* Node<T>::getNext() const
{
	return next;
}

template<typename T>
inline void Node<T>::setNext(Node<T>* next)
{
	this->next = next;
}

