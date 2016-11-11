// For this challenge you will determine how quickly you can reach the end of an array.
/*
have the function ArrayMinJumps(arr) take the array of integers stored in arr, where each integer represents the maximum number of steps that can be made from that position, and determine the least amount of jumps that can be made to reach the end of the array. For example: if arr is
[1, 5, 4, 6, 9, 3, 0, 0, 1, 3] then your program should output the number 3 because you can reach the end of the array from the beginning via the following steps:
1 -> 5 -> 9 -> END or 1 -> 5 -> 6 -> END. Both of these combinations produce a series of 3 steps. And as you can see, you don't always have to take the maximum number of jumps at a specific position, you can take less jumps even though the number is higher.

If it is not possible to reach the end of the array, return -1.
*/

#include <iostream>
using namespace std;


int ArrayMinJumps(int arr[], int size) 
{

}

int main() 
{
	int A[] = { 1, 5, 4, 6, 9, 3, 0, 0, 1, 3 };
	int B[] = { 3, 4, 2, 1, 1, 100 };
	int C[] = { 1, 3, 6, 8, 2, 7, 1, 2, 1, 2, 6, 1, 2, 1, 2 };
	cout << ArrayMinJumps(A, sizeof(A)/sizeof(A[0])) << endl; // 3
	cout << ArrayMinJumps(B, sizeof(B) / sizeof(B[0])) << endl; // 2
	cout << ArrayMinJumps(C, sizeof(C) / sizeof(C[0])) << endl; // 4
	return 0;

}