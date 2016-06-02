// For this challenge you will be searching within a 2D matrix.
/*
have the function BitmapHoles(strArr) take the array of strings stored in strArr, which will be a 2D matrix of 0 and 1's, and determine how many holes, or contiguous regions of 0's, exist in the matrix. A contiguous region is one where there is a connected group of 0's going in one or more of four directions: up, down, left, or right. For example: if strArr is ["10111", "10101", "11101", "11111"], then this looks like the following matrix:

1 0 1 1 1
1 0 1 0 1
1 1 1 0 1
1 1 1 1 1

For the input above, your program should return 2 because there are two separate contiguous regions of 0's, which create "holes" in the matrix. You can assume the input will not be empty.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to check is the current 0 is not in a connected group
bool singleSet(string arr[], int size, int row, int col)
{
	cout << "hi" << endl;
	// Out of bound conditions
	if (row == 0 && col == 0) // Top Left Corner
	{
		if (arr[row + 1][col] == '1' && arr[row][col + 1] == '1') 
			return true;
		else
			return false;
	}
	else if (row == 0 && col == arr[row].length() - 1) // Top Right Corner
	{
		if (arr[row + 1][col] == '1' && arr[row][col - 1] == '1')
			return true;
		else
			return false;
	}
	else if (row == size - 1 && col == 0) // Bottom Left Corner
	{
		if (arr[row - 1][col] == '1' && arr[row][col + 1] == '1') 
			return true;
		else
			return false;
	}
	else if (row == size - 1 && col == arr[row].length() - 1) // Bottom Right Corner
	{
		if (arr[row][col - 1] == '1' && arr[row - 1][col] == '1') 
			return true;
		else
			return false;
	}
	else if (row == 0) // Top Row
	{
		if (arr[row][col + 1] == '1' && arr[row][col - 1] == '1' && arr[row + 1][col] == '1')
			return true;
		else
			return false;
	}
	else if (col == 0) // Left Column
	{
		if (arr[row - 1][col] == '1' && arr[row + 1][col] == '1' && arr[row][col + 1] == '1') 
			return true;
		else
			return false;
	}
	else if (col == arr[row].length() - 1) //  Right Column
	{
		if (arr[row + 1][col] == '1' && arr[row - 1][col] == '1' && arr[row][col - 1] == '1') 
			return true;
		else
			return false;
	}
	else if (row == size - 1) // Bottom Row
	{
		if (arr[row - 1][col] == '1' && arr[row][col - 1] == '1' && arr[row][col + 1] == '1') 
			return true;
		else
			return false;
	}
	else if (arr[row - 1][col] == '1' && arr[row][col - 1] == '1' && arr[row][col + 1] == '1' && arr[row + 1][col] == '1') // Any Other Location
		return true;
	else
		return false;
}

// Will add 0s to the temp matrix if they are part of a connected group
void matrixUpdate(vector<string>& matrix, int row, int col, int size)
{


	if (row <= size - 1 && row > 0)
	{
		row--;
		// Loop to check if there are connected 0s in this specific direction
		while (matrix[row][col] == '0')
		{
			matrix[row][col] = '0';
			row--;
			if (row = -1) // Bound Check
			{
				break;
			}
		}
		row++; // Set to the previous index which was a 0
	}
	if (row >= 0 && row <size-1)
	{
		row++;
		while (matrix[row][col] == '0')
		{
			matrix[row][col] = '0';
			row++;
			if (row = size)
			{
				break;
			}
		}
		row--;
	}
	if (col <= matrix[row].length() - 1 && col > 0)
	{
		col--;
		while (matrix[row][col] == '0')
		{
			matrix[row][col] = '0';
			col--;
			if (col = -1)
			{
				break;
			}
		}
		col++;
	}
	if (col >= 0 && col < matrix[row].length() - 1)
	{
		col++;
		while (matrix[row][col] == '0')
		{
			matrix[row][col] = '0';
			col++;
			if (col = matrix[row].length())
			{
				break;
			}
		}
		col--;
	}
}

// Function to check that the current 0 is part of a set/group of 0s
bool groupSet(vector <string>& matrix, int row, int col, int size)
{
	// Assure this is part of a new set
	// If the current 0 has already been found than ignore it and return false
	if (matrix[row][col] == '0')
	{
		return false;
	}
	else // If it is a new set, find the connected 0s
	{
		matrix[row][col] = '0';
		// Condition for the corners

		matrixUpdate(matrix, row, col, size);


		if ((row == 0 && col == 0) || (row == 0 && col == matrix[row].length() - 1) || (row == size - 1 && col == 0) || (row == size - 1 && col == matrix[row].length() - 1))
		{
			// Top Left Corner
			if (row == 0 && col == 0)
			{
				matrixUpdate(matrix, row, col, size);
			}
			// Top Right Corner
			if (row = 0 && col == matrix[row].length() - 1 && matrix[row + 1][col] == '0')
			{
				matrixUpdate(matrix, row, col, size);
			}
			if (row = 0 && col == matrix[row].length() - 1 && matrix[row][col - 1] == '0')
			{
				matrixUpdate(matrix, row, col, size);
			}
			//Bottom Left Corner
			if (row == size - 1 && col == 0 && matrix[row - 1][col] == '0')
			{
				matrixUpdate(matrix, row, col, size);
			}
			if (row == size - 1 && col == 0 && matrix[row][col + 1] == '0')
			{
				matrixUpdate(matrix, row, col, size);
			}
			// Bottom Right Corner
			if (row == size - 1 && col == matrix[row].length() - 1 && matrix[row][col - 1] == '0')
			{
				matrixUpdate(matrix, row, col, size);
			}
			if (row == size - 1 && col == matrix[row].length() - 1 && matrix[row - 1][col] == '0')
			{
				matrixUpdate(matrix, row, col, size);
			}
		}
		// Conditions for outer rows or outer columns
		else if (row == 0 || row == size - 1 || col == 0 || col == matrix[row].length() - 1)
		{
			// Top Row
			if (row = 0 && (matrix[row][col + 1] == '0' || matrix[row][col - 1] == '0' || matrix[row + 1][col] == '0'))
			{
				matrixUpdate(matrix, row, col, size);
			}
			// Bottom Row
			if (row = size - 1 && (matrix[row - 1][col] == '0' || matrix[row][col + 1] == '0' || matrix[row][col - 1] == '0'))
			{
				matrixUpdate(matrix, row, col, size);
			}
			// Left Column
			if (col == 0 && (matrix[row + 1][col] == '0' || matrix[row - 1][col] == '0' || matrix[row][col + 1] == '0'))
			{
				matrixUpdate(matrix, row, col, size);
			}
			// Right Column
			if (col == matrix[row].length() - 1 && (matrix[row + 1][col] == '0' || matrix[row - 1][col] == '0' || matrix[row][col - 1] == '0'))
			{
				matrixUpdate(matrix, row, col, size);
			}
		}
		else
		{
			matrixUpdate(matrix, row, col, size);
		}

		return true;
	}
}

int BitmapHoles(string strArr[], int size) {
	int holes = 0;
	
	vector <string> tempMatrix(size); // Setting a secondary string/matrix for keeping track of connected groups

	// Filling the temp matrix with a misc character at the start, not including zero
	// This will help with keep track of which continuous sets we have found already
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < strArr[0].length(); y++)
		{
			tempMatrix[x].push_back('*');
		}
	}

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < strArr[row].length(); col++)
		{
			// Loop through matrix to find any 0s
			if (strArr[row][col] == '0')
			{
				// Conditions to check if the 0 is in a connected group or on its own
				if (singleSet(strArr, size, row, col))
				{
					holes++;
				}
				else if (groupSet(tempMatrix, row,col,size))
				{
					holes++;
				}
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
	cout << BitmapHoles(A, sizeof(A) / sizeof(A[0])) << endl; // 3
	cout << BitmapHoles(B, sizeof(B) / sizeof(B[0])) << endl; // 2
	cout << BitmapHoles(C, sizeof(C) / sizeof(C[0])) << endl; // 2 
	return 0;
}