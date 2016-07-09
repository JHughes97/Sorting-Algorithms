#include <time.h>
#include <iostream>
#include <chrono>
#include "declarations.h"

using namespace std;

void shellsort(int array[], int size){
	//Record initial time
	auto start = std::chrono::high_resolution_clock::now();
	//Run shell sort
	shell(array,size);
	//Record end time
	auto finish = std::chrono::high_resolution_clock::now();
	//Print time taken to sort
	cout << "ShellSort time: " << std::chrono::duration_cast<std::chrono::duration<double>>(finish-start).count() << " seconds" << endl;
}

/**
Shell's sort using Shell's gap sequence:
n/2,n/4,n/8,...
*/
void shell(int array[], int size){
	//Loop through gap sequence from n/2 ... 1
	for(int gap = size/2; gap > 0; gap /= 2){
		//loop through array from current gap to end
		for(int i = gap; i < size; i++){
			//temp variable equals current element
			int temp = array[i];
			int j;
			/*Loop through array from i back to gap while array[j-gap]
			  greater than temp element in gap-sized increments*/
			for(j = i; j >= gap && array[j-gap] > temp; j -= gap){
				//Shift elements forward
				array[j] = array[j-gap];
			}
			//Insert temp element
			array[j] = temp;
		}
	}
}
