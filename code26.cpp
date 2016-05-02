// For this challenge you will encode a given string following a specific rule.
// have the function NumberEncoding(str) take the str parameter and encode the message according to the following rule: encode every letter into its corresponding numbered position in the alphabet. Symbols and spaces will also be used in the input. For example: if str is "af5c a#!" then your program should return 1653 1#!. 

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

string NumberEncoding(string str) {
	// Making all the characters in the string lower case
	// This will make it easier to determine alphabet position calculation later on.
	for (int x = 0; x < str.length(); x++)
	{
		str[x] = tolower(str[x]);
	}
	
	string temp;
	for (int y = 0; y < str.length(); y++)
	{
		// If the character is a letter than find the position
		if (str[y] >= 'a' && str[y] <= 'z')
		{
			// Calculation to find the position
			// Since we are dealing with lowercase only, this is simple to do with ascii value
			// To handle double digits we would need to take the result as an int than store as a string datatype
			int position = int(str[y]) - 96;
			stringstream convert;
			convert << position;
			temp += convert.str();
		}
		else
		{
			// If we find symbols or other numbers just do it, JUST DO IT
			temp.push_back(str[y]);
		}
	}
	return temp;
}

int main() {

	// keep this function call here
	cout << NumberEncoding("hello 45") << endl; // 85121215 45
	cout << NumberEncoding("jaj-a") << endl; // 10110-1
	cout << NumberEncoding("af5c a#!") << endl; // 1653 1#!
	return 0;

}