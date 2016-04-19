// For this challenge you will remove duplicate elements from an array.
// have the function DistinctList(arr) take the array of numbers stored in arr and determine the total number of duplicate entries. For example if the input is [1, 2, 2, 2, 3] then your program should output 2 because there are two duplicates of one of the elements. 

#include <iostream>
#include <string>
using namespace std;

// Function used to aid in the distinctList
// Will sort the array which in turn allows for an easier solution
// For the case in which some repeats are scattered
void sortArray(int array[], int size)
{
	int temp;
	bool swap;
	do
	{
		swap = false;
		for (int x = 0; x < size - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				temp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

int DistinctList(int arr[], int size) {

	int count = 0;
	
	// Calling the sort function
	sortArray(arr, size);
	
	// Traversing the new array and checking for duplicates
	for (int x = 0; x < size-1; x++)
	{
		if (arr[x] == arr[x + 1])
		{
			count++;
		}
	}
	return count;
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	int A[] = { 0, -2, -2, 5, 5, 5 };
	int B[] = { 100, 2, 101, 4 };
	int C[] = { 1, 2, 2, 2, 3 };
	cout << DistinctList(A, sizeof(A)/sizeof(A[0])) << endl; // 3
	cout << DistinctList(B, sizeof(B) / sizeof(B[0])) << endl; // 0
	cout << DistinctList(C, sizeof(C) / sizeof(C[0])) << endl; // 2
	return 0;

}