// For this challenge you will determine the Greatest Common Factor between two numbers.
// have the function Division(num1,num2) take both parameters being passed and return the Greatest Common Factor. That is, return the greatest number that evenly goes into both numbers with no remainder. For example: 12 and 16 both are divisible by 1, 2, and 4 so the output should be 4. The range for both parameters will be from 1 to 10^3. 

#include <iostream>
using namespace std;

int Division(int num1, int num2) {

	int high = 1;
	int size;
	if (num1 >= num2)
	{
		size = num1;
	}
	else
	{
		size = num2;
	}
	for (int x = 1; x < size; x++)
	{
		if (num1%x == 0 && num2%x == 0 && x > high)
		{
			high = x;
		}
	}
	return high;
}

int main() {

	// keep this function call here
	cout << Division(7, 2) << endl; // 1
	cout << Division(36, 54) << endl; // 18
	cout << Division(12, 16) << endl; // 4
	return 0;

}