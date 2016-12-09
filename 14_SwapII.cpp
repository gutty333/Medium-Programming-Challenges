// For this challenge you will be manipulating numbers in a string based on the characters.
// have the function SwapII(str) take the str parameter and swap the case of each character. Then, if a letter is between two numbers (without separation), switch the places of the two numbers. For example: if str is "6Hello4 -8World, 7 yes3" the output should be 4hELLO6 -8wORLD, 7 YES3. 

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string SwapII(string str) {

	char temp;;

	for (int x = 0; x < str.length(); x++)
	{
		// Checking the cases of the letters
		if (isupper(str[x]))
		{
			str[x] = tolower(str[x]);
		}
		else if (islower(str[x]))
		{
			str[x] = toupper(str[x]);
		}
		// Checking for when the string has a number
		if (str[x] >= '0' && str[x] <= '9')
		{
			temp = str[x];
			bool pattern = true;
			// Store the first number and continue to traverse the string to see if it follows the rules
			for (int y = x+1; y < str.length() && pattern; y++)
			{
				pattern = false;
				// If the number stored is at the end of the string end the loop
				if (y > str.length())
				{
					break;
				}
				else if (str[y] == ' ') // If it reaches the end of the word/separation
				{
					break;
				}
				else if ((str[y] >= 'a' && str[y] <= 'z') || (str[y] >= 'A' && str[y] <= 'Z'))
				{
					// Continue iterating if you keep coming across letters
					pattern = true;
				}
				else if (str[y] >= '0' && str[y] <= '9' && (str[y-1] >= 'a' && str[y-1] <= 'z') || (str[y-1] >= 'A' && str[y-1] <= 'Z'))
				{
					// Analyze once another number has been found
					// Also check that prior to this number there is a letter
					str[x] = str[y];
					str[y] = temp;
					break;
				}
			}
		}
	}
	return str;
}

int main() {

	// keep this function call here
	cout << SwapII("Hello -5LOL6") << endl; // hELLO -6lol5
	cout << SwapII("2S 6 du5d4e") << endl; // 2s 6 DU4D5E
	cout << SwapII("6Hello4 -8World, 7 yes3") << endl; // 4hELLO6 -8wORLD, 7 YES3
	return 0;

}

