/**
*	@file SortDriver.h
* 	@author Levi Clark
*	@date 2015.26.15
*
*/

#ifndef SORTDRIVER_H
#define SORTDRIVER_H
#include <iostream>
#include <fstream>
#include "Sorts.h"


class SortDriver
{
	public:
	//takes in array and tests all of the private methods.
	static void run(int argc, char** argv);
	//prints help menu if wrong input is entered.
	static void printHelpMenu();
	
	private:
	//checks to see if file is accessible.
	static bool isFileAccessible(std::string fileName);
	//checks to see if sort is a valid type.
	static bool isSortValid(std::string sortParameter);
	//checks to make sure all parameters are correct.
	static bool areParametersValid(std::string sortName, std::string inputFileName);
	//gets how many numbers are in array.
	static int getFileCount(std::ifstream& inputFile);
	//creates the array
	static int* createArray(std::ifstream& inputFile, int size);
	//copies the  array
	static void copyArray(int original[], int copy[], int size);
	

};
#endif

