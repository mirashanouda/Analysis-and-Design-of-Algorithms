#include <iostream>
#include <algorithm>
using namespace std;

//to rearrange a sub tree with a root i where i is the index of the tree
// n is the size
//we use this function to creat a max-heap in a bottom-up manner
void heapify(int arr[], int n, int i);
void heapify(int arr[], int n, int i) {
	
	int largest = i; //initialize the ragest as the root
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (arr[left] > arr[largest] && left < n) {
		largest = left;
	}
	if (arr[right] > arr[largest] && left < n) {
		largest = right;
	}
	if (largest = !i) {
		swap(arr[i], arr[largest]);
	}
	//call heapify again to the new root to modify the new subtree
	heapify(arr, n, largest);
}


void build_heap(int arr[], int n);
void build_heap(int arr[], int n) {
	//start calling from the last node that has children
	//leaves start from index n/2 which means if we have 10 elements then the leaves starts from 6 to 10 (n/2+1) 
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}
}

void heapSort(int arr[], int n);
void heapSort(int arr[], int n) {
	
	build_heap(arr, n);

	for (int i = n - 1; n >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}


int heap_sort_count(int[], int);
int heap_sort_count(int arr[], int n)
{	


}