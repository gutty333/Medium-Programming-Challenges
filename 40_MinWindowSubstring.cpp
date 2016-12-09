// For this challenge you will be searching for the optimal substring of k characters.
/*
have the function MinWindowSubstring(strArr) take the array of strings stored in strArr, which will contain only two strings, the first parameter being the string N and the second parameter being a string K of some characters, and your goal is to determine the smallest substring of N that contains all the characters in K. For example: if strArr is ["aaabaaddae", "aed"] then the smallest substring of N that contains the characters a, e, and d is "dae" located at the end of the string. So for this example your program should return the string dae.

Another example: if strArr is ["aabdccdbcacd", "aad"] then the smallest substring of N that contains all of the characters in K is "aabd" which is located at the beginning of the string. Both parameters will be strings ranging in length from 2 to 50 characters and all of K's characters will exist somewhere in the string N. Both strings will only contains lowercase alphabetic characters.
*/

#include <iostream>
#include <string>
using namespace std;

/*
get the target string which is the second element
analyze the first element to find the substring
you will iterate through each character and check if the substring from that specified character contains all characters from the target
check the length of the substrings and keep track of the smallest one
*/


// function to check if the current substring has all the characters from the target string
bool stringSearch(string current, string value)
{
	// The current string must be either same length or greater than the target string
	if (current.length() < value.length())
	{
		return false;
	}

	// loop to check that the characters are found in the substring
	for (int x = 0; x < value.length(); x++)
	{
		bool found = false;
		for (int y = 0; y < current.length(); y++)
		{
			// Condition that checks for characters found
			// If found update the current and remove the character
			// This will help in the case we search for similar characters i.e aaaab
			if (value[x] == current[y])
			{
				current.erase(current.begin() + y);
				found = true;
				break;
			}
		}

		if (!found)
		{
			return false;
		}
	}

	return true;
}

string MinWindowSubstring(string strArr[]) 
{  
	string target = strArr[1];
	string temp, result;
	int low = 100 * 100;

	for (int x = 0; x < strArr[0].length()-1; x++)
	{
		temp += strArr[0][x];
		for (int y = x + 1; y < strArr[0].length(); y++)
		{
			// Condition to check if the substring is valid
			if (stringSearch(temp, target))
			{
				if (temp.length() < low) // Keep track of the smallest substring
				{
					low = temp.length();
					result = temp;
				}

				break;
			}
			else // Keep updating if not valid
			{
				temp += strArr[0][y];
			}

			// Condition for when analyzing the last character of our substring
			if (y == strArr[0].length() - 1 && stringSearch(temp, target))
			{
				if (temp.length() < low) // Keep track of the smallest substring
				{
					low = temp.length();
					result = temp;
				}
			}
		}
		temp = ""; // reset our substring for our next starting character
	}

	return result;
}

int main() 
{
	string A[] = { "aaabaaddae", "aed" };
	string B[] = { "aabdccdbcacd", "aad" };
	string C[] = { "ahffaksfajeeubsne", "jefaa" };
	string D[] = { "aaffhkksemckelloe", "fhea" };
	cout << MinWindowSubstring(A) << endl; // dae
	cout << MinWindowSubstring(B) << endl; // aabd
	cout << MinWindowSubstring(C) << endl; // aksfaje
	cout << MinWindowSubstring(D) << endl; // affhkkse
	return 0;
}
