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


// return the corresponding points for the located item
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
	// conditions to determine the operation to find the distance
	// if the fall on same column or same row we can apply a simple distance formula
	if (x1 == x2 || y1 == y2)
	{
		return (int)sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	}
	
	int xDistance = (int)abs(y2 - y1);
	int yDistance = (int)abs(x2 - x1);
	return xDistance + yDistance;
}


/*
Solution involves storing the index of the home, foods and Charlie

We traverse the matrix  to gather all the important locations

once collected we can start from the home and reverse back to Charlie
we can apply a greedy approach were at each iteration we find the food closest to our current destination
so the start would be find the closest piece of food to the home
next would include finding the closest piece of food, to this current food.  etc

we calculate the distance between each of the points each time we make a selection
*/
int CharlietheDog(string strArr[], int size) 
{
	vector < vector <int> > result;

	int totalDistance = 0;

	// get the points of home location
	int currentX;
	int currentY;

	// get points of dog location
	int dogX;
	int dogY;

	// traversing the matrix to collect the important locations
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < strArr[row].length(); col++)
		{
			// collect the home location
			if (strArr[row][col] == 'H')
			{
				currentX = row;
				currentY = col;
			}
			// collect the dog location
			else if (strArr[row][col] == 'C')
			{
				dogX = row;
				dogY = col;
			}
			// collect the food locations
			else if (strArr[row][col] == 'F')
			{
				result.push_back(collectPoint(row, col));
			}
		}
	}

	// loop to analyze the list of points we collected to perform an optimal selection for each iteration
	while (result.size() > 0)
	{
		int lowest = INT_MAX;
		int lowestIndex;
		int lowestX;
		int lowestY;

		for (int x = 0; x < result.size(); x++)
		{
			// calculate the optimal distance from current location to others
			int getDistance = calculateDistance(currentX, currentY, result[x][0], result[x][1]);

			// update the optimal lowest distance
			if (getDistance < lowest)
			{
				lowest = getDistance;
				lowestIndex = x;
				lowestX = result[x][0];
				lowestY = result[x][1];
			}
			else if (getDistance == lowest && calculateDistance(dogX, dogY, lowestX, lowestY) < calculateDistance(dogX, dogY, result[x][0], result[x][1]))
			{
				// conditional dealing with multiple optimal paths at first check
				// our selection criteria will select the location furthers from the dog
				lowest = getDistance;
				lowestIndex = x;
				lowestX = result[x][0];
				lowestY = result[x][1];
			}
		}

		// update our total distance
		totalDistance += lowest;

		// updating our current points and removing from our list
		currentX = lowestX;
		currentY = lowestY;
		result.erase(result.begin() + lowestIndex);
	}

	// final step is to calculate distance from our last point to the location of the dog
	totalDistance += calculateDistance(currentX, currentY, dogX, dogY);

	return totalDistance;
}

int main() 
{
	string A[] = { "FOOF", "OCOO", "OOOH", "FOOO" };
	string B[] = { "OOOO", "OOFF", "OCHO", "OFOO" };
	string C[] = { "FOOO", "OCOH", "OFOF", "OFOO" };
	string D[] = { "COFO", "OOFH", "OOFO", "OOFO" };
	string E[] = { "FOFF", "FOOO", "OCOH", "FOFO" };

	cout << CharlietheDog(A, sizeof(A)/sizeof(A[0])) << endl; // 11
	cout << CharlietheDog(B, sizeof(B) / sizeof(B[0])) << endl; // 7
	cout << CharlietheDog(C, sizeof(C) / sizeof(C[0])) << endl; // 10
	cout << CharlietheDog(D, sizeof(D) / sizeof(D[0])) << endl; // 8
	cout << CharlietheDog(E, sizeof(E) / sizeof(E[0])) << endl; // 12
	return 0;
}
