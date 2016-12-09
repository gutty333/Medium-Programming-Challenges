// For this challenge you will be determining the largest number of unique characters between two letters.
/*
have the function MatchingCharacters(str) take the str parameter being passed and determine the largest number of unique characters that exists between a pair of matching letters anywhere in the string. For example: if str is "ahyjakh" then there are only two pairs of matching letters, the two a's and the two h's. Between the pair of a's there are 3 unique characters: h, y, and j. Between the h's there are 3 unique characters: y, j, a, and k. So for this example your program should return 4.

Another example: if str is "ghececgkaem" then your program should return 5 because the most unique characters exists within the farthest pair of e characters. The input string may not contain any character pairs, and in that case your program should just return 0. The input will only consist of lowercase alphabetic characters.
*/


#include <iostream>
#include <string>
using namespace std;

int MatchingCharacters(string str) 
{
	int high = 0;
	for (int x = 0; x < str.length(); x++)
	{
		// Values used to locate a pair
		char temp = str[x];
		int start = x;
		int end=start;

		for (int y = x + 1; y < str.length(); y++)
		{
			// Locate the end of that pair
			if (str[y] == temp)
			{
				end = y;
			}
		}

		// Loop to check for unique characters within that pair
		string uniqueValues;
		for (int z = start+1; z < end; z++)
		{
			// If the character is unique add it to our list
			if (uniqueValues.find(str[z]) == -1)
			{
				uniqueValues += str[z];
			}
		}

		// Keep track of the largest number of unique characters
		if (uniqueValues.length() > high)
		{
			high = uniqueValues.length();
		}
	}

	return high;
}

int main() 
{
	cout << MatchingCharacters("ahyjakh") << endl; // 4
	cout << MatchingCharacters("ghececgkaem") << endl; // 5
	cout << MatchingCharacters("mmmerme") << endl; // 3
	cout << MatchingCharacters("abccdefghi") << endl; // 0

	return 0;
}