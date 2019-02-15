//Levi Clark
//Lab03
//sept 23, 2015

#include <iostream>
#include "Node.h" 
#include "DoubleLinkedList.h"
#include "Test.h"
#include <string>
#include <stdexcept>

using namespace std;

int main()
{
	DoubleLinkedList<int>* myList= new DoubleLinkedList<int>;
	
	
	int x;
	int y;
	int input;
	void printMenu();
	//until the user types "7" the program will loop asking for and calling different methods.
	while(input !=9)
	{

	printMenu();
	cin>> input;
	cout << "You chose " << input << endl;
	if(input ==1)
	{
		cout << "Enter a value to add to the front of the list: ";
		cin >> x;
		cout << "Adding " << x << " to the list \n";
		myList->pushFront(x);
	}
	else if(input ==2)
	{
		cout << "Enter a value to add to the back of the list: ";
		cin >> x;
		cout << "Adding " << x << " to the list \n";
		myList->pushBack(x);
	}
	
	else if(input ==3)
	{
		cout<< "Give a value to insert: \n";
		cin >> x;
		cout<< "Pick a value to insert behind: \n";
		cin >> y;
		try
		{
		myList->insertBehind(y, x);
		}
		catch(runtime_error& e)
		{
			cout<< e.what() << endl;
		}
	}
	
	else if(input ==4)
	{
		cout << "Give a value to insert: \n";
		cin >> x;
		cout << "Pick a value to insert ahead of: \n";
		cin >> y;
		try
		{
		myList-> insertAhead(y, x);
		}
		catch(runtime_error& e)
		{
			cout << e.what() << endl;
		}
	}
	
	else if(input == 5)
	{
		cout << "attempting to remove from front of list \n";
		myList->removeFront();		
	}
	
	else if(input == 6)
	{
		cout <<"attempting to remove from the back of the list \n";
		myList->removeBack();
	}
	
	else if(input ==7)
	{
		cout <<"enter a value to remove from the list \n";
		cin >> x;
		myList->remove(x);
		
	
	}
	
	else if(input == 8)
	{
		cout<< "Printing list: \n";
		myList->printList();
	}
	else if(input == 10)
	{
		Test myTester(std::cout); //declares test instance
		myTester.runTests(); //runs a series of tests on your code
	}
	
	else if(input<1 || input >10)
	{
		cout<< "sorry please pick a number between (1-10): \n";
	}
	


	}
	return(0);	
}

void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove front value\n"
		<<	"6) remove back value\n"
		<<	"7) remove specific value\n"
		<<	"8) print list\n"
		<<	"9) Quit\n"
		<< 	"10) Run Tests\n"
		<< 	"Your choice: ";
}

