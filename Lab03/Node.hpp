//Levi Clark
//Lab03
//september 23, 2015
#include <iostream>
#include "Node.h"
#include "DoubleLinkedList.h"

using namespace std;
template<typename T>
Node<T>::Node()
{
	m_value = T();
	m_next = nullptr;
	m_previous= nullptr;	
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
template<typename T>
Node<T>* Node<T>::getPrev()
{
	return(m_previous);
}
template<typename T>
void Node<T>::setPrev(Node<T>* prev)
{
	m_previous = prev;
}	

