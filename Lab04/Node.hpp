/**
*	@file Node.hpp
* 	@author Levi Clark
*	@date 2015.09.03
*
*/

#include <iostream>
#include "Node.h"


using namespace std;
template<typename T>
Node<T>::Node()
{
	m_value = T();
	m_next = nullptr;
		
}
template<typename T>
void Node<T>:: setValue(T val)
{
	m_value = val;
}
template<typename T>
T Node<T>:: getValue()
{
	return(m_value);
}
template<typename T>	
void Node<T>:: setNext(Node<T>* next)
{
	m_next = next;
}
template<typename T>
Node<T>* Node<T>::getNext()
{
	return(m_next);
}

