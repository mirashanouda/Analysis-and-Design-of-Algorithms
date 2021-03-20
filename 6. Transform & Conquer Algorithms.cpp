//The drawback of this algorithem is that it excutes the requred algorithm right but when we
// try a new array of elelments, it doesn't be excuted. 
#include <iostream> 
#include <iomanip>
#include <vector>
#include <set>
#include <fstream>
//#include <algorithm>
using namespace std;

void heapify(double arr[], int n, int i);
void build_heap(double arr[], int n);
void HSort(double arr[], int n);

void heapify(double arr[], int n, int i) {

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
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}
}

void HSort(double arr[], int n) {

	build_heap(arr, n);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
//------------------------------------------------
//task 1
void get_frequencies(double[], int); // n: size 
//task 2
double most_frequent(double arr[], int n);

void get_frequencies(double arr[], int n)
{
	/*cout << "Array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl << endl;*/

	//   arr: 4 2 2 1 7 7 4 2 3 1  
	HSort(arr, n);
	//sorted: 1 1 2 2 2 3 4 4 7 7

	vector<double> freq;
	set<double> a;
	for (int i = 0; i < n; i++)
		freq.push_back(0); //to initialize all the frequencies with 0

	for (int i = 0; i < n; i++) {
		freq.at(arr[i])++;
		a.insert(arr[i]);
	}
	/*int i = 0, j;
	while (i < n) {
		freq.push_back(make_pair(arr[i], 1));
		for (j = i + 1; j < n; j++) {
			if (arr[j] == arr[i])
				freq.at(i).second = freq.at(i).second + 1;
			else
				break;
		}
		i = j;
	}*/

	cout << "Element" << setw(10) << "frequency" << endl;
	cout << "-----------------" << endl;

	for (auto it = a.begin(); it != a.end(); it++)
		cout << *it << setw(10) << freq.at(*it) << endl;
	//cout << *it << setw(10) << freq.count(*it) << endl;
}

double most_frequent(double arr[], int n) {

	/*cout << "Array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl << endl;*/

	//   arr: 4 2 2 1 7 7 4 2 3 1  
	HSort(arr, n);
	//sorted: 1 1 2 2 2 3 4 4 7 7

	vector<double> freq;
	set<double> a;
	for (int i = 0; i < n; i++)
		freq.push_back(0);

	for (int i = 0; i < n; i++) {
		freq.at(arr[i])++;
		a.insert(arr[i]);
	}

	double max_index = -INFINITY, max_value;
	auto it = a.begin();
	while (it != a.end()) {
		if (freq.at(*it) > max_index)
		{
			max_value = *it;
			max_index = freq.at(*it);
		}
		it++;
	}
	return max_value;
}

//-------------------------------------------------
	/*
	set<pair<double, int>> freq;
	vector<double> freq;
	for (int i = 0; i < n; i++)
		freq.insert(make_pair(0, arr[i]));

	for (auto it : freq)
		cout << it.first << "  " << it.second << endl;	*/

		//-------------------------------------------------
void test(double arr[], int n);
void test(double arr[], int n) {

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	HSort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
//-------------------------------------------------
int main() {

	//task 1
	double array[] = { 4, 2, 2, 1, 7, 7, 4, 2, 3, 1 };
	double arr[] = { 5.5, 6.7, 6.7, 8.5, 5.5, 4.2, 6.7, 2, 3, 1 }; //doesn't work
	//get_frequencies(array, 10);
	cout << endl;
	//test(array, 10);

	//task 2
	double file_arr[1000];
	ifstream in("numbers.txt");

	for (int i = 0; i < 1000; i++)
		in >> file_arr[i];

	cout << "The most frequent element is : " << most_frequent(file_arr, 1000) << endl;
	get_frequencies(file_arr, 1000);

	in.close();
	system("pause");
	return 0;
}