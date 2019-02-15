
/**
*	@file Main.h
* 	@author Levi Clark
*	@date 2015.20.15
*
*/

#include "Sorts.h"

#include<iostream>
#include "Test.h"

using namespace std;

int main()
{
	void printMenu();
	
	Sorts<int>* mySorter = new Sorts<int>();
	
	//variables we will use
	int sortType;
	char repeat;
	int size;
	int upper;
	int lower;
	char print;
	string typeOfSort;
	int* array;
	double time;
	while(repeat != 'y')
	{
		
		//Gets all input regarding the array(size, bounds, type of sort)
		printMenu();
		cin>> sortType;
		if(sortType!=5)
		{
		cout << "Input a size for the random array: \n";
		cin>> size;
		cout << "Input a lower bound on the range of random numbers: \n";
		cin>> lower;
		cout << "Input an upper bound on the range of random numbers: \n";
		cin>> upper;
		cout << "Do you want to print the unsorted array? (y/n): \n";
		cin >> print;
		
		array=mySorter->createTestArray(size, lower, upper);
		
		//prints unsorted array
		if(print == 'y')
		{
			cout << "Here is the unsorted array: \n";
			cout << "[";
			for(int i = 0; i<size; i++)
			{
				
				cout<< array[i];
				if(i != size-1)
				{
					cout<<", ";
				}
			}
			cout << "] \n";
		}
		}
		if(sortType == 1)
		{
			typeOfSort = "Bubble Sort";
			mySorter->bubbleSort(array, size);
			time = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, array, size);
			
		}
		
		else if(sortType == 2)
		{
			typeOfSort = "Insertion Sort";
			mySorter->insertionSort(array, size);
			time = Sorts<int>::sortTimer(Sorts<int>::insertionSort, array, size);
		}
		else if(sortType == 3)
		{
			typeOfSort = "Selection Sort";
			mySorter->selectionSort(array, size);
			time = Sorts<int>::sortTimer(Sorts<int>::selectionSort, array, size);
		}
		else if(sortType == 4)
		{
			typeOfSort = "Bogo Sort";
			mySorter->bogoSort(array, size);
			time = Sorts<int>::sortTimer(Sorts<int>::bogoSort, array, size);
		}
		else if(sortType == 5)
		{
			cout<<"Running Tests.... \n";
			Test myTester(std::cout);
			myTester.runTests();
		}
		else if(sortType>4 || sortType < 1)
		{
			cout<< "Sorry, please enter a choice between (1-4): \n";
			
		}
		
		
		if(sortType != 5)
		{
		cout << "Sorting with " << typeOfSort << "...\n";
		cout << "Do you want to print the sorted array? (y/n): \n";
		cin>> print;
		
		//prints the sorted array
		if(print == 'y')
		{
			cout << "Here is the sorted array: \n";
			cout << "[";
			for(int i = 0; i<size; i++)
			{
				
				cout<< array[i];
				if(i != size-1)
				{
					cout<<", ";
				}
			}
			cout << "] \n";
			
		}
		cout<<size<<" numbers were sorted in ";
		cout<<std::fixed; //found online to help
		cout<< time<< " seconds.\n";
	}	
		cout<<"Do you want to quit? (y/n): \n";
		cin>> repeat;
	}
	
		delete mySorter;
		return 0;



}

void printMenu()
{
	std::cout 	<< "\n\nSelect a sort:\n"
			<< "1) Bubble Sort\n"
			<< "2) Insertion Sort\n"
			<< "3) Selection Sort\n"
			<< "4) Bogo Sort (use only with very small arrays!)\n"
			<< "5) Run Tests \n"
			<< "Enter choice: ";
}


















