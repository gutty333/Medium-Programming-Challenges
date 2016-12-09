// For this challenge you will determine the next greatest number using the same numbers of a given argument.
// have the function PermutationStep(num) take the num parameter being passed and return the next number greater than num using the same digits. For example: if num is 123 return 132, if it's 12453 return 12534. If a number has no greater permutations, return -1 (ie. 999). 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int PermutationStep(int num) {
	// Converting to a string
	// This will allow us to do some editing
	string temp;
	stringstream convert;
	convert << num;
	temp = convert.str();
	
	// Checking to see if it has no greater permutations
	bool same;
	// Here we are analyzing the length 
	// Example if num is 43333 = -1, 33 = -1, 9 = -1, etc
	if (temp.length() <= 2) 
	{
		if (temp[0] == temp[1])
		{
			return -1;
		}
		same = false;
	}
	else
	{
		same = true;
	}
	for (int x = 1; x < temp.length() - 1 && same; x++)
	{
		same = false;
		if (temp[x] == temp[x + 1])
		{
			same = true;
		}
	}
	if (same || temp.length() == 1)
	{
		return -1;
	}

	char value;
	for (int y = temp.length() - 1; y > 0; y--)
	{
		// Break point to check for the next greatest whole
		// Example if number is 1007560 it will now be 1007650
		// Will traverse from the back of the string
		if (temp[y] > temp[y - 1])
		{
			value = temp[y];
			temp[y] = temp[y - 1];
			temp[y - 1] = value;

			// Next will we optimize the number since, we want the second greatest
			// Example is we now have 1007650 we need to optimize to 1007605
			bool less;
			do
			{
				less = false;
				// Loop to check if numbers need to be shifted
				// If changes occurred we will analyze the number again to safeguard any errors
				// We are only checking until the range from which we made the initial change
				// Meaning we are only from analyzing 50 here, since 6 was are initial change
				for (int z = temp.length() - 1; z > y; z--)
				{
					if (temp[z] < temp[z - 1])
					{
						value = temp[z];
						temp[z] = temp[z - 1];
						temp[z - 1] = value;
						less = true;
					}
				}
			} while (less);

			// Convert to an integer for output
			istringstream(temp) >> num;
			return num;
		}
	}
}

int main() {

	// keep this function call here
	cout << PermutationStep(11121) << endl; // 11211
	cout << PermutationStep(41352) << endl; // 41523
	cout << PermutationStep(123) << endl; // 132
	cout << PermutationStep(12453) << endl; // 12534
	cout << PermutationStep(999) << endl; // -1
	cout << PermutationStep(754912) << endl; // 754921
	cout << PermutationStep(1112113421) << endl; // 1112114321 -> 1112114123
	cout << PermutationStep(76666666) << endl; // -1
	cout << PermutationStep(12) << endl; // 21
	return 0;
}