// For this challenge you will be searching a string for a particular substring.
// have the function KUniqueCharacters(str) take the str parameter being passed and find the longest substring that contains k unique characters, where k will be the first character from the string. The substring will start from the second position in the string because the first character will be the integer k. For example: if str is "2aabbacbaa" there are several substrings that all contain 2 unique characters, namely: ["aabba", "ac", "cb", "ba"], but your program should return "aabba" because it is the longest substring. If there are multiple longest substrings, then return the first substring encountered with the longest length. k will range from 1 to 6. 

#include <iostream>
#include <string>
using namespace std;

// Linear search function to check if a character is currently in that string
bool search(string temp, char letter)
{
	for (int x = 0; x < temp.length(); x++)
	{
		if (letter == temp[x])
		{
			return true;
		}
	}
	return false;
}

// Function that will determine how many unique characters are in the specified string
int uniqueCount(string temp)
{
	string uniqueString;

	for (int x = 0; x < temp.length(); x++)
	{
		if (!search(uniqueString, temp[x])) // Insert only the uniquer character into the string
		{
			uniqueString.push_back(temp[x]);
		}
	}
	return uniqueString.length(); // return the current total number of unique characters
}

string KUniqueCharacters(string str) {
	// getting the first character as an integer
	int unique = int(str[0]) - 48;

	int index = 1;
	string temp, temp2;

	while (index < str.length())
	{
		for (int x = index; x < str.length(); x++)
		{
			temp.push_back(str[x]);

			// Condition for when we reach pass the k integer
			// delete the last character for that substring
			if (uniqueCount(temp) > unique)
			{
				x--;
				temp.pop_back();

				// Compare to keep the largest substring
				if (temp.length() > temp2.length())
				{
					temp2 = temp;
				}
				temp.clear();
			}
		}

		// We compare once more in the case, that the substring continues to the end
		if (temp.length() > temp2.length())
		{
			temp2 = temp;
		}
		temp.clear();
		index++;
	}

	return temp2;
}

int main() {

	// keep this function call here
	cout << KUniqueCharacters("3aabacbebebe") << endl; // "cbebebe"
	cout << KUniqueCharacters("2aabbcbbbadef") << endl; // "bbcbbb"
	cout << KUniqueCharacters("2aabbacbaa") << endl; // "aabba"
	return 0;
}