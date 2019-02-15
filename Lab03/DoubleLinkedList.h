//Levi Clark
//Lab03
//september 23, 2015
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <stdexcept>

template <typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	bool isEmpty();
	int size();
	void pushFront(T value);
	void pushBack(T value);
	bool removeBack();
	bool removeFront();
	bool remove(T value);
	void insertAhead(T listValue, T newValue) throw(std::runtime_error);
	void insertBehind(T listValue, T newValue) throw(std::runtime_error);
	Node<T>* find(T value);
	void printList();
	
private:
Node<T>* m_front;
Node<T>* m_back;
int m_size;

};
#include "DoubleLinkedList.hpp"
#endif

