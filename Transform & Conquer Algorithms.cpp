//The drawback of this algorithem is that it excutes the requred algorithm right but when we
// try a new array of elelments, it doesn't be excuted. 
#include <iostream> 
#include <iomanip>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//task 1
void get_frequencies(double[], int); // n: size 
//task 2
double most_frequent(double arr[], int n);

void get_frequencies(double arr[], int n)
{
	cout << "Array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl << endl;

	//   arr: 4 2 2 1 7 7 4 2 3 1  
	sort(arr, arr + n);
	//sorted: 1 1 2 2 2 3 4 4 7 7

	vector<double> freq;
	set<double> a;
	for (int i = 0; i < n; i++)
		freq.push_back(0);

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

	cout << "Array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl << endl;

	//   arr: 4 2 2 1 7 7 4 2 3 1  
	sort(arr, arr + n);
	//sorted: 1 1 2 2 2 3 4 4 7 7

	vector<double> freq;
	set<double> a;
	for (int i = 0; i < n; i++)
		freq.push_back(0);

	for (int i = 0; i < n; i++) {
		freq.at(arr[i])++;
		a.insert(arr[i]);
	}

	double max = -INFINITY;
	auto it = a.begin();
	while (it != a.end()) {
		if (freq.at(*it) > max)
			max = *it;
		it++;
	}
	return max;
}

//set<pair<double, int>> freq;
	/*vector<double> freq;
	for (int i = 0; i < n; i++)
		freq.insert(make_pair(0, arr[i]));

	for (auto it : freq)
		cout << it.first << "  " << it.second << endl;	*/

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

	double array[] = { 4, 2, 2, 1, 7, 7, 4, 2, 3, 1 };
	double arr[] = { 5.5, 6.7, 6.7, 8.5, 5.5, 4.2, 6.7, 2, 3, 1 }; //doesn't work
	get_frequencies(array, 10);
	cout << endl;
	//test(array, 10);

	cout << "The most frequent element is : " << most_frequent(array, 10) << endl; //------------;
	system("pause");
	return 0;
}