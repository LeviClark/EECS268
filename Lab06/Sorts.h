/**
*	@file Sorts.h
* 	@author Levi Clark
*	@date 2015.20.15
*
*/


#ifndef STACK_H
#define STACK_H
#include<random>
#include<ctime>
#include<iostream>
#include<chrono>
#include<ctime>
#include<cassert>
#include<functional>

using namespace std;
template<typename T>
class Sorts
{
	public:
	//uses bubble sort given in class
	static void bubbleSort(T arr[], int size);
	
	//dont ever use this for big numbers. prints the numbers in random orders until its in order.
	static void bogoSort(T arr[], int size);
	
	//uses insertion sort discussed in class
	static void insertionSort(T arr[], int size);
	
	//uses selection sort discussed in class
	static void selectionSort(T arr[], int size);
	
	//determines if array is sorted or not
	static bool isSorted(T arr[], int size);
	
	//shuffles the array into random positions
	static void shuffle(T arr[], int size, std::default_random_engine& generator);
	
	//creates our array with the given input(size, and bounds of the min and max)
	static int* createTestArray(int size, int min, int max);
	
	//times how long the methods take to run
	static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);

};
#include "Sorts.hpp"
#endif

//double time = sortTimer(Sorts<int>:bogoSort, arr, size);
