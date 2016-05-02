// For this challenge you will determine if numbers within an array follow an arithmetic or geometric sequence.
// have the function ArithGeoII(arr) take the array of numbers stored in arr and return the string "Arithmetic" if the sequence follows an arithmetic pattern or return "Geometric" if it follows a geometric pattern. If the sequence doesn't follow either pattern return -1. An arithmetic sequence is one where the difference between each of the numbers is consistent, where as in a geometric sequence, each term after the first is multiplied by some constant or common ratio. Arithmetic example: [2, 4, 6, 8] and Geometric example: [2, 6, 18, 54]. Negative numbers may be entered as parameters, 0 will not be entered, and no array will contain all the same elements. 

#include <iostream>
#include <string>
using namespace std;

string ArithGeoII(int arr[], int size) {

	int pattern, pattern2;
	
	// Find the pattern
	pattern = arr[1]- arr[0];
	pattern2 = arr[1] / arr[0];

	bool arith = true, geo = true;
	// Check to see if the pattern stays true when we traverse the array
	for (int y = 0; y < size - 1; y++)
	{
		if (arr[y + 1] - arr[y] != pattern)
		{
			arith = false;
		}
		if (arr[y + 1] / arr[y] != pattern2)
		{
			geo = false;
		}
	}

	if (arith)
	{
		return "Arithmetic";
	}
	else if (geo)
	{
		return "Geometric";
	}
	else
	{
		return "-1";
	}
}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	int A[] = {5,10,15};
	int B[] = {2,4,16,24};
	int C[] = {2,4,6,8};
	int D[] = {2,6,18,54};
	cout << ArithGeoII(A, sizeof(A) / sizeof(A[0])) << endl; // Arithmetic
	cout << ArithGeoII(B, sizeof(B) / sizeof(B[0])) << endl; // -1
	cout << ArithGeoII(C, sizeof(C) / sizeof(C[0])) << endl; // Arithmetic
	cout << ArithGeoII(D, sizeof(D) / sizeof(D[0])) << endl; // Geometric
	return 0;

}