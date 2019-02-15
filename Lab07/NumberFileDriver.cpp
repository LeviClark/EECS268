/**
*	@file NumberFileDriver.cpp
* 	@author Levi Clark
*	@date 2015.26.15
*
*/


#include "NumberFileDriver.h"
#include <iostream>

using namespace std;
void NumberFileDriver:: run(int argc, char** argv)
{
	string flag = argv[2];
	string fileName = argv[3];
	int amount = atoi(argv[4]);
	int value = 0;
	int min = 0;
	int max = 0;
	
	if(argc ==6)
	{
		value = atoi(argv[5]);
	}
	if(argc == 7)
	{
		min = atoi(argv[5]);
		max = atoi(argv[6]);
	}
	
	if(isValidOption(flag))
	{
		if(flag == "-a")
		{
			NumberFileGenerator::ascending(fileName, amount);
		}
		else if(flag == "-d")
		{
			NumberFileGenerator::descending(fileName, amount);
		}
		else if(flag == "-r")
		{
			NumberFileGenerator::random(fileName, amount, min, max);
		}
		else if(flag == "-s")
		{
			NumberFileGenerator::singleValue(fileName, amount, value);
		}
	}
	
}

void NumberFileDriver:: printHelpMenu()
{
	std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
			<< "./prog -create -a filename amount\n"
			<< "./prog -create -d filename amount\n"
			<< "./prog -create -s filename amount value\n"
			<< "./prog -create -r filename amount min max\n"
			<< "Option explainations:\n"
			<< "\t-a for ascending\n"
			<< "\t-d for descending\n"
			<< "\t-s for a single value\n"
			<< "\t-r for random values\n"
			<< "\tfilename is the ouput file name\n"
			<< "\tamount is the amount of random numbers to place in the file\n"
			<< "\tvalue is the single number that will be written to file in -s mode\n"
			<< "\tmin is the low end of the range of random numbers\n"
			<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";


}

bool NumberFileDriver::isValidOption(std::string option)
{
	if(option == "-a" || "-d" || "-r" || "-s")
	{
		return true;
	}
	else
	{
		NumberFileDriver(printHelpMenu());
		return false;
	}
		

}





