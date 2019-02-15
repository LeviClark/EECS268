/**
*	@file Main.cpp
* 	@author Levi Clark
*	@date 2015.26.15
*
*/

#include <iostream>
#include "SortDriver.h"
#include "NumberFileGenerator.h"
#include "NumberFileDriver.h"
#include "Sorts.h"
#include "Test.h"


using namespace std;
int main(int argc, char** argv)
{
	
	string mode = argv[1];
	if(argc < 5 && argc != 2)
	{
		cout<< "Please enter more arguments: \n";
	}
	else
	{
	 //Check for number file creation flag
	if(mode == "-create")
	{	
		NumberFileDriver::run(argc, argv);		
	}
	//Check for sort flag
	else if (mode == "-sort")
	{
		SortDriver::run(argc, argv);
	}
	//Check for test flag
	if(argc ==2)
	{
		string mode = argv[1];
		if (mode == "-test")
		{
			Test myTester(std::cout);
			myTester.runTests();
		}
	}
	}


}
