// For this challenge you will determine what the variable is in a mathematical equation.
// have the function MissingDigit(str) take the str parameter, which will be a simple mathematical formula with three numbers, a single operator (+, -, *, or /) and an equal sign (=) and return the digit that completes the equation. In one of the numbers in the equation, there will be an x character, and your program should determine what digit is missing. For example, if str is "3x + 12 = 46" then your program should output 4. The x character can appear in any of the three numbers and all three numbers will be greater than or equal to 0 and less than or equal to 1000000. 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Helper function that determines the type of calculation 
void calculation(int& val, int x, int y, char symbol)
{
	// Finding which type of calculation we need to perform
	switch (symbol)
	{
		case '+':
		{
			val = x + y;
			break;
		}
		case '-':
		{
			val = x - y;
			break;
		}
		case '*':
		{
			val = x * y;
			break;
		}
		case '/':
		{
			val = x / y;
			break;
		}
	}
}
// Another helper function that will inverse the operation
void operatorSwitch(string& equation, int index)
{
	// Switching the operator
	// Example if original is + now it will be -. 
	// Ex. x+3 = 7 becomes 7-3 = x. Simple algebra
	switch (equation[index])
	{
		case '+':
		{
			equation[index] = '-';
			break;
		}
		case '-':
		{
			equation[index] = '+';
			break;
		}
		case '*':
		{
			equation[index] = '/';
			break;
		}
		case '/':
		{
			equation[index] = '*';
			break;
		}
	}
}

char MissingDigit(string str) {
	// Removing spaces
	for (int y = 0; y < str.length(); y++)
	{
		if (str[y] == ' ')
		{
			str.erase(str.begin() + y);
		}
	}

	// Find the operator and sign symbol
	int symbol, sign;
	for (int x = 0; x < str.length(); x++)
	{
		if (str[x] == '+' || str[x] == '-' || str[x] == '*' || str[x] == '/')
		{
			symbol = x;
		}
	}
	sign = str.find('=');
	
	// Finding x variable position, this will help determine the method of calculation to perform
	int value = str.find('x');

	int value1, value2, value3, index = 0, index2;
	string temp;
	// Analyzing whether the variable is after the sign
	if (value > sign)
	{
		istringstream(str.substr(0, symbol)) >> value1;
		istringstream(str.substr(symbol + 1, sign-symbol)) >> value2;
		
		// Calculation function that will give us the result for the missing variable
		calculation(value3, value1, value2, str[symbol]); 

		// We convert number value to a string and find result based on index
		// Example number = 27 , original x7 than result would be 2
		stringstream convert;
		convert << value3;
		temp = convert.str();
		index2 = sign+1; // index2 helps with making the result string parallel to the original string
		for (sign; sign < str.length(); sign++)
		{
			// If they are the same index return the corresponding value
			if (sign == value)
			{
				return temp[sign-index2];
			}
		}
	}
	else // Analyzing when variable is before the sign
	{
		// If the variable is after the symbol or before
		if (value < symbol) // Before
		{
			istringstream(str.substr(symbol + 1, sign - symbol)) >> value1;
			istringstream(str.substr(sign + 1)) >> value2;
			
			// Calculation and switching the operation
			operatorSwitch(str, symbol);
			calculation(value3, value2, value1, str[symbol]);

			stringstream convert;
			convert << value3;
			temp = convert.str();
			for (index; index < symbol; index++)
			{
				// If they are the same index return the corresponding value
				if (index == value)
				{
					return temp[index];
				}
			}
		}
		else // After
		{
			istringstream(str.substr(0, symbol)) >> value1;
			istringstream(str.substr(sign + 1)) >> value2;

			// Calculation and switching the operation
			if (value1 != value2)
			{
				operatorSwitch(str, symbol);
			}
			calculation(value3, value2, value1, str[symbol]);

			stringstream convert;
			convert << value3;
			temp = convert.str();
			index = symbol;
			index2 = symbol + 1;
			for (index; index < sign; index++)
			{
				// If they are the same index return the corresponding value
				if (index == value)
				{
					return temp[index-index2];
				}
			}
		}
	}
}

int main() {

	// keep this function call here
	cout << MissingDigit("4 - 2 = x") << endl; // 2
	cout << MissingDigit("10 + 14 = 2x") << endl; // 4
	cout << MissingDigit("20 + 7 = x7") << endl; // 2
	cout << MissingDigit("1x0 * 12 = 1200") << endl; // 0
	cout << MissingDigit("3x + 12 = 46") << endl; // 4
	cout << MissingDigit("10 - x = 10") << endl; // 0
	cout << MissingDigit("14 + x1 = 25") << endl; // 1
	cout << MissingDigit("2x - 10 = 10") << endl; // 0
	return 0;
}