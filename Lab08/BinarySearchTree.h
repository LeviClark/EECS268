/**
*	@file BinarySearchTree.h
* 	@author Levi Clark
*	@date 2015.11.1
*
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BSTI.h"
#include "Node.h"
#include <iostream>
using namespace std;
template <typename T>
class BinarySearchTree: public BSTI<T>
{
	public:
	//constructor
	BinarySearchTree();
	
	//copies the constructor (called in the clone() method)
	BinarySearchTree(const BinarySearchTree<T>& other);
	
	//deconstructor
	~BinarySearchTree();
	
	//creates a deep copy of this
	BSTI<T>* clone();
	
	/*
    	precondition: none
    	postcondition: none
    	returns: true if no nodes in the tree, otherwise returns false.
	*/
	bool isEmpty() const;
	
	/*
    	adds the value to the tree
    	returns true if add operation was successful
   	Note: this public method will depend on calling a private method of the same name
	*/
	bool add(T value);
	
	//precondition: The type T is comparable by the == operator 
	bool search(T value) const;
	
	//postcondition: the contents of the tree are printed to the console in the specified order 
	void printTree(Order order) const;
	
	//returns a vector with the contents of the tree in the specified order is returned.
	std::vector<T> treeToVector(Order order) const;
	
	
	
	private:
	
	Node<T>* m_root;
	
	//adds the value to the correct branch of the subtree
	bool add(T value, Node<T>* subTree);
	
	//deletes the left subtree, right subtree, and root node of the subtree passed in
	void deleteTree(Node<T>* subTree);
	
	//returns true if value is in tree, returns false if the value isnt in it.
	bool search(T value, Node<T>* subTree) const;
	
	//prints tree in the PRE, IN, and POST_ORDER types
	void printTree(Node<T>* subTree, Order order) const;
	
	//recursive helper function to load the vector, vec, in the specified order.
	void treeToVector(Order order, Node<T>* subTree, std::vector<T>& vec) const;


};
#include "BinarySearchTree.hpp"
#endif
