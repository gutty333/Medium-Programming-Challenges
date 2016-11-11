// For this challenge you will be finding the longest palindromic substring.
/*
have the function PalindromicSubstring(str) take the str parameter being passed and find the longest palindromic substring, which means the longest substring which is read the same forwards as it is backwards. For example: if str is "abracecars" then your program should return the string racecar because it is the longest palindrome within the input string.

The input will only contain lowercase alphabetic characters. The longest palindromic substring will always be unique, but if there is none that is longer than 2 characters, return the string none.
*/

#include <iostream>
#include <string>
using namespace std;

/*
Loop through the string
analyze sub strings with more than 3 characters
continue to analyze from that index
keep track of the longest palindrome and repeat the steps
*/

// Function checking for palindrome
bool palindrome(string value)
{
	int index = value.length() - 1;

	for (int x = 0; x < value.length() / 2; x++)
	{
		if (value[x] != value[index])
		{
			return false;
		}
		index--;
	}

	return true;
}


string PalindromicSubstring(string str) 
{
	string temp;
	string result;

	for (int x = 0; x < str.length(); x++)
	{
		temp = str[x];

		// Loop to check for a substring palindrome
		for (int y = x + 1; y < str.length(); y++)
		{
			temp += str[y];

			// Only analyze when we have at least 3 characters and the substring is a palindrome
			if (temp.length() >= 3 && palindrome(temp))
			{
				// Keep track of the longest palindrome substring
				if (temp.length() > result.length())
				{
					result = temp;
				}
			}
			
		}
	}

	if (result.length() == 0)
	{
		return "none";
	}
	else
	{
		return result;
	}
}


int main()
{
	cout << PalindromicSubstring("abracecars") << endl; // racecar
	cout << PalindromicSubstring("hellosannasmith") << endl; // sannas
	cout << PalindromicSubstring("abcdefgg") << endl; // none
	cout << PalindromicSubstring("acaaca") << endl; // acaaca

	return 0;
}