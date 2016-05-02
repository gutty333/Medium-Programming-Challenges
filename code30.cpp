// For this challenge you will determine if all the brackets in a string are correctly matched up.
// have the function MultipleBrackets(str) take the str parameter being passed and return 1 #ofBrackets if the brackets are correctly matched and each one is accounted for. Otherwise return 0. For example: if str is "(hello [world])(!)", then the output should be 1 3 because all the brackets are matched and there are 3 pairs of brackets, but if str is "((hello [world])" the the output should be 0 because the brackets do not correctly match up. Only "(", ")", "[", and "]" will be used as brackets. If str contains no brackets return 1. 


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string MultipleBrackets(string str) {

	int count = 0, count2 = 0;
	int total = 0;

	// Overall this is quite similar to the previous bracket matcher problem
	for (int x = 0; x < str.length(); x++)
	{
		// Checking for the ( opening bracket
		if (str[x] == '(')
		{
			count++;
		}
		else if (str[x] == '[') // Checking for the [ bracket
		{
			count2++;
		}
		else if (str[x] == ')') // Check that () brackets open and close
		{
			count--;
			total++;
			if (count < 0)
			{
				return "0";
			}
		}
		else if (str[x] == ']') // Check that [] brackets open and close
		{
			count2--;
			total++;
			if (count2 < 0)
			{
				return "0";
			}
		}
	}

	if (count == 0 && count2 == 0 && total == 0)
	{
		return "1";
	}
	else if (count == 0 && count2 == 0 && total > 0)
	{
		stringstream convert;
		convert << 1 << " " << total;
		return convert.str();
	}
	else
	{
		return "0";
	}
}

int main() {

	// keep this function call here
	cout << MultipleBrackets("(coder)[byte)]") << endl; // 0
	cout << MultipleBrackets("(c([od]er)) b(yt[e])") << endl; // 1 5
	cout << MultipleBrackets("(hello [world])(!)") << endl; // 1 3
	cout << MultipleBrackets("((hello [world])") << endl; // 0
	cout << MultipleBrackets("Attack on titan is awesome") << endl; // 1
	cout << MultipleBrackets("()code[rb]yte() yes()[ss][[") << endl; // 0
	return 0;

}