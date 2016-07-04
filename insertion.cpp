#include <time.h>
#include <iostream>
#include <chrono>
#include "declarations.h"

using namespace std;

void insertionsort(int array[], int size){
	//Record initial time
	auto start = std::chrono::high_resolution_clock::now();
	//Run insertion sort
	insertion(array,size);
	//Record end time
	auto finish = std::chrono::high_resolution_clock::now();
	//Print time taken to sort
	cout << "InsertionSort time: " << std::chrono::duration_cast<std::chrono::duration<double>>(finish-start).count() << " seconds" << endl;
}

void insertion(int array[], int size){
	int j;
	//Loop from index 1 to end of array
	for(int i = 1; i < size; i++){
		//Set variable equal to current element
		int key = array[i];
		//Loop from element at i-1 backwards to start of array while current element is greater than key
		for( j = i-1; j >= 0 && array[j] > key; j--){
			//Shift element forward
			array[j+1] = array[j];
		}
		//Insert key element
		array[j+1] = key;
	}
}