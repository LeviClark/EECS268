/**
*	@file SortDriver.cpp
* 	@author Levi Clark
*	@date 2015.26.15
*
*/

#include "SortDriver.h"

using namespace std;

void SortDriver::run(int argc, char** argv)
{
	string sortType = argv[2];
	string inputFileName = argv[3];
	string outputFileName = argv[4];
	
	//tests arguments
	if(areParametersValid(sortType, inputFileName))
	{
		ifstream input(inputFileName);
		
		int amount = getFileCount(input);
		
		int* arr = createArray(input, amount);
		
		double time = 0.0;
		double time1 = 0.0;
		double time2 = 0.0;
		double time3 = 0.0;
		double time4 = 0.0;
		double time5 = 0.0;
		//times based off of sortType
		if(sortType=="-bubble")
		{
			time = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, arr, amount);
		}
		else if(sortType=="-selection")
		{
			time = Sorts<int>::sortTimer(Sorts<int>::selectionSort, arr, amount);
		}
		else if(sortType=="-insertion")
		{
			time = Sorts<int>::sortTimer(Sorts<int>::insertionSort, arr, amount);
		}
		else if(sortType=="-merge")
		{
			time = Sorts<int>::sortTimer(Sorts<int>::mergeSort, arr, amount);
		}
		else if(sortType=="-quick")
		{
			time = Sorts<int>::sortTimer(Sorts<int>::quickSort, arr, amount);
		}
		else if(sortType == "-quick3")
		{	
			time = Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian, arr, amount);
		}
		//if user wants to use all sort types.
		else if(sortType =="-all")
		{
			int* temp = new int[amount];
			
			copyArray(arr,temp, amount);
			time = Sorts<int>::sortTimer(Sorts<int>::bubbleSort,temp, amount);
			delete[] temp;
			temp = new int[amount];
			
			copyArray(arr,temp,amount);
			time1 = Sorts<int>::sortTimer(Sorts<int>::selectionSort,temp, amount);
			delete[] temp;
			temp = new int[amount];
			
			copyArray(arr,temp,amount);
			time2 = Sorts<int>::sortTimer(Sorts<int>::insertionSort,temp, amount);
			delete[] temp;
			temp = new int[amount];
			
			copyArray(arr,temp,amount);
			time3 = Sorts<int>::sortTimer(Sorts<int>::mergeSort,temp, amount);
			delete[] temp;
			temp = new int[amount];
			
			copyArray(arr,temp,amount);
			time4 = Sorts<int>::sortTimer(Sorts<int>::quickSort,temp, amount);
			delete[] temp;
			temp = new int[amount];
			
			copyArray(arr,temp,amount);
			time5 = Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian,temp, amount);
			delete[] temp;
			temp = nullptr;
		
		}
		//entered wrong flag.
		else
		{
			cout<<"Sorry, invalid flag \n";
		}
		
		cout<<"Sorts finished. Results stored in file: "<<outputFileName<< endl;
		
		ofstream output(outputFileName);
		//time sort takes to complete.
		if(sortType == "-bubble")
		{
			output<<"bubble "<< amount << " "<< time<<endl;
		}
		else if(sortType == "-selection")
		{
			output<<"selection "<< amount << " " << time<<endl;
		}
		else if(sortType == "-insertion")
		{
			output<<"insertion "<< amount << " " << time<<endl;
		}
		else if(sortType == "-merge")
		{
			output<<"merge "<< amount << " " << time<<endl;
		}
		else if(sortType == "-quick")
		{
			output<<"quick "<< amount << " " << time<<endl;
		}
		else if(sortType == "-quick3")
		{
			output<<"quick3 "<< amount << " " << time<<endl;
		}
		else if(sortType =="-all")
		{
			output<<"bubble "<< amount<<" " <<time<<endl;
			output<<"selection "<< amount<<" " <<time1<<endl;
			output<<"insertion "<< amount<<" " <<time2<<endl;
			output<<"merge "<< amount<<" " <<time3<<endl;
			output<<"quick "<< amount<<" " <<time4<<endl;
			output<<"quick3 "<< amount<<" " <<time5<<endl;
			
		}
		input.close();
		output.close();
		delete[] arr;
		arr = nullptr;
		
		
	}
	else
	{
		printHelpMenu();
	}
	
}	

void SortDriver::printHelpMenu()
{
	std::cout << "\nSorting is done one of the following ways:\n\n"
			<< "./prog -sort -bubble inputFile outputFile\n"
			<< "./prog -sort -selection inputFile outputFile\n"
			<< "./prog -sort -insertion inputFile outputFile\n"
			<< "./prog -sort -quick inputFile outputFile\n"
			<< "./prog -sort -quick3 inputFile outputFile\n"
			<< "./prog -sort -merge inputFile outputFile\n"
			<< "./prog -sort -all inputFile outputFile\n"
			<< "Option explainations:\n"
			<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
			<< "\t-selection to time selection sort and store all timing results in outputFile\n"
			<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
			<< "\t-quick to time quick sort and store all timing results in outputFile\n"
			<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
			<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
			<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
			<< "\tinputFile must be file created by a NumberFileGenerator\n"
			<< "\toutputFile must be to a valid path. It will hold the timing results\n";

}	

bool SortDriver::isFileAccessible(std::string fileName)
{
	ifstream file(fileName);
	bool isFileGood = file.good();
	file.close();
	
	return isFileGood;
}	

bool SortDriver::isSortValid(std::string sortParameter)
{
	if(sortParameter=="-bubble")
	{
		return true;
	}
	else if(sortParameter=="-selection")
	{
		return true;
	}
	else if(sortParameter=="-insertion")
	{
		return true;
	}
	else if(sortParameter=="-merge")
	{
		return true;
	}
	else if(sortParameter=="-quick")
	{
		return true;
	}
	else if(sortParameter == "-quick3")
	{
		return true;
	}
	else
	{
		return false;
	}
	
	
}

bool SortDriver::areParametersValid(std::string sortName, std:: string inputFileName)
{
	return isSortValid(sortName)&&isFileAccessible(inputFileName);
}

int SortDriver::getFileCount(std::ifstream& inputFile)
{
	int count = 0;
	
	inputFile>> count;
	return count;
}

int* SortDriver::createArray(std::ifstream& inputFile, int size)
{
	int* arr = new int[size];
	
	for(int i = 0; i < size; i++)
	{
		inputFile >> arr[i];
	}
	return arr;
}

void SortDriver:: copyArray(int original[], int copy[], int size)
{
	for(int i = 0; i < size; i++)
	{
		copy[i] = original [i];
	}
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
