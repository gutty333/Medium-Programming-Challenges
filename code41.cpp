// For this challenge you will determine the largest amount of water you can trap within a boundary.
/*
have the function TrappingWater(arr) take the array of non-negative integers stored in arr, and determine the largest amount of water that can be trapped. The numbers in the array represent the height of a building (where the width of each building is 1) and if you imagine it raining, water will be trapped between the two tallest buildings. For example: if arr is [3, 0, 0, 2, 0, 4] then this array of building heights looks like the following picture if we draw it out:

Now if you imagine it rains and water gets trapped in this picture, then it'll look like the following (the x's represent water):


This is the most water that can be trapped in this picture, and if you calculate the area you get 10, so your program should return 10.
*/

#include <iostream>
using namespace std;

/*
find the highest peak
after find the next highest peak
analyze the distance between the peaks
this will allow us to trap the most amount of water
once we have a starting and end point we can iterate and calculate area
compare each step to the second highest peak
example if the second peak is 4 and our current step is 1 than area for that step is 3
continue until we reach the end
sum up all the individual area to get total area
*/

int TrappingWater(int arr[], int size) 
{
	int high, high2;
	int index, index2;
	high = high2 = 0;

	// Loop to find the highest peak
	for (int x = 0; x < size; x++)
	{
		if (arr[x] >=  high)
		{
			high = x;
			index = x;
		}
	}

	// Loop to find the second highest peak
	for (int x = 0; x < size; x++)
	{
		if (x == index)
		{
			continue;
		}

		if (arr[x] > high2)
		{
			high2 = arr[x];
			index2 = x;
		}
	}

	// Analyzing the distance
	while ((index - index2) == 1)
	{
		// The second peak now becomes the highest peak
		int temp = index;
		high = high2;
		index = index2;
		
		// We iterate to find a new second peak
		high2 = 0;
		for (int x = 0; x < size; x++)
		{
			if (x == index || x == temp)
			{
				continue;
			}

			if (arr[x] > high2)
			{
				high2 = arr[x];
				index2 = x;
			}
		}
	}

	int total = 0;
	// Loop to find the area of each step
	for (int x = index2 + 1; x < index; x++)
	{
		total += (high2 - arr[x]) * 1;
	}

	return total;
}

int main() 
{
	int A[] = { 3, 0, 0, 2, 0, 4 };
	int B[] = { 1, 2, 1, 2 };
	int C[] = { 0, 2, 4, 0, 2, 1, 2, 6 };
	int D[] = { 5, 4, 3, 2, 1, 10, 20 };

	cout << TrappingWater(A, sizeof(A)/sizeof(A[0])) << endl; // 10
	cout << TrappingWater(B, sizeof(B) / sizeof(B[0])) << endl; // 1
	cout << TrappingWater(C, sizeof(C) / sizeof(C[0])) << endl; // 11
	cout << TrappingWater(D, sizeof(D) / sizeof(D[0])) << endl; // 10
	return 0;
}
