// For this challenge you will be searching within a 2D matrix.
/*
have the function BitmapHoles(strArr) take the array of strings stored in strArr, which will be a 2D matrix of 0 and 1's, and determine how many holes, or contiguous regions of 0's, exist in the matrix. A contiguous region is one where there is a connected group of 0's going in one or more of four directions: up, down, left, or right. For example: if strArr is ["10111", "10101", "11101", "11111"], then this looks like the following matrix:

1 0 1 1 1
1 0 1 0 1
1 0 1 0 1
1 1 1 1 1

For the input above, your program should return 2 because there are two separate contiguous regions of 0's, which create "holes" in the matrix. You can assume the input will not be empty.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
analyze the string array and look for 0s
When found check if they are part of a contiguous region
This will check the 4 directions
Keep track of the zeros we have found
*/

// Function to check if the current holes is part of a contiguous region
// If so keep track of the zeros that are part of that region
// It will recursively search in all 4 directions, not repeating the last step or any previous steps
void groupSet(string arr[], int size, int row, int col, vector <string> & list, bool check)
{
	list[row][col] = '0';
	bool found = check;

	while (found)
	{
		found = false;

		// Checking Up
		if (row != 0 && arr[row - 1][col] == '0' && list[row - 1][col] == '*')
		{
			// Update the movement
			row--;
			found = true;
			groupSet(arr, size, row, col, list, found);
		}

		// Checking Down
		if (row != size - 1 && arr[row + 1][col] == '0' && list[row + 1][col] == '*')
		{
			row++;
			found = true;
			groupSet(arr, size, row, col, list, found);
		}

		// Checking Left
		if (col != 0 && arr[row][col - 1] == '0' && list[row][col-1] == '*')
		{
			col--;
			found = true;
			groupSet(arr, size, row, col, list, found);
		}

		// Checking Right
		if (col != arr[0].length() - 1 && arr[row][col + 1] == '0' && list[row][col + 1] == '*')
		{
			col++;
			found = true;
			groupSet(arr, size, row, col, list, found);
		}
	}
}

int BitmapHoles(string strArr[], int size) {
	int holes = 0;
	
	vector <string> tempMatrix(size); // Setting a secondary string/matrix for keeping track of connected groups

	// Setting temp values to our list
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < strArr[row].length(); col++)
		{
			tempMatrix[row].push_back('*');
		}
	}
	

	// Loop to find any 0s in the matrix
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < strArr[row].length(); col++)
		{
			// Condition count the holes
			if (strArr[row][col] == '0' && tempMatrix[row][col] == '*')
			{
				// function call that will find if this current hole has contiguous zeros
				// It will fill out our temp matrix with any zeros that are contiguous
				// This will help iterating so we avoid counting any holes that are part of a contiguous family
				groupSet(strArr, size, row, col, tempMatrix, true);
				holes++;
			}
		}
	}

	return holes;
}

int main() 
{
	string A[] = { "01111", "01101", "00011", "11110" };
	string B[] = { "1011", "0010" };
	string C[] = { "10111", "10101", "11101", "11111" };
	cout << BitmapHoles(A, sizeof(A) / sizeof(A[0])) << endl; // 3
	cout << BitmapHoles(B, sizeof(B) / sizeof(B[0])) << endl; // 2
	cout << BitmapHoles(C, sizeof(C) / sizeof(C[0])) << endl; // 2 
	return 0;
}