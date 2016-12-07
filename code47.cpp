// For this challenge you will determine if a path exists in a boolean matrix.
/*
have the function MatrixPath(strArr) take the strArr parameter being passed which will be a 2D matrix of 0 and 1's of some arbitrary size, and determine if a path of 1's exists from the top-left of the matrix to the bottom-right of the matrix while moving only in the directions: up, down, left, and right. If a path exists your program should return the string true, otherwise your program should return the number of locations in the matrix where if a single 0 is replaced with a 1, a path of 1's will be created successfully. If a path does not exist and you cannot create a path by changing a single location in the matrix from a 0 to a 1, then your program should return the string not possible. For example: if strArr is ["11100", "10011", "10101", "10011"] then this looks like the following matrix:

1 1 1 0 0
1 0 0 1 1
1 0 1 0 1
1 0 0 1 1



1 1 1 0 0
1 1 0 1 1
1 0 1 0 1
1 0 0 1 1

For the input above, a path of 1's from the top-left to the bottom-right does not exist. But, we can change a 0 to a 1 in 2 places in the matrix, namely at locations:
[0,3] or [1,2]. So for this input your program should return 2. The top-left and bottom-right of the input matrix will always be 1's.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*
start at the top left as your current location
check for different path options from the current location
If there are multiple options keep track of the location to reset back
Move in one of the path options and keep track of which option you took

*/



void OptionFinder(int row, int col, string matrix[], int size, vector <vector <int> > &paths)
{
	vector <int> temp;
	int options = 0;

	// Condition to find path options taken
	// Will also do boundary check
	// Going Left
	if (col != 0 && matrix[row][col - 1] == '1')
	{
		options++;
	}
	
	// Going Right
	if (col != matrix[row].length-1 && matrix[row][col + 1] == '1')
	{
		options++;
	}

	// Going Down
	if (row != size && matrix[row+1][col] == '1')
	{
		options++;
	}

	// Going UP
	if (row != 0 && matrix[row - 1][col] == '1')
	{
		options++;
	}

	if (options > 1)
	{

	}
}


string MatrixPath(string strArr[], int size) 
{
	int currentRow = 0;
	int currentCol = 0;
	


}

int main() 
{
	string A[] = { "11100", "10011", "10101", "10011" };
	string B[] = { "10000", "11011", "10101", "11001" };
	string C[] = { "1000001", "1001111", "1010101" };

	cout << MatrixPath(A, sizeof(A) / sizeof(A[0])) << endl; // 2
	cout << MatrixPath(A, sizeof(A) / sizeof(A[0])) << endl; // 1
	cout << MatrixPath(A, sizeof(A) / sizeof(A[0])) << endl; // not possible
	return 0;
}