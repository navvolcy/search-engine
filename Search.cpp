#include "Search.h"
#include<random>
#include <iostream>

using namespace std;


// initializes a Search Object with an internal integer array of the specified size
Search::Search(int size)
{
	myInt = new int[size];
	this->size = size;
}
//destroys all data allocated by the constructor
Search::~Search()
{
	delete[] myInt;
}
//Function to initialize the array with sorted random numbers
void Search::InitSortedArray()
{
	//call srand(0) before initializing to get the same numbers each time
	srand(0);
	//insert a number a bit larger than the previous number.
	myInt[0] = rand() % 20;
	for (int i = 1; i < size; i++)
	{
		myInt[i] = myInt[i - 1] + rand() % 20;
	}

}
// returns true if target is found in the object's data array
bool Search::SequentialSearch(int target)
{
	for (int i = 0; i < size; i++)
	{

		if (myInt[i] == target)
		{

			return true;
		}
	}
	return false;
}
// returns true if target is found in the object's data array (recursive)
bool Search::RecursiveBinarySearch(int target)
{

	return RecursiveBinarySearchHelper(0, size - 1, target);
}
// returns true if target is found in the object's data array
bool Search::IterativeBinarySearch(int target)
{

	int low = 0;
	int high = size - 1;


	while (low <= high)
	{
		int Mid = (high + low) / 2;
		if (myInt[Mid] == target)
		{
			return true;
		}
		if (myInt[Mid] < target)
		{
			low = Mid + 1;
		}
		if (myInt[Mid] > target)
		{
			high = Mid - 1;
		}

		//cout << low << " " << Mid << " " << high << " "<< target << endl;

	}
	return false;
}
// returns a pointer to the array of integers
int* Search::GetDataArray()
{
	return myInt;
}
//called by RecursiveBinarySearch()
bool Search::RecursiveBinarySearchHelper(int lowIndex, int highIndex, int target) const
{
	RecursionCounter rcTmp;	// used for unit testing DO NOT REMOVE



	int Mid = (highIndex + lowIndex) / 2;




	if (lowIndex > highIndex)
	{
		if (myInt[Mid] == target) return true;
		return false;
	}
	if (myInt[Mid] == target)
	{
		return true;
	}
	if (myInt[Mid] < target)
	{
		return RecursiveBinarySearchHelper(Mid + 1, highIndex, target);
	}
	if (myInt[Mid] > target)
	{
		return RecursiveBinarySearchHelper(lowIndex, Mid - 1, target);
	}




}

// add more code here
