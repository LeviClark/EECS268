/**
*	@file Main.cpp
* 	@author Levi Clark
*	@date 2015.09.03
*
*/


#include "Node.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include "Stack.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"
#include "Test.h"
using namespace std;

int main()
{
	StackInterface<int>* myStack = new Stack<int>;
	void printMenu();
	
	int choice= 0;
	int input;
	
	while(choice != 5)
	{
	printMenu();
	cin >> choice;
	
	if(choice ==1)
	{
		cout << "Input a number to add to the stack: \n";
		cin>> input;
		myStack->push(input);
		
	}
	
	else if(choice ==2)
	{
		try
		{
			cout<<myStack->peek() << " is at the top of stack \n";
		}
		catch(PreconditionViolationException& e)
		{
			cout<< e.what();
		}
	}
	else if(choice ==3)
	{
		
		myStack->print();
			
	}
	else if(choice ==4)
	{
		try
		{
			myStack->pop();
		}
		catch(PreconditionViolationException& e)
		{
			cout<< e.what();
		}
	}
	else if(choice ==6)
	{
		Test myTester(std::cout); //declares test instance
		myTester.runTests(); //runs a series of tests on your code
	}
	else if(choice < 1 || choice > 6)
	{
		cout << "Please enter a value between (1-6): \n";
	}
	}
	cout<<"Program ending \n";
	delete myStack;
	return(0);
}

void printMenu()
{
	std::cout 	<< "\n\nSelect an action:\n"
			<< "1) Add to stack \n"
			<< "2) See what is at the top of stack\n"
			<< "3) Print all stack\n"
			<< "4) Pop stack\n"
			<< "5) Quit\n"
 			<< "6) Run Tests\n"
			<< "Enter choice: ";
}
