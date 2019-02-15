/**
*	@file NumberFileDriver.h
* 	@author Levi Clark
*	@date 2015.26.15
*
*/


#include <iostream>
#ifndef NUMBERFILEDRIVER_H
#define NUMBERFILEDRIVER_H
#include "NumberFileGenerator.h"



class NumberFileDriver
{
	public:
	//creates a number file with the correct specs if the arguments are valid.
	static void run(int argc, char** argv);
	//prints help menu if the wrong input is entered
	static void printHelpMenu();
	
	private:
	//tests to see if the options for sorts are correct.
	static bool isValidOption(std::string option);



};
#endif
