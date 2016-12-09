// For this challenge you will divide two numbers and print them in a certain format.
// have the function FormattedDivision(num1,num2) take both parameters being passed, divide num1 by num2, and return the result as a string with properly formatted commas and 4 significant digits after the decimal place. For example: if num1 is 123456789 and num2 is 10000 the output should be "12,345.6789". The output must contain a number in the one's place even if it is a zero. 

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

string FormattedDivision(int num1, int num2) {

	double result = double(num1) / num2;

	// Convert the double to a string with proper output manipulation
	stringstream convert;
	convert << fixed << setprecision(4) << result;
	string num = convert.str();
	string temp;

	// Check if the number needs to be formatted with commas
	// if the whole number is in the hundreds no need to format with commas
	// else if it is in the thousands or above format with a commas
	for (int x = 0; x < num.length(); x++)
	{
		if (num[x] == '.' && x < 3) // If number was in the hundreds or lower just copy original
		{
			temp = num;
			break;
		}
		else if (num[x] == '.' && x > 3) // Format with commas
		{
			int count = 0;
			for (int y = x-1; y >= 0; y--)
			{
				// Checking to see the placement of every hundreds
				// This determines when the comma will be added
				if (count == 3) 
				{
					temp.push_back(',');
					temp.push_back(num[y]);
					count = 0;
				}
				else
				{
					temp.push_back(num[y]);
				}
				count++;
			}

			// Reversing the string back, since we were working from the period to the front
			// Also add the period
			reverse(temp.begin(), temp.end());
			temp.push_back(num[x]);
		}
		else if (temp.length() > 0)  
		{
			// Once the commas are formatted keep traversing the parent loop 
			// Just inserting the remaining numbers after the period
			temp.push_back(num[x]);
		}
	}

	return temp;
}

int main() {

	// keep this function call here
	cout << FormattedDivision(2,3) << endl; // 0.6667
	cout << FormattedDivision(10, 10) << endl; // 1.0000
	cout << FormattedDivision(123456789, 10000) << endl; // 12,345.6789
	cout << FormattedDivision(123456789, 1) << endl; // 123,456,789.0000
	cout << FormattedDivision(23456789, 1) << endl; // 23,456,789.0000
	return 0;

}