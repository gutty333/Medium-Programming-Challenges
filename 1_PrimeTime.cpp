// For this challenge you will be determining if an argument is a prime number.
// have the function PrimeTime(num) take the num parameter being passed and return the string true if the parameter is a prime number, otherwise return the string false. The range will be between 1 and 2^16. 

#include <iostream>
#include <string>
using namespace std;

string PrimeTime(int num) {

	for (int x = 2; x <= 10; x++)
	{
		if (x == num)
		{
			continue;
		}
		else if (num%x == 0)
		{
			return "false";
		}
	}

	return "true";
}

int main() {

	// keep this function call here
	cout << PrimeTime(19) << endl; // true
	cout << PrimeTime(110) << endl; // false
	cout << PrimeTime(2) << endl; // true
	cout << PrimeTime(4) << endl; // false
	cout << PrimeTime(5) << endl; // true
	cout << PrimeTime(432) << endl; // false
	cout << PrimeTime(784546) << endl; // false
	return 0;

}
