// For this challenge you will compute the length of the longest consecutive subsequence.
/*
have the function LongestConsecutive(arr) take the array of positive integers stored in arr and return the length of the longest consecutive subsequence (LCS). An LCS is a subset of the original list where the numbers are in sorted order, from lowest to highest, and are in a consecutive, increasing order. The sequence does not need to be contiguous and there can be several different subsequences. For example: if arr is [4, 3, 8, 1, 2, 6, 100, 9] then a few consecutive sequences are [1, 2, 3, 4], and [8, 9]. For this input, your program should return 4 because that is the length of the longest consecutive subsequence.
*/

#include <iostream>
#include <string>
using namespace std;

/*
order the values from least to greatest
iterate and analyze consecutive sequence
keep count of the highest sequence
*/

void sort(int list[], int size)
{
	bool swap;
	int temp;

	do
	{
		swap = false;

		for (int x = 0; x < size - 1; x++)
		{
			if (list[x] > list[x + 1])
			{
				temp = list[x];
				list[x] = list[x + 1];
				list[x + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

int LongestConsecutive(int arr[], int size) 
{
	int length, high;
	high = 0;
	length = 1;

	// Sort the values
	sort(arr, size);

	// Loop to iterate and find consecutive sequences
	for (int x = 0; x < size-1; x++)
	{
		if (arr[x] + 1 == arr[x + 1])
		{
			length++;
		}
		else if (arr[x] == arr[x + 1])
		{
			continue;
		}
		else
		{
			if (length > high)
			{
				high = length;
			}

			length = 1;
		}
	}
	
	if (length > high)
	{
		high = length;
	}

	return high;
}

int main() 
{
	int A[] = { 4, 3, 8, 1, 2, 6, 100, 9};
	int B[] = { 6, 7, 3, 1, 100, 102, 6, 12 };
	int C[] = { 5, 6, 1, 2, 8, 9, 7 };
	int D[] = { 11, 6, 6, 5, 7, 10, 1, 2, 3, 12, 9, 8 };
	int E[] = { 5, 15, 16, 21, 4, 5, 10, 9, 8, 22, 23, 7, 3, 2, 24, 1, 6 };
	cout << LongestConsecutive(A, sizeof(A) / sizeof(A[0])) << endl; // 4
	cout << LongestConsecutive(B, sizeof(B) / sizeof(B[0])) << endl; // 2
	cout << LongestConsecutive(C, sizeof(C) / sizeof(C[0])) << endl; // 5
	cout << LongestConsecutive(D, sizeof(D) / sizeof(D[0])) << endl; // 8
	cout << LongestConsecutive(E, sizeof(E) / sizeof(E[0])) << endl; // 10

	return 0;
}