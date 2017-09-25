// For this challenge you will determine the largest area under a histogram.
/*
have the function HistogramArea(arr) read the array of non-negative integers stored in arr which will represent the heights of bars on a graph (where each bar width is 1), and determine the largest area underneath the entire bar graph. For example: if arr is [2, 1, 3, 4, 1] then this looks like the following bar graph:

You can see in the above bar graph that the largest area underneath the graph is covered by the x's. The area of that space is equal to 6 because the entire width is 2 and the maximum height is 3, therefore 2 * 3 = 6. Your program should return 6. The array will always contain at least 1 element.
*/

#include <iostream>
#include <string>
using namespace std;

/*
as we traverse the array we will analyze each height
each height will be compared  to its neighbor height 
if the neighboring heights are greater than or equal to current height than update its width
after we calculate the area for that height
*/
int HistogramArea(int arr[], int size) 
{
	int maxArea = 0;

	for (int current = 0; current < size; current++)
	{
		int width = 1;
		int moveRight = current + 1;
		int moveLeft = current - 1;

		// loop to check all the neighbors to the right of the current height
		// recall we only track neighbors that are greater than or equal to current height
		// if is valid we update the width
		while (moveRight < size && arr[moveRight] >= arr[current])
		{
			width++;

			moveRight++;
		}

		// similar to checking the right neighbors here we check to the left of the array
		while (moveLeft >= 0 && arr[moveLeft] >= arr[current])
		{
			width++;

			moveLeft--;
		}

		// Now we calculate the area for this height based on our rule
		if (width * arr[current] > maxArea)
		{
			maxArea = width* arr[current];
		}
	}

	return maxArea;
}

int main() {
	int A[] = { 2, 1, 3, 4, 1 };
	int B[] = { 6, 3, 1, 4, 12, 4 };
	int C[] = { 5, 6, 7, 4, 1 };

	cout << HistogramArea(A, sizeof(A) / sizeof(A[0])) << endl; // 6
	cout << HistogramArea(B, sizeof(B) / sizeof(B[0])) << endl; // 12
	cout << HistogramArea(C, sizeof(C) / sizeof(C[0])) << endl; // 16
	return 0;
}
