// For this challenge you will determine if you can arrange a number to be a prime number.
// have the function PrimeChecker(num) take num and return 1 if any arrangement of num comes out to be a prime number, otherwise return 0. For example: if num is 910, the output should be 1 because 910 can be arranged into 109 or 019, both of which are primes. 

#include <iostream>
#include <string>
using namespace std;


int PrimeChecker(int num) {
	
}

int main() {

	// keep this function call here
	cout << PrimeChecker(98) << endl; // 1
	cout << PrimeChecker(598) << endl; // 1
	cout << PrimeChecker(910) << endl; // 1
	cout << PrimeChecker(22) << endl; // 0
	cout << PrimeChecker(71) << endl; // 1
	return 0;

}