// For this challenge you will convert a string of written numbers to an actual number.
/*
have the function StringExpression(str) read the str parameter being passed which will contain the written out version of the numbers 0-9 and the words "minus" or "plus" and convert the expression into an actual final number written out as well. For example: if str is "foursixminustwotwoplusonezero" then this converts to "46 - 22 + 10" which evaluates to 34 and your program should return the final string threefour. If your final answer is negative it should include the word "negative."
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*
Have a string array of the numbers
traverse the input and store the characters into a temp string
with each iteration we compare the temp string to our helper function to return a number equivalent
if the temp string matches a valid string number we reset the temp to search for another
the results will be stored into a string number. ex if temp string is "four" number string is "4"
the above process will continue until we reach either a minus or plus or reach the last index

once a plus or minus is reached the number string will converted to an int
it will also be added to a new list
plus or minus symbols will also be represented with placeholder integers (plus = 0, minus = 1)

the calculation will be performed ounce the expression has been analyzed
after completion we have to convert the result back to a string expression
we traverse the final string to converts its digits to represent an expression
example twothree = 23
*/

string list[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };


// Converts string expression to its number corresponding number
// "nine" = "9"
int getValue(string temp)
{
	for (int x = 0; x < 10; x++)
	{
		if (temp == list[x])
		{
			return x;
		}
	}

	return -1;
}

// Converts character digit to its string expression
// "4" = "four"
string getExpression(char digit)
{
	int index = int(digit) - 48;

	return list[index];
}

string StringExpression(string str)
{
	string temp;
	string number = "";
	vector <int> numberList;


	for (int x = 0; x < str.length(); x++)
	{
		temp.push_back(str[x]);

		// checking if the temp string corresponds to a valid string number
		int value = getValue(temp);
		if (value >= 0 && value <= 9)
		{
			// condition for when temp matches a valid number
			// we transform the number expression to its number representative 
			// example "one" = "1"
			stringstream convert;
			convert << value;
			number += convert.str(); // storing our result
			temp.clear(); // reseting our temp string to validate another section of our input
		}

		if (temp == "plus" || temp == "minus" || x == str.length()-1)
		{
			// condition for when we reach an operator or last number expression
			// we convert the number representative to an integer
			// we also track our operation if one was found
			int result;
			istringstream(number) >> result;
			numberList.push_back(result);

			number = "";

			if (temp == "plus")
			{
				numberList.push_back(0);
			}
			else if (temp == "minus")
			{
				numberList.push_back(1);
			}
			temp.clear();
		}
	}

	// loop to perform the calculation based on our gathered numbers and operations
	int total = numberList[0];
	for (int x = 1; x < numberList.size() - 1; x += 2)
	{
		// these condition determine if we add or subtract based on our placeholder values for the operators
		// 0 = plus  and 1 = minus
		if (numberList[x] == 0)
		{
			total += numberList[x + 1];
		}
		else
		{
			total -= numberList[x + 1];
		}
	}

	stringstream convert;
	convert << total;
	number = convert.str();
	string finalString= "";

	// in the case the result is negative
	if (total < 0)
	{
		finalString += "negative";
	}

	// loop to traverse final string number
	// here we do inverse of before now we transfer number representative to its expression
	// example "2" = "two"
	for (int x = 0; x < number.length(); x++)
	{
		finalString += getExpression(number[x]);
	}

	return finalString;
}

int main()
{
	cout << StringExpression("onezeropluseight") << endl; // oneeight
	cout << StringExpression("oneminusoneone") << endl; // negativeonezero
	cout << StringExpression("foursixminustwotwoplusonezero") << endl; // threefour
	
	return 0;
}
