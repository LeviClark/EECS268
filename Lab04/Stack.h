/**
*	@file Stack.h
* 	@author Levi Clark
*	@date 2015.09.03
*
*/


#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include "Node.h"


using namespace std;
template<typename T>

class Stack:  public StackInterface<T>
{
public: 
Stack();
virtual ~Stack();
virtual bool isEmpty();
virtual void push(T newEntry);//puts new node at top of stack. reassignes m_head to new node
virtual void pop() throw(PreconditionViolationException);//deletes node from front stack. reassignes m_head to next node in list.
virtual T peek() throw(PreconditionViolationException);//outputs value of node on top of stack.
virtual int size();
virtual void print();//prints the nodes in order from top to bottom of stack

private: 
Node<T>* m_head = nullptr;
T m_size = 0;		
	
};
#include "Stack.hpp"
#endif
