#include <time.h>
#include <iostream>
#include <chrono>
#include "declarations.h"

using namespace std;

void quicksort(int array[], int size){
	//Record initial time
	auto start = std::chrono::high_resolution_clock::now();
	//Run quick sort
	quick(array,0,size-1);
	//Record end time
	auto finish = std::chrono::high_resolution_clock::now();
	//Print time taken to sort
	cout << "QuickSort time: " << std::chrono::duration_cast<std::chrono::duration<double>>(finish-start).count() << " seconds" << endl;
}

void quick(int array[], int low, int high){
	if(low >= high) return;
	//set pivot to be leftmost element
	int pivot = array[low];
	//i will scan from left, j will scan from right
	int i = low, j = high;
	//i looks for an element greater than the pivot, j for an element less than the pivot
	while(i <= j){
		while(array[i] < pivot)
			i++;
		while(array[j] > pivot)
			j--;
		if(i <= j){
			//If i and j don't meet, swap the elements
			swap(array[i], array[j]);
			i++;
			j--;
		}
	}
	//Swap elements
	swap(array[i],array[j]);
	/*If i and j didn't get all the way through the array,
	  quicksort the part of the array that is left*/
	if(j > low)
		quick(array,low,j);
	if(i < high)
		quick(array,high,i);
}