// For this challenge you will determine if you can arrange a number to be a prime number.
// have the function PrimeChecker(num) take num and return 1 if any arrangement of num comes out to be a prime number, otherwise return 0. For example: if num is 910, the output should be 1 because 910 can be arranged into 109 or 019, both of which are primes. 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Function to check if the argument is prime
bool isPrime(string number)
{
	int value;
	istringstream(number) >> value;
	if (value == 1)
	{
		return false;
	}
	for (int x = 2; x < value; x++)
	{
		if (value%x == 0)
		{
			return false;
		}
	}
	return true;
}

int PrimeChecker(int num) {
	// Convert to a string for editing
	stringstream convert;
	convert << num;
	string temp = convert.str();
	char current;
	
	//Check if the number is prime when is only 1 digit
	if (temp.length() == 1)
	{
		if (isPrime(temp))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	// Check if the number is prime when there are only 2 digits
	else if (temp.length() == 2)
	{
		if (isPrime(temp))
		{
			return 1;
		}
		current = temp[0];
		temp[0] = temp[1];
		temp[1] = current;
		if (isPrime(temp))
		{
			return 1;
		}
	}
	else
	{
		// Loop to arrange the number when dealing with multiple digits
		for (int x = 0; x < temp.length(); x++)
		{
			for (int y = 0; y < temp.length()-1; y++)
			{
				if (isPrime(temp)) // Check the number to see if is prime
				{
					return 1;
				}
				else // Rearrange the digits
				{
					current = temp[y];
					temp[y] = temp[y + 1];
					temp[y + 1] = current;
				}
			}
		}
	}

	return 0;
}

int main() {

	// keep this function call here
	cout << PrimeChecker(98) << endl; // 1
	cout << PrimeChecker(598) << endl; // 1
	cout << PrimeChecker(910) << endl; // 1
	cout << PrimeChecker(22) << endl; // 0
	cout << PrimeChecker(71) << endl; // 1
	cout << PrimeChecker(100) << endl; // 0
	return 0;

}