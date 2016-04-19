// For this challenge you will manipulate a string of characters using a simple reduction method.
// have the function StringReduction(str) take the str parameter being passed and return the smallest number you can get through the following reduction method. The method is: Only the letters a, b, and c will be given in str and you must take two different adjacent characters and replace it with the third. For example "ac" can be replaced with "b" but "aa" cannot be replaced with anything. This method is done repeatedly until the string cannot be further reduced, and the length of the resulting string is to be outputted. For example: if str is "cab", "ca" can be reduced to "b" and you get "bb" (you can also reduce it to "cc"). The reduction is done so the output should be 2. If str is "bcab", "bc" reduces to "a", so you have "aab", then "ab" reduces to "c", and the final string "ac" is reduced to "b" so the output should be 1. 

#include <iostream>
#include <string>
using namespace std;

// Function to reduce the string
string reduce(string word, int index, char letter)
{
	word[index] = letter;
	word.erase(word.begin()+(index + 1));
	return word;
}

int StringReduction(string str) {
	bool swap;
	int index = 0;

	do
	{
		while (index < str.length() - 1)
		{
			swap = false;

			// Checking if the characters are adjacent
			if (str[index] == str[index + 1])
			{
				index++;
			}
			else
			{
				// If Adjacent replace it with the third character
				if (str[index] == 'a')
				{
					if (str[index + 1] == 'b')
					{
						str = reduce(str, index, 'c');
						index = index + 1;
					}
					else if (str[index + 1] == 'c')
					{
						str = reduce(str, index, 'b');
						index = index + 1;
					}
					swap = true;
				}
				else if (str[index] == 'b')
				{
					if (str[index + 1] == 'a')
					{
						str = reduce(str, index, 'c');
						index = index + 1;
					}
					else if (str[index + 1] == 'c')
					{
						str = reduce(str, index, 'a');
						index = index + 1;
					}
					swap = true;
				}
				else if (str[index] == 'c')
				{
					if (str[index + 1] == 'a')
					{
						str = reduce(str, index, 'b');
						index = index + 1;
					}
					else if (str[index + 1] == 'b')
					{
						str = reduce(str, index, 'a');
						index = index + 1;
					}
					swap = true;
				}
			}
		}
		// Safeguard that if the string is reduced to 1 character end the loop
		if (str.length() == 1)
		{
			swap = false;
		}
		// Reset the index back, to traverse the new edited string
		index = 0; 
	} while (swap);
	
	return str.length();
}

int main() {

	// keep this function call here
	cout << StringReduction("abcabc") << endl; // 2
	cout << StringReduction("cccc") << endl; // 4
	cout << StringReduction("cab") << endl; // 2
	cout << StringReduction("bcab") << endl; // 1
	return 0;

}