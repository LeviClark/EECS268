//Levi Clark
//Lab03
//september 23, 2015
#ifndef NODE_H
#define NODE_H
template<typename T>
class Node
{
	public: 
	Node();
	void setNext(Node<T>* next);
	T getValue();
	void setValue(T val);
	Node<T>* getNext();
	Node<T>* getPrev();
	void setPrev(Node<T>* prev);
	private:
	T m_value;
	Node<T>* m_next;
	Node<T>* m_previous;
};
#include "Node.hpp"
#endif
