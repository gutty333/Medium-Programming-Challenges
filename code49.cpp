// For this challenge you will determine what the variables are in a mathematical equation.
/*
have the function MissingDigitII(str) take the str parameter, which will be a simple mathematical formula with three numbers, a single operator (+, -, *, or /) and an equal sign (=) and return the two digits that complete the equation. In two of the numbers in the equation, there will be a single ? character, and your program should determine what digits are missing and return them separated by a space. For example, if str is "38?5 * 3 = 1?595" then your program should output 6 1.

The ? character will always appear in both the first number and the last number in the mathematical expression. There will always be a unique solution.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*
find out what type of operation needs to happen
convert our values to an int to perform operations
since the middle number is always complete we can use it to perform various operation with our first number
The method is simple insert temp digits 0-9 on first number
perform operation between the numbers and check that it matches our last number
*/

// Linear search function
bool search(vector <int> list, int value)
{
	for (int x = 0; x < list.size(); x++)
	{
		if (list[x] == value)
		{
			return true;
		}
	}
	return false;
}

string MissingDigitII(string str)
{
	char operation;
	// Conditions to find what type of operation we are working with
	if (str.find('*') != -1)
	{
		operation = str.find('*');
	}
	else if (str.find('/') != -1)
	{
		operation = str.find('/');
	}
	else if (str.find('+') != -1)
	{
		operation = str.find('+');
	}
	else if (str.find('-') != -1)
	{
		operation = str.find('-');
	}

	string firstNum, middleNum, lastNum;
	int equalSign = str.find('='); // Locating our equal sign

	// Extracting our string values to later convert to ints and perform calculations
	firstNum = str.substr(0, operation - 1);
	middleNum = str.substr(operation + 2, (equalSign - operation)-3);
	lastNum = str.substr(equalSign + 2);

	// We locate the missing digit of our last number 
	int num;
	int question = lastNum.find('?');
	if (question == 0)
	{
		lastNum[question] = '9';
	}
	else
	{
		lastNum[question] = '0';
	}
	
	istringstream(lastNum) >> num;

	// List that will store all the possible valid results when the operation is perform
	// This includes the last number and increments its digit in the proper location
	// Example if last number is 3?5, the list we have 305,315,325,etc...
	vector <int> resultList;
	resultList.push_back(num);

	// Loop creating the list
	for (int x = 0; x < 9; x++)
	{
		stringstream convert;
		convert << num;
		string temp = convert.str();
		if (question == 0)
		{
			temp[question] = char(int(convert.str()[question]) - 1);
		}
		else
		{
			temp[question] = char(int(convert.str()[question]) + 1);
		}
		istringstream(temp) >> num;
		resultList.push_back(num);
	}

	// Locating missing digit of first number and cover both first number and middle number to ints
	int question2 = firstNum.find('?');
	if (question2 == 0)
	{
		firstNum[question2] = '9';
	}
	else
	{
		firstNum[question2] = '0';
	}
	
	int first, middle;
	istringstream(firstNum) >> first;
	istringstream(middleNum) >> middle;

	// String to store our final output
	string result;

	// Loop to perform the operation
	// Since we set our first number to the highest possible we iterate until the zero digit
	// Through each iteration we perform operations with middle num and check if the total is in our list
	for (int x = 0; x < 10; x++)
	{
		int total;
		switch (str[operation])
		{
			case '*':
				// Perform the required operation
				total = first * middle;
				// Condition to check if is in our list
				if (search(resultList, total))
				{
					// extracts our digits from the total and first number
					stringstream convert;
					convert << first;
					result += convert.str()[question2];
					result += " ";
					convert.str("");
					convert << total;
					result += convert.str()[question];
					return result;
				}
				break;
			case '/':
				total = first / middle;
				if (search(resultList, total))
				{
					stringstream convert;
					convert << first;
					result += convert.str()[question2];
					result += " ";
					convert.str("");
					convert << total;
					result += convert.str()[question];
					return result;
				}
				break;
			case '+':
				total = first + middle;
				if (search(resultList, total))
				{
					stringstream convert;
					convert << first;
					result += convert.str()[question2];
					result += " ";
					convert.str("");
					convert << total;
					result += convert.str()[question];
					return result;
				}
				break;
			case '-':
				total = first - middle;
				if (search(resultList, total))
				{
					stringstream convert;
					convert << first;
					result += convert.str()[question2];
					result += " ";
					convert.str("");
					convert << total;
					result += convert.str()[question];
					return result;
				}
				break;
		}
		
		// Updates our first number
		stringstream convert;
		convert << first;
		string temp = convert.str();
		if (question2 == 0)
		{
			temp[question2] = char(int(convert.str()[question2]) - 1);
		}
		else
		{
			temp[question2] = char(int(convert.str()[question2]) + 1);
		}
		istringstream(temp) >> first;
	}
}

int main() 
{
	cout << MissingDigitII("38?5 * 3 = 1?595") << endl; // 6 1
	cout << MissingDigitII("56? * 106 = 5?678") << endl; // 3 9
	cout << MissingDigitII("18?1 + 9 = 189?") << endl; // 8 0 
	cout << MissingDigitII("1? + 11 = ?2") << endl; // 1 2
	cout << MissingDigitII("6? - 51 = ?7") << endl; // 8 1
	cout << MissingDigitII("5555? - 4261 = ?1294") << endl; // 5 5
	cout << MissingDigitII("?0 + 20 = 4?") << endl; // 2 0
	cout << MissingDigitII("50? / 5 = ?00") << endl; // 0 1
	cout << MissingDigitII("? + 21 = ?0") << endl; // 9 3
	return 0;
}

