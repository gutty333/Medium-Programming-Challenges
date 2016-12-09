// For this challenge you will be searching within a 2D matrix.
/*
have the function BitmapHoles(strArr) take the array of strings stored in strArr, which will be a 2D matrix of 0 and 1's, and determine how many holes, or contiguous regions of 0's, exist in the matrix. A contiguous region is one where there is a connected group of 0's going in one or more of four directions: up, down, left, or right. For example: if strArr is ["10111", "10101", "11101", "11111"], then this looks like the following matrix:

1 0 1 1 1
1 0 0 0 1
1 0 1 0 1
1 1 1 1 1

For the input above, your program should return 2 because there are two separate contiguous regions of 0's, which create "holes" in the matrix. You can assume the input will not be empty.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// NOT FINISHED

/*
analyze the string array and look for 0s
When found check if they are part of a contiguous region
This will check the 4 directions
Keep track of the zeros we have found
*/


bool groupSet(string arr[], int size, int row, int col, vector <string> & list)
{
	int currentX = row;
	int currentY = col;

	list[row][col] = '0';


	while ()
	{
		// Checking Up
		if (row != 0 && arr[row - 1][col] == '0' && list[row - 1][col] == '*')
		{
			// Update the movement
			row--;




		}


		// Checking Down
		if (row != size - 1 && arr[row + 1][col] == '0' && list[row + 1][col] == '*')
		{

		}

		// Checking Left
		if (col != 0 && arr[row][col - 1] == '0')
		{

		}

		// Checking Right
		if (col != arr[0].length() - 1 && arr[row][col + 1] == '0')
		{

		}
	}

	

	return false;
}

int BitmapHoles(string strArr[], int size) {
	int holes = 0;
	
	vector <string> tempMatrix(size); // Setting a secondary string/matrix for keeping track of connected groups

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < strArr[row].length(); col++)
		{
			if (strArr[row][col] == '0')
			{

			}
		}
	}

	return holes;
}

int main() {
	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	string A[] = { "01111", "01101", "00011", "11110" };
	string B[] = { "1011", "0010" };
	string C[] = { "10111", "10101", "11101", "11111" };
	//cout << BitmapHoles(A, sizeof(A) / sizeof(A[0])) << endl; // 3
	//cout << BitmapHoles(B, sizeof(B) / sizeof(B[0])) << endl; // 2
	cout << BitmapHoles(C, sizeof(C) / sizeof(C[0])) << endl; // 2 
	return 0;
}