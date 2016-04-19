// For this challenge you will determine if all the brackets in a string are correctly matched up.
// have the function MultipleBrackets(str) take the str parameter being passed and return 1 #ofBrackets if the brackets are correctly matched and each one is accounted for. Otherwise return 0. For example: if str is "(hello [world])(!)", then the output should be 1 3 because all the brackets are matched and there are 3 pairs of brackets, but if str is "((hello [world])" the the output should be 0 because the brackets do not correctly match up. Only "(", ")", "[", and "]" will be used as brackets. If str contains no brackets return 1. 


#include <iostream>
#include <string>
using namespace std;

string MultipleBrackets(string str) {

	// code goes here   
	return str;

}

int main() {

	// keep this function call here
	cout << MultipleBrackets("(coder)[byte)]") << endl; // 0
	cout << MultipleBrackets("(c([od]er)) b(yt[e])") << endl; // 1 5
	cout << MultipleBrackets() << endl;
	return 0;

}