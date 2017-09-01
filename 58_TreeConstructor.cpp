//  For this challenge you will determine if an array of integer pairs can form a binary tree properly.
/*
have the function TreeConstructor(strArr) take the array of strings stored in strArr, which will contain pairs of integers in the following format: (i1,i2), where i1 represents a child node in a tree and the second integer i2 signifies that it is the parent of i1. For example: if strArr is ["(1,2)", "(2,4)", "(7,2)"]

which you can see forms a proper binary tree. Your program should, in this case, return the string true because a valid binary tree can be formed. If a proper binary tree cannot be formed with the integer pairs, then return the string false. All of the integers within the tree will be unique, which means there can only be one node in the tree with the given integer value.
*/

#include <iostream>
#include <string>
using namespace std;

string TreeConstructor(string strArr[]) 
{

}

int main() 
{
	string A[] = { "(1,2)", "(2,4)", "(7,2)" };
	cout << TreeConstructor(A);
	return 0;

}
