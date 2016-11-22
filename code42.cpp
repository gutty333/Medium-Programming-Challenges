// For this challenge you will determine how many different ways students can sit next to each other.
/*
have the function SeatingStudents(arr) read the array of integers stored in arr which will be in the following format:
[K, r1, r2, r3, ...] where K represents the number of desks in a classroom, and the rest of the integers in the array will be in sorted order and will represent the desks that are already occupied. All of the desks will be arranged in 2 columns, where desk #1 is at the top left, desk #2 is at the top right, desk #3 is below #1, desk #4 is below #2, etc. Your program should return the number of ways 2 students can be seated next to each other. This means 1 student is on the left and 1 student on the right, or 1 student is directly above or below the other student.

For example: if arr is [12, 2, 6, 7, 11] then this classrooms looks like the following picture:

1	~2
3	4
5	~6 
~7	8
9	10
~11	12

Based on above arrangement of occupied desks, there are a total of 6 ways to seat 2 new students next to each other. The combinations are: [1, 3], [3, 4], [3, 5], [8, 10], [9, 10], [10, 12]. So for this input your program should return 6. K will range from 2 to 24 and will always be an even number. After K, the number of occupied desks in the array can range from 0 to K.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
get the number of total seats
setup the seating into a 2 dimensional array
marked down which seats have already been taken
iterate through the 2D array and check which seats are open for 2 new students
they must be next to each other
keep track of the total number of combinations
*/

int SeatingStudents(int arr[], int size) 
{
	int total = arr[0];

	vector <vector <int> > list; // will contain the desk layout of the classroom
	vector <vector <int> > result; // will contain all the combinations
	int seat = 1;

	// Loop to fill out the new list with the seating format required
	for (int x = 0; x < total/2; x++)
	{
		vector <int> temp;
		list.push_back(temp);

		// Keeps track of the correct desk number on based on a 2 column layout
		if (seat <= total)
		{
			for (int y = 0; y < 2; y++, seat++)
			{
				list[x].push_back(seat);
			}
		}
	}

	// Marking down the seats that are already taken
	// Will also check for any combination of open seats where 2 new students can seat
	int resultSize = -1;
	for (int row = 0; row < list.size(); row++)
	{
		vector <int> temp2;
		
		for (int col = 0; col < 2; col++)
		{
			for (int z = 1; z < size; z++)
			{
				// Conditions to signify a taken seat
				if (arr[z] == list[row][col])
				{
					list[row][col] = -1;
				}

				// Bound checking
				if (row != list.size() - 1 && arr[z] == list[row + 1][col])
				{
					list[row + 1][col] = -1;
				}
			}
		}

		// Condition to check if the desk/seats are open for the new students to seat next to each other
		// If a combination is found it will add it to our new 2D list
		// The size of our new list will represent the total number of combinations found
		if (list[row][0] != -1 && list[row][1] != -1)
		{
			result.push_back(temp2);
			resultSize++; // Used to keep track of our current row
			result[resultSize].push_back(list[row][0]);
			result[resultSize].push_back(list[row][1]);
		}

		// Simple bound checking
		if (row != list.size() - 1) // Analyzing any row not including the last row
		{
			if (list[row][0] != -1 && list[row + 1][0] != -1)
			{
				result.push_back(temp2);
				resultSize++;
				result[resultSize].push_back(list[row][0]);
				result[resultSize].push_back(list[row + 1][0]);
			}

			if (list[row][1] != -1 && list[row + 1][1] != -1)
			{
				result.push_back(temp2);
				resultSize++;
				result[resultSize].push_back(list[row][1]);
				result[resultSize].push_back(list[row + 1][1]);
			}
		}
	}

	return result.size();
}

int main() 
{
	int A[] = { 12, 2, 6, 7, 11 };
	int B[] = { 6, 4 };
	int C[] = { 8, 1, 8 };

	cout << SeatingStudents(A, sizeof(A) / sizeof(A[0])) << endl; // 6
	cout << SeatingStudents(B, sizeof(B) / sizeof(B[0])) << endl; // 4
	cout << SeatingStudents(C, sizeof(C) / sizeof(C[0])) << endl; // 6
	return 0;

}