//Task 1
# include <iostream>
using namespace std; 

unsigned s_ver_1(unsigned);

unsigned s_ver_1(unsigned n)
{
	if (n == 0 || n == 1)
		return n;
	else
		return s_ver_1(n - 1) + s_ver_1(n - 2);
}

int main()
{
	cout << "  n        S(n)\n";
	int sum;
	for (int i = 0; i < 15; i++)
	{
		sum = s_ver_1(i);
		printf("  %d        %d\n", i, sum);
	}

	system("pause");
	return 0;
}