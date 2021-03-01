#include <iostream>
#include <algorithm>
using namespace std;

//All functions:
int heapify(int arr[], int n, int i, int count = 0);
int build_heap(int arr[], int n);
int heapSort(int arr[], int n);
int heap_sort_count(int[], int);
int bubble_sort_count(int* arr, int n);
int insertion_sort_count(int* arr, int n);
int selectionSort_count(int arr[], int n);


//to rearrange a sub tree with a root i where i is the index of the tree
// n is the size
//we use this function to creat a max-heap in a bottom-up manner
int heapify(int arr[], int n, int i, int count) {
	
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


int build_heap(int arr[], int n) {

	int count = 0;
	//start calling from the last node that has children
	//leaves start from index n/2 which means if we have 10 elements then the leaves starts from 6 to 10 (n/2+1) 
	for (int i = n / 2 - 1; i >= 0; i--) {
		count = count + heapify(arr, n, i);
	}
	return count;
}


int heapSort(int arr[], int n) {
	
	int count = build_heap(arr, n);

	for (int i = n - 1; n >= 0; i--) {
		swap(arr[0], arr[i]);
		count = count + heapify(arr, i, 0); //----------------------------------
	}
	return count;
}


int heap_sort_count(int arr[], int n)
{	
	return heapSort(arr, n);
}

int bubble_sort_count(int* arr, int n) {

	int count_bubble = 0;
	for (int i = 0; i < n - 1; i++) {//the last element is already in place
		for (int j = 0; j < n - i - 1; j++) {
			count_bubble++; //counts the number of comparisions 
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	return count_bubble;
}

int insertion_sort_count(int* arr, int n) {

	int count_insert = 0, i, j, key; //key refers to the smallest element

	for (i = 1; i < n; i++) {//starts from 1 becasue we are comparing with the previous one

		key = arr[i];
		j = i - 1;

		count_insert++;
		while (j >= 0) {
			if (arr[j] > key) {

				arr[j + 1] = arr[j];
			}
			j--;
		}
		arr[j] = key;//*******************************
	}
	return count_insert;
}

int selectionSort_count(int arr[], int n)
{
	int i, j, min_idx, count = 0;

	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			count++;
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
			swap(arr[min_idx], arr[i]);
	}
	return count;
}