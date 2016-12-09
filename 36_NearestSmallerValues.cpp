// For this challenge you will determine the nearest smaller value for each number in an array.
/*
have the function NearestSmallValues(arr) take the array of integers stored in arr, and for each element in the list, search all the previous values for the nearest element that is smaller than the current element and create a new list from these numbers. If there is no element before a certain position that is smaller, input a -1. For example: if arr is [5, 2, 8, 3, 9, 12] then the nearest smaller values list is [-1, -1, 2, 2, 3, 9]. The logic is as follows:

For 5, there is no smaller previous value so the list so far is [-1]. For 2, there is also no smaller previous value, so the list is now [-1, -1]. For 8, the nearest smaller value is 2 so the list is now [-1, -1, 2]. For 3, the nearest smaller value is also 2, so the list is now [-1, -1, 2, 2]. This goes on to produce the answer above. Your program should take this final list and return the elements as a string separated by a space: -1 -1 2 2 3 9
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/*
iterate through each value
iterate backwards and find any smaller values
if none found insert -1 else, insert that small value
convert the new list to a string
*/

string NearestSmallerValues(int arr[], int size) 
{
	vector <int> list;

	// Loop to iterate through each value
	for (int x = 0; x < size; x++)
	{
		bool found = false;

		// Nested loop checking for any previous smaller values
		for (int y = x - 1; y >= 0 && !found; y--)
		{
			if (arr[y] < arr[x])
			{
				list.push_back(arr[y]);
				found = true;
			}
		}

		// Condition for when no smaller values were found we insert -1
		if (!found)
		{
			list.push_back(-1);
		}
	}

	// Taking the values from our list and formatting to a string
	stringstream convert;
	for (int x = 0; x < size; x++)
	{
		convert << list[x] << " ";
	}

	return convert.str();
}

int main() 
{
	int A[] = { 5, 2, 8, 3, 9, 12 };
	int B[] = { 5, 3, 1, 9, 7, 3, 4, 1 };
	int C[] = { 2, 4, 5, 1, 7 };
	cout << NearestSmallerValues(A, sizeof(A) / sizeof(A[0])) << endl; // -1 -1 2 2 3 9
	cout << NearestSmallerValues(B, sizeof(B) / sizeof(B[0])) << endl; // -1 -1 -1 1 1 1 3 1
	cout << NearestSmallerValues(C, sizeof(C) / sizeof(C[0])) << endl; // -1 2 4 -1 1
	return 0;

}