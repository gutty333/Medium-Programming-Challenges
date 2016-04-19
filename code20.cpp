// For this challenge you will be determining the multiples of a specific number.
// have the function ThreeFiveMultiples(num) return the sum of all the multiples of 3 and 5 that are below num. For example: if num is 10, the multiples of 3 and 5 that are below 10 are 3, 5, 6, and 9, and adding them up you get 23, so your program should return 23. The integer being passed will be between 1 and 100. 

#include <iostream>
#include <string>
using namespace std;

int ThreeFiveMultiples(int num) {
	int total = 0;
	// Find multiples of both 3 and 5
	// Iterate all number less than num
	// Calculate the ones that are multiples
	for (int x = 1; x < num; x++)
	{
		if (x % 3 == 0 || x % 5 == 0)
		{
			total += x;
		}
	}

	return total;
}

int main() {

	// keep this function call here
	cout << ThreeFiveMultiples(6) << endl; // 8
	cout << ThreeFiveMultiples(1) << endl; // 0
	cout << ThreeFiveMultiples(10) << endl; // 23
	cout << ThreeFiveMultiples(31) << endl;
	cout << ThreeFiveMultiples(17) << endl;
	return 0;

}