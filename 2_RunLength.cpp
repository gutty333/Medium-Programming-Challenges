// For this challenge you will determine the Run Length Encoding of a string.
// have the function RunLength(str) take the str parameter being passed and return a compressed version of the string using the Run-length encoding algorithm. This algorithm works by taking the occurrence of each repeating character and outputting that number along with a single character of the repeating sequence. For example: "wwwggopp" would return 3w2g1o2p. The string will not contain any numbers, punctuation, or symbols. 

#include <iostream>
#include <string>
using namespace std;

string RunLength(string str) 
{
	string temp;
	char letter = ' ';
	int count;

	for (int x = 0; x < str.length(); x++)
	{
		count = 1; // Set the repetition number 1
		if (str[x] == letter) // Ignore if the letter has been already recorded
		{
			continue;
		}
		else
		{
			letter = str[x];
		}

		// Loop to check how many times the letter repeats
		for (int y = x; y < str.length()-1; y++)
		{
			if (x == str.length() - 1)
			{
				break;
			}
			else if (str[y] == letter && str[y] == str[y + 1])
			{
				count++;
			}
		}

		// Insert the results into a new string
		temp.push_back(char(count+48));
		temp.push_back(letter);
	}

	return temp;
}

int main() {

	// keep this function call here
	cout << RunLength("aabbcde") << endl; // 2a2b1c1d1e
	cout << RunLength("wwwbbbw") << endl; // 3w3b1w
	cout << RunLength("wwwggopp") << endl; // 3w2g1o2p
	return 0;

}