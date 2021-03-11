//Task 3
# include <iostream>
using namespace std; 

int s_ver_3(int);
int** matrix_product(int**, int);

int s_ver_3(int n)
{
	int ** matrix = new int * [2];

	matrix = matrix_product(matrix, n);
	return matrix[0][1];
	
}

int** matrix_product(int** mtrx, int n) 
{

}


int main()
{
	cout << "  n        S(n)\n";
	int sum;
	for (int i = 0; i < 15; i++)
	{
		sum = s_ver_2(i);
		printf("  %d        %d\n", i, sum);
	}


	system("pause");
	return 0;
}