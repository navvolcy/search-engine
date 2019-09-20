#ifndef __SEARCH__
#define __SEARCH__
#include "RecursionCounter.h"


using namespace std;

class Search
{
public:
	
	

	
	Search(int size);
	
	~Search();

	
	void InitSortedArray();
	
	bool SequentialSearch(int target);

	bool RecursiveBinarySearch(int target);

	bool IterativeBinarySearch(int target);

	int* GetDataArray();



private:
	bool RecursiveBinarySearchHelper(int lowIndex, int highIndex, int target) const;
	
	int* myInt;
	int size;
};


#endif
