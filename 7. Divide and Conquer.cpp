#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//funtions:
string multiply(string n1, string n2);
void padding(string& str, int n, bool right);
string add(string X, string Y, string Z, char sign);

//function definition
string multiply(string n1, string n2)
{
	string product; //the product we should return

	if (n1.length() > n2.length()) {
		padding(n2, int(n1.length() - n2.length()), false);
	}
	else if (n2.length() > n1.length()) {
		padding(n1, int(n2.length() - n1.length()), false);
	}
	//now both numbers should be equal in length


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
		
		//base case
		if (a.length() == 1){

			string product_table[45][45];
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					product_table[i][j] = to_string((i + 1) * (j + 1));

			//product = ac10^n + [(a+b)(c+d) - ac - bd]10^n/2 + bd 
			

			int A, B, C, D;
			stringstream convert_a(a);
			convert_a >> A;
			stringstream convert_b(b);
			convert_b >> B;
			stringstream convert_c(c);
			convert_c >> C;
			stringstream convert_d(d);
			convert_d >> D;
			// another method using stoi()

			string
				ac = product_table[A - 1][C - 1],
				bd = product_table[B - 1][D - 1],
				a_b = add(a, b, 0, '+'),
				c_d = add(c, d, 0, '+'),
				//(ab + bc)
				midterm = add(
					to_string(stoi(a_b) * stoi(c_d)),
					ac,
					bd, '-');
				
			padding(ac, 2, true);
			padding(midterm, 1, true);
			product = add(ac, midterm, bd, '+');
			return product;
		}
		else {
			return to_string(stoi(multiply(a, b))* stoi(multiply(c, d)));
		}
			
	}
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

string add(string X, string Y, string Z,char sign)
{
	int x = stoi(X),
		y = stoi(Y),
		z = stoi(Z),
		sum = 0;
	if (sign == '+')
		sum = x + y + z;
	else if (sign == '-')
		sum = x - y - z;

	return to_string(sum);
}

int main() {

	int num1, num2;

	cout << "Enter the 2 numbers to get their product (separate them by new line)" << endl;
	cin >> num1 >> num2;

	string n1 = to_string(num1),
		   n2 = to_string(num2);

	cout << "the product = " << multiply(n1, n2) << endl;


	system("pause");
	return 0;
}

