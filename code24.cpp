// For this challenge you will be determining whether a number is part of the Fibonacci sequence.
// have the function FibonacciChecker(num) return the string yes if the number given is part of the Fibonacci sequence. This sequence is defined by: Fn = Fn-1 + Fn-2, which means to find Fn you add the previous two numbers up. The first two numbers are 0 and 1, then comes 1, 2, 3, 5 etc. If num is not in the Fibonacci sequence, return the string no. 

#include <iostream>
#include <string>
using namespace std;

// Recursive implementation
// Will start with default values of 1
// Will go through the Fibonacci sequence until number is found or the sequence number is greater than the target value
string FibonacciChecker(int x, int y,int num) {
	if (num == 0 || num == 1) // If the number is 1 or 0 
	{
		return "yes";
	}
	else if (x + y == num) // When number is part of the sequence
	{
		return "yes";
	}
	else if (x + y < num) // While still less than the target, continue through the sequence
	{
		return FibonacciChecker(x + y, x, num);
	}
	else
	{
		return "no";
	}
}

int main() {

	// keep this function call here
	cout << FibonacciChecker(1,1,34) << endl; // yes
	cout << FibonacciChecker(1,1,54) << endl; // no
	cout << FibonacciChecker(1,1,13) << endl; // yes
	cout << FibonacciChecker(1,1,22) << endl; // no
	return 0;

}