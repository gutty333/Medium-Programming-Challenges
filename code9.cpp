// For this challenge you will determine the mode, the number that appears most frequently, in an array.
// have the function SimpleMode(arr) take the array of numbers stored in arr and return the number that appears most frequently (the mode). For example: if arr contains [10, 4, 5, 2, 4] the output should be 4. If there is more than one mode return the one that appeared in the array first (ie. [5, 10, 10, 6, 5] should return 5 because it appeared first). If there is no mode return -1. The array will not be empty. 

#include <iostream>
#include <string>
using namespace std;

int SimpleMode(int arr[], int size) {

	int value = -1, count, high = 0;

	for (int x = 0; x < size; x++)
	{
		// Keep track of time the number repeats and the index of that repeating number
		count = 1;

		for (int y = 0; y < size; y++)
		{
			if (x == y)
			{
				continue;
			}
			
			if (arr[x] == arr[y])
			{
				count++;
			}

			// Only replace the value with a number that has a higher repetition
			if (count > high)
			{
				value = arr[x];
				high = count;
			}
		}
	}

	if (high == 1)
	{
		return -1;
	}
	else
	{
		return value;
	}
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	int A[] = {5,5,2,2,1};
	int B[] = {3,4,1,6,10};
	int C[] = {10,4,5,2,4};
	int D[] = {5,10,10,6,5};
	int E[] = { 4, 4, 5, 6, 7, 8, 8, 8, 8, 8 };
	cout << SimpleMode(A, sizeof(A) / sizeof(A[0])) << endl; // 5
	cout << SimpleMode(B, sizeof(B)/sizeof(B[0])) << endl;  // -1
	cout << SimpleMode(C, sizeof(C) / sizeof(C[0])) << endl; // 4
	cout << SimpleMode(D, sizeof(D) / sizeof(D[0])) << endl; // 5
	cout << SimpleMode(E, sizeof(E) / sizeof(E[0])) << endl; // 8
	return 0;
}

