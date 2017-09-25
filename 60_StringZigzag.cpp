//  For this challenge you will be printing a string in a particular zig-zag format.
/*
have the function StringZigzag(strArr) read the array of strings stored in strArr, which will contain two elements, the first some sort of string and the second element will be a number ranging from 1 to 6. The number represents how many rows to print the string on so that it forms a zig-zag pattern. For example: if strArr is ["coderbyte", "3"] then this word will look like the following if you print it in a zig-zag pattern with 3 rows:

c	   r	   e
 o   e   b   t
   d       y


Your program should return the word formed by combining the characters as you iterate through each row, so for this example your program should return the string creoebtdy.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


/*
create a matrix based on the data provided
the length of the string element will represent the column count
the input number will represent the row count
we than traverse the first string element and store its characters into the matrix based on their location
their column will be parallel to the index of their string
for the row position we will keep a counter
with each iteration it updates, when it reaches the bottom it will decrement back to the top

For the output a straight solution is to traverse our matrix from top to bottom and extract only valid characters
*/
string StringZigzag(string strArr[], int size)
{
	int colSize = strArr[0].length();
	int rowSize;
	istringstream(strArr[1]) >> rowSize;

	if (rowSize <= 1)
	{
		return strArr[0];
	}

	vector < vector <char> > matrixMap(rowSize);

	// loop to create a matrix map with garbage values
	for (int row = 0; row < rowSize; row++)
	{
		for (int col = 0; col < colSize; col++)
		{
			matrixMap[row].push_back('#');
		}
	}

	int currentRow = 0;
	bool traverseDown = true;

	// loop to fill the matrix map with the characters from our input string
	for (int currentCol = 0; currentCol < strArr[0].length(); currentCol++)
	{
		// adding the current character to the correct location
		matrixMap[currentRow][currentCol] = strArr[0][currentCol];

		// update our row index
		if (traverseDown)
		{
			currentRow++;
		}
		else
		{
			currentRow--;
		}

		// Condition to determine if we traverse to the bottom or the top
		if (currentRow == rowSize)
		{
			currentRow -= 2;
			traverseDown = false;
		}
		else if (currentRow == -1 && !traverseDown)
		{
			currentRow += 2;
			traverseDown = true;
		}
		
	}
	
	string result = "";
	//loop to extract the characters in their new correct order
	for (int row = 0; row < rowSize; row++)
	{
		for (int col = 0; col < colSize; col++)
		{
			if (matrixMap[row][col] != '#')
			{
				result += matrixMap[row][col];
			}
		}
	}

	return result;
}

int main() 
{
	string A[] = { "coderbyte", "3" };
	string B[] = { "cat", "5" };
	string C[] = { "kaamvjjfl", "4" };
	string D[] = { "aeettym", "1" };

	cout << StringZigzag(A, sizeof(A) / sizeof(A[0])) << endl; // creoebtdy
	cout << StringZigzag(B, sizeof(B) / sizeof(B[0])) << endl; // cat
	cout << StringZigzag(C, sizeof(C) / sizeof(C[0])) << endl; // kjajfavlm
	cout << StringZigzag(D, sizeof(D) / sizeof(D[0])) << endl; // aeettym
	return 0;
}