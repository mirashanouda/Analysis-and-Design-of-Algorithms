#include <iostream>
using namespace std; 

int bubble_sort_comparisons(int* arr, int n);
int insertion_sort_comparisons(int* arr, int n);
int* generate_k_inversions(int k, int n);
void test1();
void test2();

int bubble_sort_comparisons(int* arr, int n) {
	
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

int insertion_sort_comparisons(int* arr, int n) {

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

int* generate_k_inversions(int k, int n) { //we can make up to n(n-1)/2 inversions but her for simplicity we will make up to n-1 only 

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		arr[i] = i + 1;

	for (int i = 1; i <= k; i++) 
		swap(arr[i], arr[i-1]);
	
	return arr;
}

void test1() {

	//n: 1 - 10
	cout << "----------------------------------TEST(1)----------------------------------\n";
	cout << "   N    Bubble(best)    Bubble(worst)    Insertion(best)    Insertion(worst)\n";
	cout << "---------------------------------------------------------------------------\n";

	for (int n = 1; n <= 10; n++) {

		int* ary = new int[n];

		for (int i = 0; i < n; i++) {
			int k = n - i;
			ary[i] = k;
		}	


		//now we have an un sorted array (worest case) that goes to the 2 sorting funtions 
		//we need to generate a soreted copy of it to be (best case)
		//we need 4 coppies of it: 2 sorted (best case) and 2 in an inverse arrangment (worest case)


		int* copy_ary = ary; // coppy of unsorted 

		int insert_w = insertion_sort_comparisons(copy_ary, n); //unsorted
		int insert_b = insertion_sort_comparisons(copy_ary, n); //sorted

		int bubble_w = bubble_sort_comparisons(ary, n); //unsorted 
		int bubble_b = bubble_sort_comparisons(ary, n); //sorted 

		/*cout << "worest: \n";
		

		

		/*cout << "best: \n";
		for (int i = 0; i < n; i++)
		{
			cout << copy_ary[i] << "  ";
		}cout << endl << endl;*/

		

		cout << "   " << n << "      " << bubble_b << "      " << bubble_w << "      " << insert_b << "      " << insert_w << endl;
	}


}

void test2() {
	cout << "----------------------------------TEST(2)----------------------------------\n";
	cout << "   N                 Bubble sort comp.                 Insertion sort comp.\n";
	cout << "---------------------------------------------------------------------------\n";

	for (int n = 5; n <= 15; n++) {
		
		int inversion = n / 4;
		
		int *arr = generate_k_inversions(inversion, n);

		int bubble = bubble_sort_comparisons(arr, n);
		int insert = insertion_sort_comparisons(arr, n);

		cout << "   " << n << "                  " << bubble << "                 " << insert << endl;
		cout << "---------------------------------------------------------------------------\n";
	}

}

int main() {
	test1();
	cout << endl << endl; 
	test2();
	
	
	system("pause");
	return 0;
}