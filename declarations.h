#ifndef declarations
#define declarations

//Bubble Sort functions
void bubblesort(int array[], int size);
void bubble(int array[], int size);

//Selection Sort functions
void selectionsort(int array[], int size);
void selection(int array[], int size);

//Shell sort functions
void shellsort(int array[], int size);
void shell(int array[], int size);

//Heap sort functions
void heapsort(int array[], int size);
void heap(int array[], int size);
void siftDown(int array[], int first, int last);

//Insertion Sort functions
void insertionsort(int array[], int size);
void insertion(int array[], int size);

//Merge Sort functions
void mergesort(int array[], int size);
void recmerge(int array[], int lower, int upper);
void merge(int array[], int left, int right, int upper);

//Quick Sort functions
void quicksort(int array[], int size);
void quick(int array[], int low, int high);

//Array functions
void swap(int &x, int &y);
void randomize(int array[], int size);
void print(int array[], int size);

//Include the files containing functions
#include "bubble.cpp"
#include "selection.cpp"
#include "shell.cpp"
#include "heap.cpp"
#include "insertion.cpp"
#include "merge.cpp"
#include "quick.cpp"
#include "arrayFunctions.cpp"
#endif