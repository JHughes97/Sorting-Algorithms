#include <stdlib.h>
#include <time.h>
#include "declarations.h"

void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

void randomize(int array[], int size){
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		array[i] = rand() % 1000000 +1;
	}
}

void print(int array[], int size){
	for(int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
	cout << endl;
}