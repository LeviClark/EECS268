/**
*	@file StackInterface.h
* 	@author Levi Clark
*	@date 2015.09.03
*
*/

#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H
#include "Node.h"
#include "PreconditionViolationException.h"
template<typename T>
class StackInterface
{
public: 

virtual ~StackInterface() {};

virtual bool isEmpty()= 0; //checks to see if stack is empty or not.

virtual void push(T newEntry) = 0; //creates a new node and inserts at top of stack. then sets m_head to equal this newEntry.

virtual void pop() throw(PreconditionViolationException) = 0;//deletes the m_head node and reasignes m_head to the next node in the list.

virtual T peek() throw(PreconditionViolationException) = 0;//outputs the value of the m_head node.

virtual int size()= 0;

virtual void print()= 0;//prints the stack in order. if its empty, prints "".

private: 
Node<T>* m_head = nullptr;
T m_size = 0;	
};

#endif
