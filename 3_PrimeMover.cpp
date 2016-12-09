// For this challenge you will be returning a certain prime number.
// have the function PrimeMover(num) return the numth prime number. The range will be from 1 to 10^4. For example: if num is 16 the output should be 53 as 53 is the 16th prime number. 

#include <iostream>
#include <cmath>
using namespace std;

int PrimeMover(int num) {
	
	int count = 0;
	bool prime;

	for (int x = 2; x <= pow(10, 4); x++)
	{
		// If the number is greater than 100
		// Check if there are any divisors 
		if (x > 100)
		{
			prime = true;
			for (int y = 2; y < pow(10, 4); y++)
			{
				// Ignore when the divisor is the same as the number
				if (y == x)
				{
					continue;
				}
				else if (x % y == 0) // If there is a number end the loop and signify that it is not prime
				{
					prime = false;
					break;
				}
			}

			if (prime)
			{
				count++;
			}
		}
		else if (x > 10 && x<100 && !(x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0 || x % 9 == 0))
		{
			count++;
		}
		else if (x == 2 || x == 3 || x == 5 || x == 7)
		{
			count++;
		}

		if (count == num)
		{
			return x;
		}
	}
}

int main() {

	// keep this function call here
	cout << PrimeMover(9) << endl; // 23
	cout << PrimeMover(1000) << endl; // 541
	cout << PrimeMover(16) << endl; // 53
	return 0;

}