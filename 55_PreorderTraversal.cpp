// For this challenge you will be traversing a binary tree.
/*
have the function PreorderTraversal(strArr) take the array of strings stored in strArr, which will represent a binary tree with integer values in a format similar to how a binary heap is implemented with NULL nodes at any level represented with a #. Your goal is to return the pre-order traversal of the tree with the elements separated by a space. For example: if strArr is ["5", "2", "6", "1", "9", "#", "8", "#", "#", "#", "#", "4", "#"] 
*/

#include <iostream>
#include <string>
using namespace std;


/*
The approach will remain as if dealing with a linked list implemented tree
start at the root, than analyze values to the left of the current until a null node than right
unlike a simple node redirection here we have to control our index 
We will use the formula of 2i+1 and 2i+2 where i is the parent and those represent the children
if we encounter a '#' this will work as our base case
to simplify we will also have a global string variable to record our result
and reset it each time it is called from the function
*/

string result;

void traversal(string tree[], int index, int size)
{
	// base case to return to the caller if current node is null
	// Or if we have gone pass our array size
	if (index >= size || tree[index] == "#")
	{
		return;
	}

	// include the current node to our result
	result += tree[index] + " ";

	// special case from when we go out of bounds but due to the index not properly representing the current parent
	// for example if a parent has a leaf node to its left, than the index needs to be updated
	// That is the leaf node will not count, so we decrease our index to represent a valid parent node
	// Again this is only for when the current parent had a leaf node sibling to its left
	if (2 * index + 1 >= size && tree[index - 1] == "#")
	{
		index--;
	}

	// move to the left of current node
	traversal(tree, 2 * index + 1, size);

	// move to the right of current node
	traversal(tree, 2 * index + 2, size);
}

string PreorderTraversal(string strArr[], int size) 
{
	result = ""; // string to store our result
	int index = 0; 
	
	// calling our method passing it index 0 which represents the root of our tree
	traversal(strArr, index, size);

	return result;
}

int main() 
{
	string A[] = { "5", "2", "6", "1", "9", "#", "8", "#", "#", "#", "#", "4", "#" };
	string B[] = { "4", "1", "5", "2", "#", "#", "#" };
	string C[] = { "2", "6", "#" };
	string D[] = { "5", "2", "6", "#", "9", "8", "1", "#", "#", "12", "15", "#", "#", "#", "45" };
	
	cout << PreorderTraversal(A, sizeof(A) / sizeof(A[0])) << endl; // 5 2 1 9 6 8 4
	cout << PreorderTraversal(B, sizeof(B) / sizeof(B[0])) << endl; // 4 1 2 5
	cout << PreorderTraversal(C, sizeof(C) / sizeof(C[0])) << endl; // 2 6
	cout << PreorderTraversal(D, sizeof(D) / sizeof(D[0])) << endl; // 5 2 9 12 15 6 8 1 45
	return 0;
}