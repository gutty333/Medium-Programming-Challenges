// For this challenge you will determine if the brackets in a string are correctly matched up.
// have the function BracketMatcher(str) take the str parameter being passed and return 1 if the brackets are correctly matched and each one is accounted for. Otherwise return 0. For example: if str is "(hello (world))", then the output should be 1, but if str is "((hello (world))" the the output should be 0 because the brackets do not correctly match up. Only "(" and ")" will be used as brackets. If str contains no brackets return 1. 

#include <iostream>
#include <string>
using namespace std;

int BracketMatcher(string str) {

	int count = 0; // Used to keep count of opening brackets

	for (int x = 0; x < str.length(); x++)
	{
		if (str[x] == '(') // Keep track of opening brackets
		{
			count++;
		}
		// If we find a closing bracket signify a match by decreasing the count
		// The important rule is that for a closing tag to exist an opening tag must be found first
		// If the rule is broken output 0
		else if (str[x] == ')') 
		{
			count--;
			if (count < 0)
			{
				return 0;
			}
		}
	}

	// Condition to assure that all the tags were closed
	if (count == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main() {

	// keep this function call here 
	cout << BracketMatcher("(hello (world))") << endl; // 1
	cout << BracketMatcher("((hello (world))") << endl; // 0
	cout << BracketMatcher("( and )") << endl; // 1
	cout << BracketMatcher("(coder)(byte))") << endl; // 0
	cout << BracketMatcher("(c(oder)) b(yte)") << endl; // 1
	cout << BracketMatcher("(hi there (wow nice) this is (crazy wild))") << endl; // 1
	cout << BracketMatcher("(the force(is strong)") << endl; // 0
	cout << BracketMatcher("(soo easy even a (caveman (can do this stuff)) now this is radical (yeah rock on) sweet )") << endl; // 1  ((())())
	cout << BracketMatcher("Jo()(in) the (dark side)") << endl; // 1
	cout << BracketMatcher("Join) the (dark side)") << endl; // 0
	return 0;

}