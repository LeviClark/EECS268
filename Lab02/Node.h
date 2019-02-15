//Levi Clark
//Lab02
//september 13, 2015
#ifndef NODE_H
#define NODE_H

class Node
{
	public: 
	Node();
	//get	
	int getValue();
	
	//set
	void setValue(int val);
	
	void setNext(Node* prev);
	
	Node* getNext();
	
	private:
	int m_value;
	Node* m_next;
};
#endif
