#include <iostream>
#include <string>
using namespace std;

//funtions:
string multiply(string n1, string n2);
void padding(string& str, int n, bool right);

//function definition
string multiply(string n1, string n2)
{
	//string a = sub_string
	if (n1.length() > n2.length()) {
		padding(n2, int(n1.length() - n2.length()), false);
	}
	else if (n2.length() > n1.length()) {
		padding(n1, int(n2.length() - n1.length()), false);
	}
	//now both numbers should be equal in length

	//base case
	if (n1.length() <= 2 && n2.length() <= 2)
	{
		//converting the odd n-digits to even
		if (n1.length() % 2 == 1)
			padding(n1, 1, false);
		if (n2.length() % 2 == 1)
			padding(n2, 1, false);

		if (n1.length() % 2 == 0)//even n-digits
		{
			int steps_a = int(n1.length()) / 2 - 1,
				index_b = int(n1.length()) / 2,
				end_index = int(n1.length());

			string
				a = n1.substr(0, steps_a),
				b = n1.substr(index_b, end_index),
				c = n2.substr(0, steps_a),
				d = n2.substr(index_b, end_index);
		}
	}
	

	return 0;
}

void padding(string& str, int n, bool right) //right is true if zeros on the right, false if on the left
{
	string zeros;
	for (int i = 0; i < n; i++) {
		zeros.append("0");
	}
	if (right)
		str = str + zeros;
	else 
		str = zeros + str;
}

int main() {

	int num1, num2;

	cout << "Enter the 2 numbers to get their product (separate them by new line)" << endl;
	cin >> num1 >> num2;

	string n1 = to_string(num1),
		   n2 = to_string(num2);

	//string n = "XXX";
	////n.append("000");
	//cout << "000" + n <<endl;

	system("pause");
	return 0;
}

