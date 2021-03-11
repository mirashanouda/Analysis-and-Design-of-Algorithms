//Task 2
# include <iostream>
using namespace std; 

int s_ver_2(int);
int s_ver_2(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else {
		int* arr = new int[n];
		for (int i = 2; i < n; i++) {
			if (i == 0)
				arr[i] = 0;
			else if (i == 1)
				arr[i] = 1;
			else arr[i] = arr[i - 1] + arr[i - 2];
		}
		return arr[n - 1];
	}

int main()
{
	cout << "  n        S(n)\n";
	int sum;
	for (int i = 0; i < 15; i++)
	{
		sum = s_ver_3(i);
		printf("  %d        %d\n", i, sum);
	}


	system("pause");
	return 0;
}