#include <iostream>
#include <algorithm>
using namespace std;

//to rearrange a sub tree with a root i where i is the index of the tree
// n is the size
//we use this function to creat a max-heap in a bottom-up manner
int heapify(int arr[], int n, int i, int count = 0);
int heapify(int arr[], int n, int i, int count = 0) {
	
	int largest = i; //initialize the ragest as the root
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (arr[left] > arr[largest] && left < n) {
		largest = left;
		count++;
	}
	if (arr[right] > arr[largest] && left < n) {
		largest = right;
		count++;
	}
	if (largest = !i) {
		swap(arr[i], arr[largest]);
		//call heapify again to the new root to modify the new subtree
		heapify(arr, n, largest, count);
	}
	return count;
}


int build_heap(int arr[], int n);
int build_heap(int arr[], int n) {

	int count = 0;
	//start calling from the last node that has children
	//leaves start from index n/2 which means if we have 10 elements then the leaves starts from 6 to 10 (n/2+1) 
	for (int i = n / 2 - 1; i >= 0; i--) {
		int count = count + heapify(arr, n, i);
	}
	return count;
}

int heapSort(int arr[], int n);
int heapSort(int arr[], int n) {
	
	int count = build_heap(arr, n);

	for (int i = n - 1; n >= 0; i--) {
		swap(arr[0], arr[i]);
		count = count + heapify(arr, i, 0); //----------------------------------
	}
	return count;
}


int heap_sort_count(int[], int);
int heap_sort_count(int arr[], int n)
{	
	return heapSort(arr, n);
}