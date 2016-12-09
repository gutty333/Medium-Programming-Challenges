// For this practice test you will determine the maximum profit that can be made in a range of stock prices.
// have the function StockPicker(arr) take the array of numbers stored in arr which will contain integers that represent the amount in dollars that a single stock is worth, and return the maximum profit that could have been made by buying stock on day x and selling stock on day y where y > x. For example: if arr is [44, 30, 24, 32, 35, 30, 40, 38, 15] then your program should return 16 because at index 2 the stock was worth $24 and at index 6 the stock was then worth $40, so if you bought the stock at 24 and sold it at 40, you would have made a profit of $16, which is the maximum profit that could have been made with this list of stock prices. 
// If there is not profit that could have been made with the stock prices, then your program should return -1. For example : arr is[10, 9, 8, 2] then your program should return -1

#include <iostream>
#include <string>
using namespace std;

int StockPicker(int arr[], int size) {

	int value;
	int high = -1;

	// Loop to analyze each stock
	for (int x = 0; x < size-1; x++)
	{
		// Loop to compare which is the maximum profit
		// This takes the stock on day x and day y, to find difference
		for (int y = x+1; y < size; y++)
		{
			if (arr[x] < arr[y])
			{
				value = arr[y] - arr[x];

				if (value > high)
				{
					high = value;
				}
			}
		}
	}

	return high;
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	int A[] = { 10, 12, 4, 5, 9 };
	int B[] = { 14, 20, 4, 12, 5, 11 };
	int C[] = { 44, 30, 24, 32, 35, 30, 40, 38, 15 };
	int D[] = { 10, 9, 8, 2 };
	cout << StockPicker(A, sizeof(A) / sizeof(A[0])) << endl; // 5
	cout << StockPicker(B, sizeof(B) / sizeof(B[0])) << endl; // 8
	cout << StockPicker(C, sizeof(C) / sizeof(C[0])) << endl; // 16
	cout << StockPicker(D, sizeof(D) / sizeof(D[0])) << endl; // -1
	return 0;
}