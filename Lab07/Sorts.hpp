/**
*	@file Sorts.hpp
* 	@author Levi Clark
*	@date 2015.26.15
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

template<typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
	//basically splits array into individual pieces
	if(size>1)
	{
		int middle = size/2;
		//int right = size-left;
		T* a1 = arr+ 0;
		T* a2 = arr + middle;
		
		mergeSort(a1, middle);
		mergeSort(a2, size-middle);
		//array is split at this point and merge sorts and puts back together
		merge(a1, a2, middle, size-middle);
	}
	
	assert(Sorts<T>::isSorted(arr, size));

}

template<typename T>
void Sorts<T>:: merge(T* a1, T* a2, int size1, int size2) 
{
	//this puts array back together in order
	
	//temp array
	T* arr = new int[size1+size2];
	int a1First = 0;
	int a2First = 0;
	int a1Last = size1-1;
	int a2Last = size2-1;
	int index = 0;
	
	while(a1First<=a1Last && a2First<=a2Last)
	{
		if(a1[a1First]<=a2[a2First])
		{
			arr[index] = a1[a1First];
			a1First++;
		}
		else
		{
			arr[index] = a2[a2First];
			a2First++;
		}
		index++;
	
	}
	
	while(a1First <= a1Last)
	{
		arr[index] = a1[a1First];
		a1First++;
		index++;
	}
	
	while(a2First <= a2Last)
	{
		arr[index] = a2[a2First];
		a2First++;
		index++;
	}
	
	for(index = 0; index <= size1+size2-1; index++)
	{
		a1[index] = arr[index];
	}
	delete[] arr;
	arr = nullptr;
	
}

template<typename T>
void Sorts<T>:: quickSort(T arr[], int size)
{
	//used 0, size-1 instead of creating variables and using those.
	quickSortRec(arr,0,size-1, false);
	assert(Sorts<T>:: isSorted(arr, size));
}

template<typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)
{
	//used 0, size-1 instead of creating variables and using those.
	quickSortRec(arr,0,size-1, true);
	assert(Sorts<T>:: isSorted(arr, size));
	

}

template<typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
	if(last-first ==1)
	{
		if(arr[first] > arr[last])
		{
			//swaps using our swapper method
			swapper(arr, first, last);
		}
	}
	else if(last-first ==0)
	{
		return;
	}
	else
	{
		int middle = (last - first +1)/2;
		
		if(arr[first] > arr[middle] && arr[first] > arr[last])
		{
			swapper(arr, first, last);
		}
		else
		{
			if(arr[middle] > arr[first] && arr[middle] > arr[last])
			{
				swapper(arr, middle, last);
			}
		}
	}
}

template<typename T>
void Sorts<T>:: quickSortRec(T arr[], int first, int last, bool median)
{
	if(first<last)
	{
		int pivot = partition(arr, first, last, median);
			
		quickSortRec(arr, first, pivot-1, median);
		
		quickSortRec(arr, pivot+1, last, median);
		
	}
}

template<typename T>
int Sorts<T>:: partition(T arr[], int first, int last, bool median)
{
	if(median)
	{
		setMedianPivot(arr,first,last);
	}
	
	int pivot = last;
	int leftIndex = first;
	int rightIndex = last-1;
	bool finished = false;
	
	while(!finished)
	{
		while(arr[leftIndex] < arr[pivot])
		{
			leftIndex++;
		}
		while(arr[rightIndex] > arr[pivot])
		{
			rightIndex--;
		}
		
		if(leftIndex < rightIndex)
		{
			swapper(arr, leftIndex, rightIndex);
			leftIndex++;
			rightIndex--;
		}
		else
		{
			finished = true;
		}
	}
	
	swapper(arr, pivot, leftIndex);
	pivot = leftIndex;
	return pivot;

}

//created to get rid of some steps for the new sort types.
template <typename T>
void Sorts<T>::swapper(T arr[], int first, int second)
{
	T temp = arr[first];
	
	arr[first] = arr[second];
	arr[second] = temp;
}











































