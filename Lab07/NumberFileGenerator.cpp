/**
*	@file NumberFileGenerator.cpp
* 	@author Levi Clark
*	@date 2015.26.15
*
*/


#include "NumberFileGenerator.h"
#include <iostream>

using namespace std;
void NumberFileGenerator:: ascending(string fileName, int amount)
{
	
	ofstream output(fileName);
	
	output << amount <<"\n";
	
	for(int i = 1; i < amount; i++)
	{
		output << i << "\n";
	}
	output.close();
}

void NumberFileGenerator:: descending(string fileName, int amount)
{
	ofstream output(fileName);
	
	output << amount <<"\n";
	
	for(int i = amount; i > 1; i--)
	{
		output << i << "\n";
	}
	output.close();
}

void NumberFileGenerator:: random(string fileName, int amount, int min, int max)
{
	ofstream output(fileName);
	
	output << amount <<"\n";
	
	default_random_engine generator(time(nullptr));	
	
	uniform_int_distribution<int>distribution(min, max);
	
	for(int i = 0; i< amount-1; i++)
	{
		output << distribution(generator) << "\n";
	}
	output.close();
}	

void NumberFileGenerator:: singleValue(string fileName, int amount, int value)
{
	ofstream output(fileName);
	
	output << amount <<"\n";
	
	for(int i = 0; i < amount-1; i++)
	{
		output << value << "\n";
	}
	
	output.close();
}		

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
