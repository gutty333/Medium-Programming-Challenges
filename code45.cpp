//  For this challenge you will print a 2D matrix in spiral order.
/*
have the function MatrixSpiral(strArr) read the array of strings stored in strArr which will represent a 2D N matrix, and your program should return the elements after printing them in a clockwise, spiral order. You should return the newly formed list of elements as a string with the numbers separated by commas. For example: if strArr is "[1, 2, 3]", "[4, 5, 6]", "[7, 8, 9]" then this looks like the following 2D matrix:

1 2 3
4 5 6
7 8 9


1 2 3 5
4 5 6 8
7 8 9 4
1 2 3 6
4 5 6 1
7 8 9 2

So your program should return the elements of this matrix in a clockwise, spiral order which is: 1,2,3,6,9,8,7,4,5
*/

#include <iostream>
#include <string>
using namespace std;


/*
only analyze number characters
read first row full
get last values of the other rows before reaching last
read last row in reverse
get first values of the other rows before reaching first
read new first row full minus last value
read second to last value of the other rows before reaching end
continue to iterate 
*/

string MatrixSpiral(string strArr[], int size) 
{
	int last = size - 1;
	int first = 0;
	int midcol = (strArr[first].length - 1) - 1;

	for (int row = 0; row < size; row++)
	{
		


		if (row == first)
		{
			for (int col = 1; col < strArr[row].length() - 1; col++)
			{

				if (strArr[row][col] >= '0' && strArr[row][col] <= '9')
				{
					cout << strArr[row][col];
				}
			}
			// update the first col
			first++;
		}
		else if (row == last)
		{
			for (int col = midcol; midcol >= 0; midcol--)
			{
				if (strArr[row][midcol] >= '0' && strArr[row][midcol] <= '9')
				{
					cout << strArr[row][midcol];
				}
			}
			// update the last col
			last--;
		}
		else
		{
			cout << strArr[row][midcol];
		}
		
	}

	return "true";
}

int main() 
{
	string A[] = { "[1, 2, 3]", "[4, 5, 6]", "[7, 8, 9]" };
	string B[] = { "[1, 2]", "[10, 14]" };
	string C[] = { "[4, 5, 6, 5]", "[1, 1, 2, 2]", "[5, 4, 2, 9]" };

	cout << MatrixSpiral(A, sizeof(A)/sizeof(A[0])) << endl; // 1,2,3,6,9,8,7,4,5
	cout << MatrixSpiral(B, sizeof(B) / sizeof(B[0])) << endl; // 1,2,14,10
	cout << MatrixSpiral(C, sizeof(C) / sizeof(C[0])) << endl; // 4,5,6,5,2,9,2,4,5,1,1,2
	return 0;

}