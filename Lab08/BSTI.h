/**
*	@file BSTI.h
* 	@author Levi Clark
*	@date 2015.11.1
*
*/


#ifndef BSTI_H
#define BSTI_H

#include <vector>
using namespace std;

enum Order
{
	PRE_ORDER,
	IN_ORDER, 
	POST_ORDER
};

template <typename T>
class BSTI
{
	public:
	
	
    	/*precondition: A BSTI exists
    	//postcondition: Deletes the entire tree
    	returns: Returns a pointer to a deep copy of this 
    	*/
	virtual ~BSTI(){};
		
  	/*	
    	precondition: this is in a valid state
    	postcondition: Creates a deep copy of this
    	returns: Returns a pointer to a deep copy of this
   	*/
	virtual BSTI<T>* clone() = 0;
	
    	/*	
    	precondition: none
    	postcondition: none
    	returns: true if no nodes in the tree, otherwise returns false.
   	*/
	virtual bool isEmpty() const = 0;
	
    	/*	
    	precondition: none
    	postcondition: none
    	returns: true if no nodes in the tree, otherwise returns false.
    	*/
	virtual bool add(T value) = 0;
	
   	/*
   	precondition: The type T is comparable by the == operator
   	returns: true if the value is in the tree, false otherwise
	*/
	virtual bool search(T value) const = 0;
	
	//postcondition: the contents of the tree are printed to the console in the specified order 
	virtual void printTree(Order order) const = 0;
	
	//returns a vector with the contents of the tree in the specified order is returned 
	virtual std::vector<T>treeToVector(Order order) const = 0;
};
#endif










