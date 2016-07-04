#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "declarations.h"

using namespace std;

int main(){
	//Create int array and fill with random ints
	const int numElements = 50000;
	int array[numElements];
	randomize(array, numElements);

	//Run bubble sort on array and then refill with random ints
	bubblesort(array, numElements);
	randomize(array, numElements);

	//Run selection sort on array and then refill with random ints
	selectionsort(array, numElements);
	randomize(array, numElements);

	//Run shell sort on array and then refill with random ints
	shellsort(array, numElements);
	randomize(array, numElements);

	//Run heap sort on array and then refill with random ints
	heapsort(array, numElements);
	randomize(array, numElements);

	//Run insertion sort on array and then refill with random ints
	insertionsort(array, numElements);
	randomize(array, numElements);

	//Run merge sort on array and then refill with random ints
	mergesort(array, numElements);
	randomize(array, numElements);
	
	//Run quick sort on array and then refill with random ints
	quicksort(array, numElements);
	randomize(array, numElements);

	//print(array, numElements);
}