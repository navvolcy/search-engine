
#include <iostream>
#include <random>
#include "Search.h"

#include "Timer.h"
using namespace std;

// used for Recursion Unit Testing. DO NOT REMOVE
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

int main() {
	int size = 1000;
	cout << " Creating a sorted array of " << size << endl;
	Search s(size);
	s.InitSortedArray();
	cout << "Finished creating a sorted array of " << size << endl << endl;
	
	cout << "Searching for a number at the start of the array" << endl;
	Timer ti;
	ti.Start();
	bool found = s.SequentialSearch(s.GetDataArray()[0]);
	ti.End();
	
	cout << "s.sequencialSearch() returned " << found << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	ti.Start();
	bool seen = s.IterativeBinarySearch(s.GetDataArray()[0]);
	ti.End();
	cout << "s.IterativeBinarySearch() returned " << seen << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	ti.Start();
	bool find = s.RecursiveBinarySearch(s.GetDataArray()[0]);
	ti.End();
	cout << "s.RecursiveBinarySearch() returned " << find << " in " << ti.DurationInNanoSeconds() << " ns " << endl;
