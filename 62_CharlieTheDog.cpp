// For this challenge you will be helping a dog collect all the food in a grid.
/*
have the function CharlietheDog(strArr) read the array of strings stored in strArr which will be a 4x4 matrix of the characters 'C', 'H', 'F', 'O', where C represents Charlie the dog, H represents its home, F represents dog food, and O represents and empty space in the grid. Your goal is to figure out the least amount of moves required to get Charlie to grab each piece of food in the grid by moving up, down, left, or right, and then make it home right after. Charlie cannot move onto the home before all pieces of food have been collected. For example: if strArr is ["FOOF", "OCOO", "OOOH", "FOOO"], then this looks like the following grid:


For the input above, the least amount of steps where the dog can reach each piece of food, and then return home is 11 steps, so your program should return the number 11. The grid will always contain between 1 and 8 pieces of food.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// return the corresponding index for the located item
vector <int> collectPoint(int x, int y)
{
	vector <int> temp;
	temp.push_back(x);
	temp.push_back(y);
	return temp;
}

// calculates distance between 2 points
int calculateDistance(int x1, int y1, int x2, int y2)
{

}

/*
Possible solution involves storing the index of the home, foods and Charlie

We traverse the matrix  to gather all the important locations

once collected we can start from the home and reverse back to Charlie
we can apply a greedy approach were at each iteration we find the food closest to our current destination
so the start would be find the closest piece of food to the home
next would include finding the closest piece of food, to this current food.  etc

we calculate the distance between each of the points each time we make a selection
*/
string CharlietheDog(string strArr[], int size) 
{
	vector < vector <int> > result;
	int source;
	int dog;

	int totalDistance = 0;

	// traversing the matrix to collect the important locations
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < strArr[row].length(); col++)
		{
			
			if (strArr[row][col] == 'H' || strArr[row][col] == 'C' || strArr[row][col] == 'F')
			{
				if (strArr[row][col] == 'H')
				{
					source = result.size();
				}

				if (strArr[row][col] == 'C')
				{
					dog = result.size();
				}

				result.push_back(collectPoint(row, col));
			}
		}
	}

	for (int x = 0; x < result.size(); x++)
	{
		cout << "The x is " << result[x][0] << " and y is " << result[x][1] << endl;
	}
	cout << "The home is at index " << source << endl;
	cout << "The dog is at index " << dog << endl;


	int lowest;

	while (result.size() > 1)
	{
		for (int x = 0; x < result.size(); x++)
		{
			if (x == source || x == dog)
			{
				continue;
			}

			int getDistance = 
		}
	}


	return "test";
}

int main() 
{
	string A[] = { "FOOF", "OCOO", "OOOH", "FOOO" };
	string B[] = { "OOOO", "OOFF", "OCHO", "OFOO" };
	string C[] = { "FOOO", "OCOH", "OFOF", "OFOO" };


	cout << CharlietheDog(A, sizeof(A)/sizeof(A[0])) << endl; // 11
	cout << CharlietheDog(B, sizeof(B) / sizeof(B[0])) << endl; // 7
	cout << CharlietheDog(C, sizeof(C) / sizeof(C[0])) << endl; // 10
	return 0;
}
