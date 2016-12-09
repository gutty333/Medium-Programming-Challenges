// For this challenge you will be determining the areas of rectangles.
// have the function OverlappingRectangles(strArr) read the strArr parameter being passed which will represent two rectangles on a Cartesian coordinate plane and will contain 8 coordinates with the first 4 making up rectangle 1 and the last 4 making up rectangle 2. It will be in the following format: ["(0,0),(2,2),(2,0),(0,2),(1,0),(1,2),(6,0),(6,2)"] Your program should determine the area of the space where the two rectangles overlap, and then output the number of times this overlapping region can fit into the first rectangle. For the above example, the overlapping region makes up a rectangle of area 2, and the first rectangle (the first 4 coordinates) makes up a rectangle of area 4, so your program should output 2. The coordinates will all be integers. If there's no overlap between the two rectangles return 0. 

#include <iostream>
#include <string>
using namespace std;

// Not Finished
string OverlappingRectangles(string strArr[], int size) {

	// code goes here   
	return strArr[0];

}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	string A[] = { "(0,0),(0,-2),(3,0),(3,-2),(2,-1),(3,-1),(2,3),(3,3)" };
	string B[] = { "(0,0),(5,0),(0,2),(5,2),(2,1),(5,1),(2,-1),(5,-1)" };
	string C[] = { "(0,0),(2,2),(2,0),(0,2),(1,0),(1,2),(6,0),(6,2)" };
	cout << OverlappingRectangles(A, sizeof(A) / sizeof(A[0])) << endl; // 6
	cout << OverlappingRectangles(B, sizeof(B) / sizeof(B[0])) << endl; // 3
	cout << OverlappingRectangles(C, sizeof(C) / sizeof(C[0])) << endl; // 2

	return 0;

}
