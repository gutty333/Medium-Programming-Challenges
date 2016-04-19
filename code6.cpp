// For this challenge you will determine if string 1 can be rearranged into string 2.
// have the function StringScramble(str1,str2) take both parameters being passed and return the string true if a portion of str1 characters can be rearranged to match str2, otherwise return the string false. For example: if str1 is "rkqodlw" and str2 is "world" the output should return true. Punctuation and symbols will not be entered with the parameters. 

#include <iostream>
#include <string>
using namespace std;

string StringScramble(string str1, string str2) {
	
	bool found;
	int index = -1;

	for (int x = 0; x < str2.length(); x++)
	{
		found = false;
		for (int y = 0; y < str1.length(); y++)
		{
			if (str2[x] == str1[y] && y != index)
			{
				index = y; // Safeguarding that we do not use another previously utilized letter
				found = true; // Determine whether the letter was found
			}
		}
		if (!found)
		{
			return "false";
		}
	}

	return "true";
}

int main() {

	// keep this function call here
	cout << StringScramble("cdore","coder") << endl; // true
	cout << StringScramble("h3llko", "hello") << endl; // false
	cout << StringScramble("rkqodlw","world") << endl; // true
	cout << StringScramble("win33er", "winner") << endl; // false
	return 0;

}