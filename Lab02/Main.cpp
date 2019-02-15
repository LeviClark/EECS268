//Levi Clark
//Lab02
//9-14-15

#include <iostream>
#include "Node.h" 
#include "LinkedList.h"
#include "Test.h"

using namespace std;

int main()
{
	LinkedList* myList = new LinkedList();
	int x;
	int input;
	void printMenu();
	//until the user types "7" the program will loop asking for and calling different methods.
	while(input !=7)
	{

	printMenu();
	cin>> input;
	cout << "You chose " << input << endl;
	if(input ==1)
	{
		cout << "Enter a value to add to the front of the list: ";
		cin >> x;
		cout << "Adding " << x << " to the list \n";
		
		myList->addFront(x);
	}
	
	else if(input ==2)
	{
		cout << "Enter the value to add to the back of the list: ";
		cin >> x;
		cout << "Adding " << x << " to the list \n";
		
		myList->addBack(x);
	}
	else if(input == 3)
	{
		myList->removeFront();
		cout << "Attempting to remove from front of list: \n";
		cout << "Removal Successful\n";
	}
	
	else if(input ==4)
	{
		myList->removeBack();
		cout << "Attempting to remove from the end of the list: \n";
		cout << "Removal Successful\n";
	}
	
	else if(input ==5)
	{
		cout << "Printing list: ";
		myList->printList();
		
	}

	else if(input == 6)
	{
		cout<< "What number would you like to search for: \n";
		cin>> input;
		myList->search(input);
		cout << "Searching for " << input << endl;
		if(myList->search(input))
		{
			cout << input << " is in the list \n";
		}
		else
		{
			cout << input << " is not in the list \n";
		}
	}
	else if(input == 8)
	{
		Test myTester(std::cout); //declares test instance
		myTester.runTests(); //runs a series of tests on your code
	}
	
	else if(input<1 || input>8)
	{
		cout << "Error: Please enter a number between 1-8: \n";
	}

	//Node* testNode = new Node();
	//cout << testNode->getValue() << endl;

	//testNode->setValue(69);
	//cout << testNode->getValue();


	}
	return(0);	
}

void printMenu()
{
	cout << "\n\nSelect from the following menu: \n"
		<< "1) Add to the front of the list \n"
		<< "2) Add to the end of the list \n"
		<< "3) Remove from front of the list\n"
		<< "4) Remove from back of the list\n"
		<< "5) Print the list\n"
		<< "6) Search for value\n"
		<< "7) Exit\n"
		<< "8) Run tests\n"
		<< "Enter your choice: \n";
}
