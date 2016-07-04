#include <time.h>
#include <iostream>
#include <chrono>
#include "declarations.h"

using namespace std;

void selectionsort(int array[], int size){
	//Record initial time
	auto start = std::chrono::high_resolution_clock::now();
	//Run selection sort
	selection(array,size);
	//Record end time
	auto finish = std::chrono::high_resolution_clock::now();
	//Print time taken to sort
	cout << "SelectionSort time: " << std::chrono::duration_cast<std::chrono::duration<double>>(finish-start).count() << " seconds" << endl;
}

void selection(int array[], int size){
	//Loop through array backwards
	for(int i = size-1; i > 0; i--){
		//Variable to track largest element
		int first = 0;
		//Loop from index 1 to i
		for(int j = 1; j <= i; j++){
			//If current element greater than first, swap them
			if(array[j] > array[first])
				first = j;
		}
		//Swap element into correct place
		swap(array[first],array[i]);
	}
}