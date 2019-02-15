/**
*	@file Stack.hpp
* 	@author Levi Clark
*	@date 2015.09.03
*
*/

#include <iostream>
#include "Stack.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"
using namespace std;
template<typename T>
Stack<T>::Stack()
{
	//This needs nothing in it.
}

template<typename T>
Stack<T>:: ~Stack()
{
	while(!isEmpty())
	{
		pop();
	}

}

template<typename T>
bool Stack<T>:: isEmpty()
{
	if(m_size == 0)
	{
		
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void Stack<T>::push(T newEntry)
{
	Node<T>* temp = new Node<T>();
	temp->setValue(newEntry);
	
	if(isEmpty())
	{
		m_head = temp;
		temp = nullptr;
	}
	else
	{
		temp->setNext(m_head);
		m_head = temp;
		temp = nullptr;
	}
	m_size++;
	


}

template<typename T>
void Stack<T>:: pop() throw(PreconditionViolationException)
{
	if(isEmpty())
	{
		throw(PreconditionViolationException("Error"));
	}
	else
	{
		Node<T>* temp = m_head;
		m_head = m_head->getNext();
		delete temp;
		temp = nullptr;
		m_size--;
		
	}

}
template<typename T>
int Stack<T>:: size()
{
	return(m_size);
}

template<typename T>
T Stack<T>:: peek() throw(PreconditionViolationException)

{
	if(isEmpty())
	{
		throw(PreconditionViolationException("Error: Peek attempted on an empty stack \n"));
	}
	else
	{
		T value= m_head->getValue();
		return(value);
	}
	
}

template<typename T>
void Stack<T>:: print()
{
	if(isEmpty())
	{
		cout<<"";
	}
	else
	{
		Node<T>* temp = m_head;
		while(temp != nullptr)
		{
			cout<<temp->getValue();
			cout<<" ";
			temp = temp->getNext();
		}
	}
}

















