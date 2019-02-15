/**
*	@file Sorts.hpp
* 	@author Levi Clark
*	@date 2015.20.15
*
*/


#include "Sorts.h"
#include<random>
#include<ctime>
#include<chrono>
#include<cassert>
#include<functional>

#include<iostream>


using namespace std;

template<typename T>
void Sorts<T>:: bubbleSort(T arr[], int size)
{
	T temp;
		
	for(int i = 0; i<size-1; i++)
	{
		for(int j = 0; j<size-1; j++)
		{
			if(arr[j]> arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	assert(Sorts<T>:: isSorted(arr, size));

}

template<typename T>
void Sorts<T>:: bogoSort(T arr[], int size)
{
	std:: default_random_engine generator(time(nullptr));
	
	while(!isSorted(arr, size))
	{
		shuffle(arr, size, generator);
	}
	assert(Sorts<T>:: isSorted(arr, size));

}

template<typename T>
void Sorts<T>:: insertionSort(T arr[], int size)
{
	int j;
	int temp;
	
	for(int i = 0; i<size; i++)
	{
		j = i;
		while(j>0 && arr[j]<arr[j-1])
		{
			temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
	}
	assert(Sorts<T>:: isSorted(arr, size));
}

template<typename T>
void Sorts<T>:: selectionSort(T arr[], int size)
{

	int j;
	int k;
	T temp;
	
	for(int i = 0; i<size-1; i++)
	{
		k = i;
		for(j = i+1; j<size; j++)
		{
			if(arr[k]>arr[j])
			{
				k = j;
			}
		}
		if(k!=i)
		{
			temp = arr[k];
			arr[k] = arr[i];
			arr[i] = temp;
		}	
	
	}
	assert(Sorts<T>::isSorted(arr, size));

}

template<typename T>
bool Sorts<T>:: isSorted(T arr[], int size)
{
	for(int i = 0; i<size-1; i++)
	{
		if(arr[i] > arr[i+1])
		{
			return false;
		}
	}
	return true;

}
template<typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator)
{
	int i;
	int temp;
	int rand;
	
	std:: uniform_int_distribution<int> distribution(0, size-1);
	
	for(i=0; i<size-1; i++)
	{
		rand = distribution(generator);
		temp = arr[i];
		arr[i] = arr[rand];
		arr[rand] = temp;
	}
	

}

    
template<typename T>
int* Sorts<T>::createTestArray(int size, int min, int max)
{

	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(min, max);

	int* randomArray = new int[size];
	for(int i = 0; i<size; i++)
	{
		randomArray[i] = distribution(generator);
	}
	return randomArray;	
	delete randomArray;
	


}

template<typename T>
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
//Declarations-------------------------------
std::chrono::system_clock::time_point start;
std::chrono::system_clock::time_point end;
std::chrono::duration<double> elapsed;

start = std::chrono::system_clock::now();

sort(arr, size);

end = std::chrono::system_clock::now();


elapsed = (end-start);

return(elapsed.count());


	
	
}










































