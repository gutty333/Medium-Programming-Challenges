//  For this challenge you will be determining if a string is a valid password.
/*
have the function SimplePassword(str) take the str parameter being passed and determine if it passes as a valid password that follows the list of constraints:

1. It must have a capital letter.
2. It must contain at least one number.
3. It must contain a punctuation mark.
4. It cannot have the word "password" in the string.
5. It must be longer than 7 characters and shorter than 31 characters.

If all the above constraints are met within the string, the your program should return the string true, otherwise your program should return the string false. For example: if str is "apple!M7" then your program should return "true".
*/

#include <iostream>
#include <string>
using namespace std;

string SimplePassword(string str) 
{
	int lowLimit = 7;
	int highLimit = 31;
	bool capital = false;
	bool symbol = false;
	bool number = false;
	string temp = "password";

	// checking the size
	if (str.size() >= 31 || str.size() < 7)
	{
		return "false";
	}

	for (int x = 0; x < str.size(); x++)
	{
		if (str[x] >= '0' && str[x] <= '9')
		{
			number = true;
		}
		else if (isupper(str[x]))
		{
			capital = true;
		}
		else if (int(str[x]) >= 33 && int(str[x]) <= 47 || int(str[x]) >= 58 && int(str[x]) <= 64)
		{
			symbol = true;
		}

		// Condition to check if the word 'password' is found in the input
		if (tolower(str[x]) == 'p')
		{
			int index = 0;
			bool found = true;
		
			for (int y = x; y < x + temp.size(); y++)
			{
				if (tolower(str[y]) != temp[index])
				{
					found = false;
					break;
				}
				index++;
			}

			if (found)
			{
				return "false";
			}
		}
	}

	if (capital && symbol && number)
	{
		return "true";
	}
	else
	{
		return "false";
	}
}

int main() 
{

	cout << SimplePassword("apple!M7") << endl; // true
	cout << SimplePassword("passWord123!!!!") << endl; // false
	cout << SimplePassword("turkey90AAA=") << endl; // true
	return 0;

}