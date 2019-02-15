/**
*	@file Node.h
* 	@author Levi Clark
*	@date 2015.11.1
*
*/

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
	public:
	Node();
	Node(const Node<T>& other);
	
	//getters
	T getValue() const;
	Node<T>* getLeft() const;
	Node<T>* getRight() const;
	
	//setters
	void setValue(T value);
	void setLeft(Node<T>* left);
	void setRight(Node<T>* right);
	
	private:
	Node<T>* m_left;
	Node<T>* m_right;
	T m_value;
};
#include "Node.hpp"
#endif
