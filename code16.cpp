// For this challenge you will determine if there is a number that appears consecutively in both arguments.
// have the function TripleDouble(num1,num2) take both parameters being passed, and return 1 if there is a straight triple of a number at any place in num1 and also a straight double of the same number in num2. For example: if num1 equals 451999277 and num2 equals 41177722899, then return 1 because in the first parameter you have the straight triple 999 and you have a straight double, 99, of the same number in the second parameter. If this isn't the case, return 0. 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int TripleDouble(int num1, long long num2) {

	stringstream convert;
	convert << num1;
	string temp1 = convert.str();
	int count;
	int value = -1;

	for (int x = 0; x < temp1.length(); x++)
	{
		// Find the triple value from the first argument
		count = 1;
		for (int y = 0; y < temp1.length() - 1; y++)
		{
			if (temp1[x] == temp1[y] && temp1[y] == temp1[y+1])
			{
				count++;
			}
			if (count == 3)
			{
				value = int(temp1[x]);
				break;
			}
		}
		if (value != -1)
		{
			break;
		}
	}
	// Checking for the double in the second argument
	stringstream convert2;
	convert2 << num2;
	string temp2 = convert2.str();
	for (int z = 0; z < temp2.length()-1; z++)
	{
		if (char(value) == temp2[z] && temp2[z] == temp2[z + 1])
		{
			return 1;
		}
	}
	return 0;
}

int main() {

	// keep this function call here
	cout << TripleDouble(465555,5579) << endl; // 1
	cout << TripleDouble(67844, 66237) << endl; // 0
	cout << TripleDouble(451999277,41177722899) << endl; // 1
	cout << TripleDouble(556668, 556886) << endl;  // 0
	cout << TripleDouble(333,33) << endl; // 1
	cout << TripleDouble(555666, 5589) << endl; // 1
	cout << TripleDouble(3776777,87766) << endl; // 1
	return 0;

}