//Levi Clark
//Lab02
//september 13, 2015
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	bool isEmpty();
	int size();
	bool search(int value);
	void printList();
	void addBack(int value);
	void addFront(int value);
	bool removeBack();
	bool removeFront();

private:
Node* m_front;
int m_size;

};
#endif

