// For this challenge you will be manipulating a string using dashes (-).
// have the function DashInsertII(str) insert dashes ('-') between each two odd numbers and insert asterisks ('*') between each two even numbers in str. For example: if str is 4546793 the output should be 454*67-9-3. Don't count zero as an odd or even number. 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string DashInsertII(int num) {

	stringstream convert;
	convert << num;
	string temp = convert.str();
	string temp2;

	for (int x = 0; x < temp.length()-1; x++)
	{
		if (temp[x] == '0' || temp[x+1] == '0')
		{
			temp2.push_back(temp[x]);
			continue;
		}
		else if (temp[x] % 2 == 0 && temp[x + 1] % 2 == 0)
		{
			temp2.push_back(temp[x]);
			temp2.push_back('*');
		}
		else if (temp[x] % 2 != 0 && temp[x + 1] % 2 != 0)
		{
			temp2.push_back(temp[x]);
			temp2.push_back('-');
		}
		else
		{
			temp2.push_back(temp[x]);
		}
	}
	temp2.push_back(temp[temp.length() - 1]);
	return temp2;
}

int main() {

	// keep this function call here
	cout << DashInsertII(99946) << endl; // 9-9-94*6
	cout << DashInsertII(56647304) << endl; // 56*6*47-304
	cout << DashInsertII(4546793) << endl; // 454*67-9-3
	cout << DashInsertII(1562) << endl; // 1-56*2
	cout << DashInsertII(77993) << endl; // 7-7-9-9-3
	return 0;
}