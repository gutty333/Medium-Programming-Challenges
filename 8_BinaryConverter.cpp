// For this challenge you will be converting a number from binary to decimal.
// have the function BinaryConverter(str) return the decimal form of the binary value. For example: if 101 is passed return 5, or if 1000 is passed return 8. 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int BinaryConverter(string str) {
	
	int total = 0; // Will determine the decimal total
	
	for (int x = 0; x < str.length(); x++)
	{
		// If the switch is true perform the calculation
		if (str[x] == '1')
		{
			// This is based on the formula
			// Example 2^0 + 2^1+ 2^2+......
			total += pow(2, (str.length() - x) - 1);
		}
	}
	return total;
}

int main() {

	// keep this function call here
	cout << BinaryConverter("100101") << endl; // 37
	cout << BinaryConverter("011") << endl; // 3
	cout << BinaryConverter("101") << endl; // 5 
	cout << BinaryConverter("1000") << endl; // 8 
	return 0;

}