// For this challenge you will be determining if a string is a palindrome.
// have the function PalindromeTwo(str) take the str parameter being passed and return the string true if the parameter is a palindrome, (the string is the same forward as it is backward) otherwise return the string false. The parameter entered may have punctuation and symbols but they should not affect whether the string is in fact a palindrome. For example: "Anne, I vote more cars race Rome-to-Vienna" should return true. 

#include <iostream>
#include <string>
using namespace std;

string PalindromeTwo(string str) {

	string temp;
	// Creating a new string with only letters
	for (int x = 0; x < str.length(); x++)
	{
		if ((str[x] >= 'a' && str[x] <= 'z') || (str[x] >= 'A' && str[x] <= 'Z'))
		{
			temp.push_back(tolower(str[x]));
		}
	}

	string temp2 = temp;
	int index = 0;
	// Comparing the strings
	for (int y = temp.length() - 1; y >= 0; y--)
	{
		if (temp2[index] != temp[y])
		{
			return "false";
		}
		index++;
	}
	return "true";
}

int main() {

	// keep this function call here
	cout << PalindromeTwo("Noel - sees Leon") << endl; // true
	cout << PalindromeTwo("A war at Tarawa!") << endl; // true
	cout << PalindromeTwo("Anne, I vote more cars race Rome-to-Vienna") << endl; // true
	return 0;

}