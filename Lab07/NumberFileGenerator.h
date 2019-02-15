/**
*	@file NumberFileGenerator.h
* 	@author Levi Clark
*	@date 2015.26.15
*
*/


#ifndef NUMBERFILEGENERATOR_H
#define NUMBERFILEGENERATOR_H

#include <random>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

class NumberFileGenerator
{
	public:
	//prints it in ascending order(least to greatest).
	static void ascending(string fileName, int amount);
	//prints it in descending order(greatest to least).
	static void descending(string fileName, int amount);
	//prints array with given size and populates it with random numbers between min and max.
	static void random(string fileName, int amount, int min, int max);
	//prints a single value in array with "amount" size.(ex: array size 10 with only the number 5 in it)
	static void singleValue(string fileName, int amount, int value);

};
#endif
