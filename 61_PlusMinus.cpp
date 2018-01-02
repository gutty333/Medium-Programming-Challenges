// For this challenge you will need to determine how to add or subtract numbers to end up with zero.
/*
have the function PlusMinus(num) read the num parameter being passed which will be a combination of 1 or more single digits, and determine if it's possible to separate the digits with either a plus or minus sign to get the final expression to equal zero. For example: if num is 35132 then it's possible to separate the digits the following way,
3 - 5 + 1 + 3 - 2, and this expression equals zero. Your program should return a string of the signs you used, so for this example your program should return -++-. If it's not possible to get the digit expression to equal zero, return the string not possible.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int PlusMinus(int num) 
{

}

int main() 
{

	cout << PlusMinus(35132) << endl; // -++-
	cout << PlusMinus(199) << endl; // not possible
	cout << PlusMinus(26712) << endl; // -+--

	return 0;

}