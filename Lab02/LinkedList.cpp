//Levi Clark
//Lab02
//september 13, 2015

#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;
LinkedList::LinkedList()
{
	m_front = nullptr;
	m_size = 0;
}
//deconstructor
LinkedList:: ~LinkedList()
{
	while (!isEmpty())
	{
		removeFront();
		
	}
	
}
bool LinkedList::isEmpty()
{
	if (m_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LinkedList::size()
{
	return m_size;
}
bool LinkedList::search(int value)
{
	//traverse the list
	Node* temp = m_front;
	while(temp != nullptr)
	{
		if(temp->getValue()==value)
		{
			return true;
		}
		temp = temp->getNext();
	}
	return false;	
}

void LinkedList::printList()
{
	Node* temp = m_front;

	if(isEmpty())
	{
		cout << "";
	}
	while (temp != nullptr)
	{
		cout << temp->getValue() <<" ";
		temp = temp->getNext();
	}


}

void LinkedList::addFront(int value)
{
	Node* temp = new Node();
	temp->setValue(value);
	
	if(m_front == nullptr)
	{
		m_front = temp;
	}
	else //list already has something in it
	{
		temp->setNext(m_front);
		m_front = temp;
	}
	m_size++;
}

void LinkedList::addBack(int value)
{
	Node* temp =nullptr;
	Node* tail =nullptr;
	

	if (isEmpty())
	{
		m_front = new Node();
		m_front->setValue(value);
		m_size++;
	}
	else if(!isEmpty()) //something already in list
	{
		tail = m_front;
		while(tail->getNext()!=nullptr)
		{
			tail = tail->getNext();
		}
		temp = new Node();
		temp->setValue(value);
		tail->setNext(temp);
		m_size++;
	}
	
}

bool LinkedList::removeBack()
{
	Node* tail = m_front;
	Node* temp = m_front;
	if(isEmpty())
	{
		return(false);
	}
	else // there's already something in the list
	{
		//pushes tail to the end value
		while(tail->getNext() !=nullptr)
		{
			tail = tail->getNext();
		}
		//pushes temp to the node before the end
		while(temp->getNext()!=tail)
		{
			temp = temp->getNext();
		}
		//we can now delete the final one and point the second to last one to null
		delete tail;
		temp->setNext(nullptr);
		m_size --;
		return true;
		
	}
}

bool LinkedList::removeFront()
{
	if(isEmpty())
	{
		return(false);
	}
	else
	{
		Node* temp = m_front;
		m_front = m_front ->getNext();
		delete temp;
		temp = nullptr;
		m_size--;
		return(true);
	}
}

