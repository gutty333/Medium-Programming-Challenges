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
#include <vector>
#include <sstream>
using namespace std;


/*
only analyze number characters
take the string data and create a new list of only numbers to better iterate later on
check for the total numbers to help with the loop
start on row 1 col 1 and iterate to right
once you reach end of col update rows
if is not first row take the last col value
once you reach end row iterate to left
update first and last rows again
now repeat process but in reverse
*/

string MatrixSpiral(string strArr[], int size) 
{
	vector <vector <int> > list(size);
	string temp;
	int num;

	// Loop to create a new list of ints
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < strArr[row].length(); col++)
		{
			// Condition to convert the string to int and add to the list
			if (strArr[row][col] == ',' || strArr[row][col] == ']')
			{
				istringstream(temp) >> num;
				list[row].push_back(num);
				temp.clear();
			}
			// Create the string number
			else if (strArr[row][col] >= '0' & strArr[row][col] <= '9')
			{
				temp += strArr[row][col];
			}
		}
	}

	// We provide the total amount of numbers in the matrix.
	int total = size * list[0].size();
	int start = 0;

	// Will represent the parent row and col
	int first = 0;
	int last = size;

	// Will represent the child row and col
	// These are our current location
	int row = 0;
	int col = 0;

	// Will represent the length our columns are when analyzed
	int colStart = 0;
	int colEnd = list[0].size();

	// Signals to determine how we iterate
	bool down, up;

	string result;

	// Spiral cycle
	while (start < total)
	{
		// When we are dealing with the parent first row
		// We iterate to the right
		if (row == first)
		{
			stringstream convert;
			convert << list[row][col];
			result += convert.str();
			result += ',';

			// Condition to check if we have reached the current column end
			// Iterate to the right
			if (col + 1 < colEnd)
			{
				col++;
			}
			else
			{
				// Update our last row and col end
				// Also signal that we now go down
				last--;
				row++;
				colEnd--;
				down = true;
				up = false;
			}
		}
		// Condition when we reach the parent last row
		else if (row == last)
		{
			stringstream convert;
			convert << list[row][col];
			result += convert.str();
			result += ',';

			// Iterate to the left
			if (col - 1 >= colStart)
			{
				col--;
			}
			else
			{
				// Update our first row and column start
				// Signal that we now go up
				first++;
				row--;
				colStart++;
				up = true;
				down = false;
			}
		}
		else if (down) // Going down we just take the last value of that row based on column length we set up
		{
			stringstream convert;
			convert << list[row][col];
			result += convert.str();
			result += ',';
			row++;
		}
		else if (up) // Going down we take the first value of that row based on column lenght we set up
		{
			stringstream convert;
			convert << list[row][col];
			result += convert.str();
			result += ',';
			row--;
		}

		start++;
	}

	// Erasing the comma at the end
	result.erase(result.end() - 1);

	return result;
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