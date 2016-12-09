// For this challenge you will be determining if a string is a valid number.
/*
have the function FormattedNumber(strArr) take the strArr parameter being passed, which will only contain a single element, and return the string true if it is a valid number that contains only digits with properly placed decimals and commas, otherwise return the string false. For example: if strArr is ["1,093,222.04"] then your program should return the string true, but if the input were ["1,093,22.04"] then your program should return the string false. The input may contain characters other than digits.
*/

#include <iostream>
#include <string>
using namespace std;

/*
iterate through the first element
make sure we are only working with digits, commas, and decimal point
when we find a comma make sure there are three preceding digits else false
we can only have one decimal point
commas are only valid before the decimal point
*/

string FormattedNumber(string strArr[]) 
{   
	int hundred = 3;
	int comma=-1, decimal=strArr[0].length();
	int decimalTotal = 0;

	for (int x = 0; x < strArr[0].length(); x++)
	{
		// Condition to check we are only working with the correct characters
		if (strArr[0][x] == ',' || strArr[0][x] == '.' || strArr[0][x] >= '0' && strArr[0][x] <= '9')
		{
			// Checking for the start of a comma also checking that the rules are followed
			if (strArr[0][x] == ',')
			{
				if (hundred == 3)
				{
					hundred = 0;
					comma = x;
					if (comma > decimal)
					{
						return "false";
					}
				}
				else
				{
					return "false";
				}
				
			}

			// Digits after the comma
			if (strArr[0][x] >= '0' && strArr[0][x] <= '9' && x > comma && comma != -1)
			{
				hundred++;
			}

			// Locating our decimal point
			// Assuring we only have a single decimal point
			// Also assuring our comma rule is checked
			if (strArr[0][x] == '.')
			{
				decimal = x;
				decimalTotal++;
				if (decimalTotal > 1 || hundred != 3)
				{
					return "false";
				}
			}
		}
		else
		{
			return "false";
		}
	}

	return "true";
}

int main() 
{
	string A[] = { "1,093,222.04" };
	string B[] = { "1,093,22.04" };
	string C[] = { "0.232567" };
	string D[] = { "2,567.00.2" };
	string E[] = { "1,093,2qw.04" };
	string F[] = { "898989898" };

	cout << FormattedNumber(A) << endl; // true
	cout << FormattedNumber(B) << endl; // false
	cout << FormattedNumber(C) << endl; // true
	cout << FormattedNumber(D) << endl; // false
	cout << FormattedNumber(E) << endl; // false
	cout << FormattedNumber(F) << endl;
	return 0;
}