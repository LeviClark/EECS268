/**
*	@file Sorts.h
* 	@author Levi Clark
*	@date 2015.26.15
*
*/


#ifndef SORTS_H
#define SORTS_H
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
	
	//uses insertion sort discussed in class
	static void insertionSort(T arr[], int size);
	//not used, but in test file. randomly prints until in order.
	static void bogoSort(T arr[], int size);
	//seperates array into individual pieces then merges together after sorting
	static void mergeSort(T arr[], int size);
	//another recursive sort discussed in class
	static void quickSort(T arr[], int size);
	//uses quicksort but we find the median point first
	static void quickSortWithMedian(T arr[], int size);
	
	//uses selection sort discussed in class
	static void selectionSort(T arr[], int size);
	
	//determines if array is sorted or not
	static bool isSorted(T arr[], int size);
	//not used in this lab
	static int* createTestArray(int size, int min, int max);
	//uses bubble sort discussed in class
	static void bubbleSort(T arr[], int size);
	
	
	
	//times how long the methods take to run
	static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);
	
	private: 
	//saves time and swaps for me
	static void swapper(T arr[], int first, int second);
	//merges and sorts the array that mergesort broke up
	static void merge(T* a1, T* a2, int size1, int size2);
	//sorts the array by partitioning it, quicksorts left of pivot, then right of pivot.
	static void quickSortRec(T arr[], int first, int last, bool median);
	//puts the medina value of the array in the last position
	static void setMedianPivot(T arr[], int first, int last);
	//used by quicksort. partitions the array by chosing a pivot based on median flag.
	static int partition(T arrr[], int first, int last, bool median);
	//shuffles array randomly
	static void shuffle(T arr[], int size, std::default_random_engine& generator);
	
};
#include "Sorts.hpp"
#endif

//double time = sortTimer(Sorts<int>:bogoSort, arr, size);
























