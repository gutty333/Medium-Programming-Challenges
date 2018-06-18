// For this challenge you will determine how quickly you can reach the end of an array.
/*
have the function ArrayMinJumps(arr) take the array of integers stored in arr, where each integer represents the maximum number of steps that can be made from that position, and determine the least amount of jumps that can be made to reach the end of the array. For example: if arr is
[1, 5, 4, 6, 9, 3, 0, 0, 1, 3] then your program should output the number 3 because you can reach the end of the array from the beginning via the following steps:
1 -> 5 -> 9 -> END or 1 -> 5 -> 6 -> END. Both of these combinations produce a series of 3 steps. And as you can see, you don't always have to take the maximum number of jumps at a specific position, you can take less jumps even though the number is higher.

If it is not possible to reach the end of the array, return -1.
*/

#include <iostream>
using namespace std;

/*
start at the first index
have a condition to check if taking 1 step is enough
or if starting value is <= 0

traverse however many steps the current location provides
as we traverse we analyze the values along the way
collect the sum of current value + lastValue
if >= end, return the result
else record the result and check if is the highest possible.
*/
int ArrayMinJumps(int arr[], int size)
{
	int result = 1;
	int totalSteps = arr[0];
	int index = 0;
	int highest;

	// base case conditions
	if (size == 1 && arr[0] > 0)
	{
		return 0;
	}
	else if (totalSteps >= size-1)
	{
		return result;
	}
	else if (totalSteps <= 0)
	{
		return -1;
	}

	// analyzing the values
	while (index < size)
	{
		// updating our jump/step count
		result++;

		// analyzing the values during our movement
		for (int x = 0; x < totalSteps; x++)
		{
			index++;

			if (x == 0)
			{
				highest = index;
			}

			// condition to check if current value is enough to reach the end
			if (index + arr[index] >= size-1)
			{
				return result;
			}
			// condition to locate the best selection we can make
			else if (index + arr[index] >= arr[highest] + index)
			{
				highest = index;
			}
		}

		// updating our index and totalSteps
		index = highest;
		totalSteps = arr[index];

		// check if is possible to make jumps
		if (totalSteps == 0)
		{
			return -1;
		}
	}

	return result;
}

int main() 
{
	int A[] = { 1, 5, 4, 6, 9, 3, 0, 0, 1, 3 };
	int B[] = { 3, 4, 2, 1, 1, 100 };
	int C[] = { 1, 3, 6, 8, 2, 7, 1, 2, 1, 2, 6, 1, 2, 1, 2 };
	int D[] = { 4, 5, 2, 1, 5, 3, 1, 4, 6, 2, 1, 0, 1, 0, 4, 3, 0, 1, 2, 4, 5 };
	int E[] = { 1, 0, 0, 2 };
	int F[] = { 4 };
	int G[] = {1,1};

	cout << ArrayMinJumps(A, sizeof(A)/sizeof(A[0])) << endl; // 3
	cout << ArrayMinJumps(B, sizeof(B) / sizeof(B[0])) << endl; // 2
	cout << ArrayMinJumps(C, sizeof(C) / sizeof(C[0])) << endl; // 4
	cout << ArrayMinJumps(D, sizeof(D) / sizeof(D[0])) << endl; // 5
	cout << ArrayMinJumps(F, sizeof(F) / sizeof(F[0])) << endl; // 0
	cout << ArrayMinJumps(G, sizeof(G) / sizeof(G[0])) << endl; // 1
	cout << ArrayMinJumps(E, sizeof(E) / sizeof(E[0])) << endl; // -1
	
	return 0;
}