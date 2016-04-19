// For this challenge you will determine how to order an array of numbers consecutively.
// have the function Consecutive(arr) take the array of integers stored in arr and return the minimum number of integers needed to make the contents of arr consecutive from the lowest number to the highest number. For example: If arr contains [4, 8, 6] then the output should be 2 because two numbers need to be added to the array (5 and 7) to make it a consecutive array of numbers from 4 to 8. Negative numbers may be entered as parameters and no array will have less than 2 elements. 

#include <iostream>
#include <string>
using namespace std;

void bubbleSort(int arr[], int size)
{
	int temp;
	bool swap;

	do
	{
		swap = false;

		for (int x = 0; x < size - 1; x++)
		{
			if (arr[x] > arr[x + 1])
			{
				temp = arr[x];
				arr[x] = arr[x + 1];
				arr[x + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

int Consecutive(int arr[], int size) {

	int difference;
	int total = 0;

	// Sort the array in descending order
	bubbleSort(arr, size);

	// Step through the array and analyze the difference between each value
	// Since it is in order we just compare the values next to each other and find the gap
	for (int x = 0; x < size-1; x++)
	{
		difference = arr[x + 1] - arr[x];
		total += (difference - 1);
	}

	return total;
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	int A[] = { 5, 10, 15 };
	int B[] = { -2, 10, 4 };
	int C[] = {4,8,6};
	cout << Consecutive(A, sizeof(A) / sizeof(A[0])) << endl; // 8
	cout << Consecutive(B, sizeof(B) / sizeof(B[0])) << endl; // 10
	cout << Consecutive(C, sizeof(C) / sizeof(C[0])) << endl; // 2
	return 0;

}