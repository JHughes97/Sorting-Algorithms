#include <time.h>
#include <iostream>
#include <chrono>
#include "declarations.h"

using namespace std;

void mergesort(int array[], int size){
	//Record initial time
	auto start = std::chrono::high_resolution_clock::now();
	//Run merge sort
	recmerge(array,0,size);
	//Record end time
	auto finish = std::chrono::high_resolution_clock::now();
	//Print time taken to sort
	cout << "MergeSort time: " << std::chrono::duration_cast<std::chrono::duration<double>>(finish-start).count() << " seconds" << endl;
}

void recmerge(int array[], int lower, int upper){
	//For small number of elements, use insertion sort
	if((upper-lower) > 8){
		insertion(array,upper-lower);
	}else{
		//mid equals halfway point
		int mid = (lower+upper)/2;
		//Perform merge sort on each half
		recmerge(array,lower,mid);
		recmerge(array,mid+1,upper);
		//Merge array together
		merge(array,lower,mid+1,upper);
	}
}

void merge(int array[], int left, int right, int upper){
	int i = 0;		//i tracks index in workspace
	int lower = left;	//lowerbound of array
	int mid = right-1;	//midpoint
	int n = upper-lower+1;	//number of elements

	//workspace array used for sorting elements
	int* workspace = new int[n];
	
	//Put lower of two sides in workspace
	while(left <= mid && right <= upper){
		if(array[left] > array[right])
			workspace[i++] = array[left++];
		else
			workspace[i++] = array[right++];
	}

	//Put left over elements in workspace
	while(left <= mid)
		workspace[i++] = array[left++];

	while(right <= upper)
		workspace[i++] = array[right++];

	//Put sorted elements in array
	for(i = 0; i < n; i++)
		array[lower+i] = workspace[i];
}