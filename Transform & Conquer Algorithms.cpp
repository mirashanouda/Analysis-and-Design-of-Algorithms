#include <iostream> 
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

//task 1
void get_frequencies(double[], int); // n: size 
void heapSort(double[], int);
void build_heap(double[], int);
void heapify(double[], int, int);

void heapify(double arr[], int n, int i)// i: the index
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

void build_heap(double arr[], int n) {
	//start calling from the last node that has children
	//leaves start from index n/2 which means if we have 10 elements then the leaves starts from 6 to 10 (n/2+1) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
}

void heapSort(double arr[], int n)
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
	sort(arr, arr + n);
	//sorted: 1 1 2 2 2 3 4 4 7 7
	vector<pair<double, int>> freq;

	int i = 0, j;
	while (i < n) {
		freq.push_back(make_pair(arr[i], 1));
		for (j = i + 1; j < n; j++) {
			if (arr[j] == arr[i])
				freq.at(i).second = freq.at(i).second + 1;
			else
				break;
		}
		i = j;
	}

	cout << "Array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl << endl;
	cout << "Element" << setw(10) << "frequency" << endl;
	cout << "-----------------" << endl;

	for (int i = 0; i < int(freq.size()); i++)
		cout << freq.at(i).first << setw(10) << freq.at(i).second << endl;
}

void test(double arr[], int n);
void test(double arr[], int n) {
	
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " "; 
	cout << endl;
}

int main() {

	double array[] = {4, 2, 2, 1, 7, 7, 4, 2, 3, 1 };
	get_frequencies(array, 10);
	//test(array, 10);

	system("pause");
	return 0;
}