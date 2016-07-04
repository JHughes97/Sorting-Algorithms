#include <time.h>
#include <iostream>
#include <chrono>
#include "declarations.h"

using namespace std;

void heapsort(int array[], int size){
	//Record initial time
	auto start = std::chrono::high_resolution_clock::now();
	
	//Place array in heap order where largest element is root
	heap(array, size);

	/*Put array in heap order where heap is decremented in size
	  so largest value stays in place*/
	int last = size-1;
	while(last > 0){
		swap(array[0], array[last]);
		siftDown(array,0,last-1);
		last--;
	}

	//Record end time
	auto finish = std::chrono::high_resolution_clock::now();
	//Print time taken to sort
	cout << "HeapSort time: " << std::chrono::duration_cast<std::chrono::duration<double>>(finish-start).count() << " seconds" << endl;
}

void heap(int array[], int size){
	//First contains index of last parent node
	int first = (size-2)/2;
	while(first >= 0){
		//Sift down so that all nodes are in heap order
		siftDown(array,first,size-1);
		first--;
	}
}

void siftDown(int array[], int first, int last){
	int root = first;
	//Loop while the root has a child
	while((root*2+1) <= last){
		int child = root*2+1; //root*2+1 points to the left child
		if(child+1 <= last && array[child] < array[child+1])
			child = child+1;  //points to the right child
		if(array[root] < array[child]){
			swap(array[root], array[child]);
			root = child;  //continue sifting from child
		}else{
			return;
		}
	}
}