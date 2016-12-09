// For this challenge you will determine the next number in a sequence.
// have the function LookSaySequence(num) take the num parameter being passed and return the next number in the sequence according to the following rule: to generate the next number in a sequence read off the digits of the given number, counting the number of digits in groups of the same digit. For example, the sequence beginning with 1 would be: 1, 11, 21, 1211, ... The 11 comes from there being "one 1" before it and the 21 comes from there being "two 1's" before it. So your program should return the next number in the sequence given num. 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int LookSaySequence(int num) {
	// Convert to a string for editing
	stringstream convert;
	convert << num;
	string temp = convert.str();

	int count = 1;
	string temp2;
	for (int x = 0; x < temp.length(); x++)
	{
		// Checking the last two numbers of the sequence
		if (x == temp.length() - 1 && temp[x] != temp[x - 1])
		{
			temp2.push_back(char(count + 48));
			temp2.push_back(temp[x]);
			count = 1;
		}
		// Checking the next number in the sequence
		else if (temp[x] == temp[x + 1])
		{
			count++;
		}
		else
		{
			temp2.push_back(char(count+48));
			temp2.push_back(temp[x]);
			count = 1;
		}
	}

	istringstream(temp2) >> num;
	return num;
}

int main() {

	// keep this function call here
	cout << LookSaySequence(1211) << endl; //111221
	cout << LookSaySequence(2466) << endl; // 121426
	cout << LookSaySequence(111221) << endl; // 312211
	return 0;

}