/**
*	@file Main.cpp
* 	@author Levi Clark
*	@date 2015.11.1
*
*/


#include <iostream>
#include "Node.h"
#include "BinarySearchTree.h"
#include "BSTI.h"
#include <random>
#include <ctime>
#include <climits>
#include "Test.h"

using namespace std;
int main(int argc, char** argv)
{
	
	void printMenu();
	
	Test myTester; //declares a Test instance
	
	//makes sure the user inputs either 2 or 3 arguments.
	if(!(argc == 2 || argc == 3))
	{
		cout << "Sorry, invalid arguments. \n";
		return 0;
	}
	
	//sets the second input in the command line to be the argument type.
	string argumentType = argv[1];
	
	int numOfNodes = 0;
	
	//if argument type == "-nodes" then sets the 3rd argument to be the number of nodes total.
	if(argumentType =="-nodes" && argc ==3)
	{
		numOfNodes = atoi(argv[2]);
	}
	else if(argumentType =="-test")
	{
		myTester.runTests();
	}
	else
	{
		cout<<"Sorry, invalid arguments. \n";
	}
	
	if(numOfNodes<0)
	{
		cout << "Error, Can't have a negative number of nodes! \n";
	}
	
	int input = 0;
	int number = 0;
	
	//creates your tree and tree copy.
	BinarySearchTree<int>* myTree = new BinarySearchTree<int>();
	BinarySearchTree<int>* myTreeCopy = nullptr;
	
	//random numbers for tree.
	default_random_engine generator(time(nullptr));
	uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);
	
	cout<<"Populating tree with "<<numOfNodes<<" values\n";
	
	//adds random numbers into binary tree.
	for(int i = 0; i<numOfNodes; i++)
	{
		number=distribution(generator);
		if(myTree->add(number))
		{
			cout<< "Adding "<<number<< " to tree\n";
		}
		else
		{
			cout<<"Sorry, couldn't add value to tree\n";
		}
	}
	
	//while user doesnt want to exit.
	while(input !=8)
	{
		printMenu();
		cin>>input;
		
		//add to tree
		if(input == 1)
		{
			if(myTree!=nullptr)
			{
				cout<<"Choose a value to input into the original tree: \n";
				cin>>number;
				
				if(myTree->add(number))
				{
					cout<< "Adding "<<number<< " to tree\n";
				}
				
				else
				{
					cout<<"Sorry, couldn't add value to tree\n";
				}
			}
				
			else
			{
				cout<< "No tree found. Cannot add, sorry \n";
			}
		}
		//copy tree
		else if(input ==2)
		{
			myTreeCopy = new BinarySearchTree<int>(*(myTree));
			cout<<"Original tree has been copied.\n";
		}
		//delete tree
		else if(input ==3)
		{
			delete myTree;
			myTree=nullptr;
			cout<<"Deleted Tree.\n";
		}
		//print original tree
		else if(input ==4)
		{
			
			if(myTree==nullptr)
			{
				cout<<"No tree found.";
			}
			else
			{
				//print options
				cout<<"\nWhich type of print would you like to use?\n";
				cout<<"1) IN_ORDER\n";
				cout<<"2) PRE_ORDER\n";
				cout<<"3) POST_ORDER\n";
				cout<<"Your Choice: \n";
				
				int printType = 0;
				cin>>printType;
				//prints tree based of user input
				if(printType == 1)
				{
					myTree->printTree(IN_ORDER);
				}
				else if(printType == 2)
				{
					myTree->printTree(PRE_ORDER);
				}
				else if(printType == 3)
				{
					myTree->printTree(POST_ORDER);
				}
				else
				{
					cout<<"Sorry, please enter a value between 1-3: \n";
				}
			
			}
			
		}
		//print copy of tree
		else if(input == 5)
		{
			
			if(myTreeCopy==nullptr)
			{
				cout<<"No tree found.";
			}
			else
			{
				//print options
				cout<<"\nWhich type of print would you like to use?\n";
				cout<<"1) IN_ORDER\n";
				cout<<"2) PRE_ORDER\n";
				cout<<"3) POST_ORDER\n";
				cout<<"Your Choice: \n";
				
				int printType = 0;
				cin>>printType;
				
				//prints tree based off user input
				if(printType == 1)
				{
					myTreeCopy->printTree(IN_ORDER);
				}
				else if(printType == 2)
				{
					myTreeCopy->printTree(PRE_ORDER);
				}
				else if(printType == 3)
				{
					myTreeCopy->printTree(POST_ORDER);
				}
				else
				{
					cout<<"Sorry, please enter a value between 1-3: \n";
				}
			
			}
			
			
		}
		//search tree for value
		else if(input == 6)
		{
			
			if(myTree==nullptr)
			{
				cout<<"No tree found.";
			}
			else
			{
				cout<<"Choose a value to search for: \n";
				cin>> number;
				
				if(myTree->search(number))
				{
					cout<<number<< " is in the tree.\n";
				}
				else
				{
					cout<<number<< " is not in the tree.\n";
				}
			}
		}
		//search copy of tree for value
		else if(input == 7)
		{
			if(myTreeCopy==nullptr)
			{
				cout<<"No tree found.";
			}
			else
			{
				cout<<"Choose a value to search for: \n";
				cin>> number;
				
				if(myTreeCopy->search(number))
				{
					cout<<number<< " is in the tree.\n";
				}
				else
				{
					cout<<number<< " is not in the tree.\n";
				}
			}
		}
		//close
		else if(input == 8)
		{
			cout<< "Program is closing....\n";
		}
		//run tests
		else if(input == 9)
		{
			
			myTester.runTests(); //runs a series o tests on your code
		}
		
		else
		{
			cout<<"sorry, Please enter a value between 1-9: \n";
		}
	}
	if(myTree != nullptr)
	{
		delete myTree;
		myTree = nullptr;
	}
	delete myTreeCopy;
	myTreeCopy = nullptr;
	return 0;
	

}

void printMenu()
{
	std::cout<<"\nInput a selection\n";
	std::cout<<"1) Add more values to original tree\n";
	std::cout<<"2) Copy the original tree\n";
	std::cout<<"3) Delete the original tree (one time only)\n";
	std::cout<<"4) Print original tree\n";
	std::cout<<"5) Print copy\n";
	std::cout<<"6) Search original tree\n";
	std::cout<<"7) Search copy\n";
	std::cout<<"8) Exit\n";
	std::cout<<"9) Run tests\n";
	std::cout<<"Your choice:\n"; 

}















