/**
*	@file BinarySearchTree.hpp
* 	@author Levi Clark
*	@date 2015.11.1
*
*/


#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
	if(!other.isEmpty())
	{
		m_root = new Node<T>(*(other.m_root));
	}
	else
	{
		m_root = nullptr;
	}
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteTree(m_root);
}

template <typename T>
BSTI<T>* BinarySearchTree<T>:: clone()
{
	BSTI<T>* clone = new BinarySearchTree<T>(*(this));
	return clone;
}

template <typename T>
bool BinarySearchTree<T>:: isEmpty() const
{
	if(m_root == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}

}

template <typename T>
bool BinarySearchTree<T>:: add(T value)
{
	return add(value, m_root);
}

template <typename T>
bool BinarySearchTree<T>:: search(T value) const
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
		return search(value, m_root);
	}
}

template <typename T>
void BinarySearchTree<T>:: printTree(Order order) const
{
	printTree(m_root, order);
}

template <typename T>
std::vector<T> BinarySearchTree<T>::treeToVector(Order order) const
{
	std::vector<T> vec;
	treeToVector(order, m_root, vec);
	return vec;
}

template <typename T>
void BinarySearchTree<T>:: treeToVector(Order order, Node<T>* subTree, std::vector<T>& vec) const
{
	//in = left, visit, right
	//pre = visit, left, right
	//post = left, right, visit
	
	if(subTree == nullptr)
	{
		return;
	}
	switch(order)
	{
		case Order::IN_ORDER:
		treeToVector(order, subTree->getLeft(), vec);
		vec.push_back(subTree->getValue());
		treeToVector(order, subTree->getRight(), vec);
		break;
		
		case Order::PRE_ORDER:
		vec.push_back(subTree->getValue());
		treeToVector(order, subTree->getLeft(), vec);
		treeToVector(order, subTree->getRight(), vec);
		break;
		
		case Order:: POST_ORDER:
		treeToVector(order, subTree->getLeft(), vec);
		treeToVector(order, subTree->getRight(), vec);
		vec.push_back(subTree->getValue());
		break;
	}
	
}

template <typename T>
bool BinarySearchTree<T>:: add(T value, Node<T>* subTree)
{
	if(isEmpty())
	{
		Node<T>* myNode = new Node<T>();
		myNode->setValue(value);
		m_root = myNode;
		return true;
	}
	else if(value<subTree->getValue())
	{
		if(subTree->getLeft() == nullptr)
		{
			Node<T>* myNode = new Node<T>();
			myNode->setValue(value);
			subTree->setLeft(myNode);
			return true;
		}
		return add(value, subTree->getLeft());
	}
	else if(value>subTree->getValue())
	{
		if(subTree->getRight() == nullptr)
		{
			Node<T>* myNode = new Node<T>();
			myNode->setValue(value);
			subTree->setRight(myNode);
			return true;
		}
		return add(value, subTree->getRight());
	}
	else
	{
		return false;
	}
}

template <typename T>
void BinarySearchTree<T>:: deleteTree(Node<T>* subTree)
{
	if(subTree!= nullptr)
	{
		if(subTree->getLeft() !=nullptr)
		{
			deleteTree(subTree->getLeft());
		}
		if(subTree->getRight() !=nullptr)
		{
			deleteTree(subTree->getRight());
		}
	}
	delete subTree;
	subTree = nullptr;
}

template <typename T>
bool BinarySearchTree<T>:: search(T value, Node<T>* subTree) const
{
	if(subTree == nullptr)
	{
		return false;
	}
	if(value == subTree->getValue())
	{
		return true;
	}
	if(value < subTree->getValue())
	{
		return search(value, subTree->getLeft());
	}
	else if(value > subTree->getValue())
	{
		return search(value, subTree->getRight());
	}
	return true;
}

template <typename T>
void BinarySearchTree<T>:: printTree(Node<T>* subTree, Order order) const
{

	//in = left, visit, right
	//pre = visit, left, right
	//post = left, right, visit
	
	if(subTree == nullptr)
	{
		return;
	}
	switch(order)
	{
		case Order::IN_ORDER:
		printTree(subTree->getLeft(), order);
		cout<<subTree->getValue()<< " ";
		printTree(subTree->getRight(), order);
		break;
		
		case Order::PRE_ORDER:
		cout<<subTree->getValue()<< " ";
		printTree(subTree->getLeft(), order);
		printTree(subTree->getRight(), order);
		break;
		
		case Order:: POST_ORDER:
		printTree(subTree->getLeft(), order);
		printTree(subTree->getRight(), order);
		cout<<subTree->getValue()<< " ";
		break;
	}
}











































