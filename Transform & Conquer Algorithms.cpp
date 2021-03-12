#include <iostream> 
#include <vector>
using namespace std;

//task 1
void get_frequencies(double [], int); // n: size 
void heapSort(int [], int);
void build_heap(int [], int);
void heapify(int [], int, int);

void heapify(int arr[], int n, int i)// i: the index
{
  int largest = i; //initialize the ragest as the root
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (arr[left] > arr[largest] && left < n)
		largest = left;
	
	if (arr[right] > arr[largest] && left < n)
		largest = right;

	if (largest = !i) {
		swap(arr[i], arr[largest]);
		//call heapify again to the new root to modify the new subtree
		heapify(arr, n, largest);
	}
}

void build_heap(int arr[], int n) {
	//start calling from the last node that has children
	//leaves start from index n/2 which means if we have 10 elements then the leaves starts from 6 to 10 (n/2+1) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
}

void heapSort(int arr[], int n) 
{	
	build_heap(arr, n);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void get_frequencies(double arr[], int n)
{
  //   arr: 4 2 2 1 7 7 4 2 3 1  
  heapSort(arr, n);
  //sorted: 1 1 2 2 2 3 4 4 7 7 

}