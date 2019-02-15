//Levi Clark
//Lab02
//september 13, 2015
#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
	m_value = 0;
	m_next = nullptr;	
	

}
void Node:: setValue(int val)
{
	m_value = val;
}

int Node:: getValue()
{
	return(m_value);
}
	
void Node:: setNext(Node* prev)
{
	m_next = prev;
}

Node* Node::getNext()
{
	return(m_next);
}



