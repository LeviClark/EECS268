/**
*	@file Node.h
* 	@author Levi Clark
*	@date 2015.09.03
*
*/


#ifndef NODE_H
#define NODE_H
#include "PreconditionViolationException.h"
template<typename T>
class Node
{
	public: 
	Node();
	void setNext(Node<T>* next);
	T getValue();
	void setValue(T val);
	Node<T>* getNext();
	
	private:
	T m_value;
	Node<T>* m_next;
	
};
#include "Node.hpp"
#endif
