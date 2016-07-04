#include <time.h>
#include <iostream>
#include <chrono>
#include "declarations.h"

using namespace std;

void bubblesort(int array[], int size){
	//Record initial time
	auto start = std::chrono::high_resolution_clock::now();
	//Run bubble sort
	bubble(array,size);
	//Record end time
	auto finish = std::chrono::high_resolution_clock::now();
	//Print time taken to sort
	cout << "BubbleSort time: " << std::chrono::duration_cast<std::chrono::duration<double>>(finish-start).count() << " seconds" << endl;
}

void bubble(int array[], int size){
	//Loop from end of array to front
	for(int i = size-1; i > 0; i--){
		//Loop from start of array to i
		for(int j = 0; j < i; j++){
			//If element is bigger than element to it's right, swap them
			if(array[j]>array[j+1])
				swap(array[j],array[j+1]);
		}
	}
}