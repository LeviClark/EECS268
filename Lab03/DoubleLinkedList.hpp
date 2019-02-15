//Levi Clark
//Lab03
//september 23, 2015

#include <iostream>
#include "Node.h"
#include "DoubleLinkedList.h"
using namespace std;

template<typename T>
DoubleLinkedList <T>::DoubleLinkedList()
{
	m_front = nullptr;
	m_back = nullptr;
	
	m_size = 0;
}
//deconstructor
template<typename T>
DoubleLinkedList<T>:: ~DoubleLinkedList()
{
	while (!isEmpty())
	{
		removeFront();
		
	}
	
}

template<typename T>
bool DoubleLinkedList <T>::isEmpty()
{
	if(m_size == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}
template<typename T>	
int DoubleLinkedList<T>::size()
{
	return m_size;
}
template<typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
	Node<T>* temp = new Node<T>();
	temp->setValue(value);
	
	if(isEmpty())
	{
		m_front = temp;	
	}
	else	
	{
		temp->setNext(m_front);
		m_front = temp;
		
	}
	m_size++;
}



template<typename T>
void DoubleLinkedList<T> :: printList()
{
	Node<T>* temp = m_front;
	if(isEmpty())
	{
		cout<<"";
	}
	
	while(temp != nullptr)
	{
		cout<<temp->getValue();
		cout<<" ";
		temp = temp->getNext();
	}
}

template<typename T>

void DoubleLinkedList<T> :: pushBack(T value)
{
	Node<T>* myNode = new Node<T>();
	myNode->setValue(value);
	
	if(isEmpty())
	{
		m_front = myNode;
		m_back = myNode;
	}
	else
	{
		Node<T>* temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}
		temp->setNext(myNode);
		myNode->setPrev(temp);
	}
	m_size++;
}
template<typename T>
bool DoubleLinkedList<T>::removeFront()
{
	if(isEmpty())
	{
		return(false);
	}
	else
	{
		Node<T>* temp= m_front;
		m_front = m_front->getNext();
		delete temp;
		temp = nullptr;
		m_size--;
		return(true);
	}
}
template<typename T>
bool DoubleLinkedList<T> :: removeBack()
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
	
		
		Node<T>* tail = m_front;
		
		while(tail->getNext() != nullptr)
		{
			tail = tail->getNext();
		}
		Node<T>* temp = m_front;
		while(temp->getNext() != tail)
		{
			temp = temp->getNext();
		}
		delete tail;
		tail = nullptr;
		temp->setNext(nullptr);
		m_size--;
		return true;
	}
	
}


template<typename T>
bool DoubleLinkedList<T>::remove(T value)
{
	Node<T>* temp = m_front;
	Node<T>* head = temp;
	Node<T>* tail = nullptr;
	temp = find(value);
	if(isEmpty())
	{
		return false;
	}
	else if(!isEmpty())
	{
		if(temp == nullptr)
		{
			return false;	
		}
		if(temp == m_front)
		{
			removeFront();
			return true;
			
		}
		
		else if(temp->getNext() == nullptr)
		{
			removeBack();
			return true;
		}
		
		else if(temp != m_front && temp->getNext()!= nullptr)
		{
		while(head->getNext() != temp)
		{
			head = head->getNext();
		}
		
		//links the nodes before and after the node we're removing.
		tail=temp->getNext();
          	head->setNext(tail);
          	tail->setPrev(head);
          	delete temp;
          	temp = NULL;
          	m_size--;
          	return true;
          	}	
	}
	return true;

}

template<typename T>
Node<T>* DoubleLinkedList<T>:: find(T value)
{
	
	if(isEmpty())
	{
		return nullptr;
	}
	else
	{
		Node<T>* temp = m_front;
		while(temp != nullptr)
		{
			if(temp->getValue() == value)
			{
				return temp;
			}
			else
			{
				temp = temp->getNext();
			}
		}
		return nullptr;	
		
	}
}
template<typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue) throw(std::runtime_error)
{
	if(isEmpty())
	{
		throw(runtime_error("list is empty"));
	}
	
	Node<T>* t1 = nullptr;
	Node<T>* t2 = m_front;
	Node<T>* myNode = new Node<T>();
	
	myNode->setValue(newValue);
	t1 = find(listValue);
	if(t1 == nullptr)
	{
		throw(runtime_error("value isnt in list"));
	}
	if(t1 == m_front)
	{
		m_front = myNode;
		m_front->setNext(t1);
		t1->setPrev(myNode);
		m_size++;
	}
	else
	{
	while(t2->getNext() != t1)
	{
		t2 = t2->getNext();
	}
	t2->setNext(myNode);
	myNode->setNext(t1);
	t1->setPrev(myNode);
	myNode->setPrev(t2);
	m_size++;
	}
}
template<typename T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue) throw(std::runtime_error)
{
	if(isEmpty())
	{
		throw(runtime_error("list is empty"));
	}
	
	Node<T>* t1 = nullptr;
	Node<T>* t2 = m_front;
	Node<T>* myNode = new Node<T>;
	
	myNode->setValue(newValue);
	t1 = find(listValue);
	if(t1 == nullptr)
	{
		throw(runtime_error("value isnt in list"));
	}
	if(t1->getNext() == nullptr)
	{
		t1->setNext(myNode);
		myNode->setNext(nullptr);
		m_size++;
	}
	else
	{
		t2 = t1->getNext();
		myNode->setNext(t2);
		t1->setNext(myNode);
		myNode->setPrev(t1);
		t2 -> setPrev(myNode);
	
	
	}
}

























































