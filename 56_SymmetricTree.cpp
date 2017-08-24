// For this challenge you will traverse a binary tree and determine if it is symmetric.
/*
have the function SymmetricTree(strArr) take the array of strings stored in strArr, which will represent a binary tree, and determine if the tree is symmetric (a mirror image of itself). The array will be implemented similar to how a binary heap is implemented, except the tree may not be complete and NULL nodes on any level of the tree will be represented with a #. For example: if strArr is ["1", "2", "2", "3", "#", "#", "3"]
For the input above, your program should return the string true because the binary tree is symmetric.
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;


/*
first check the number of nodes present
if size is 1 than return true, since that represents just the root node
if size 3 assure that it also represent just a root node, so a valid node, with 2 null nodes is valid
if none of the previous 2 are met than need at least 7 nodes to have a mirror image of each subtree
note that null nodes are count as an element in the array
we are going to take an approach similar to a level order
as we traverse the tree add parents to a queue
we than compare the children of each parent
after comparing we pop those current parent from the queue and add the valid children
we continue to move down the tree
the sibling must match in a reverse fashion, meaning if parent A has a left child with value 5
than parent B must have a right child with value 5
this traversal will continue until the queue is empty, note that any null nodes are not added to the queue
*/


// Will update the index for the children of the 2 parents
void getChildren(int& leftChild, int& rightChild, string& left, string& right, int parent1, int parent2, string strArr[])
{
	leftChild = 2 * parent1 + 1;
	rightChild = 2 * parent2 + 2;
	left = strArr[leftChild];
	right = strArr[rightChild];
}

string SymmetricTree(string strArr[], int size) 
{
	if (size == 1)
	{
		if (strArr[0] == "#")
		{
			return "true";
		}
		return "false";
	}
	else if (size == 3)
	{
		// If first node is null return false
		// since a null node cannot have children
		if (strArr[0] == "#")
		{
			return "false";
		}
		else if (strArr[0] != "#" && strArr[1] == "#" && strArr[2] == "#")
		{
			// This is valid since this is represents a single node
			return "true";
		}
	}
	else if (size < 7)
	{
		return "false";
	}

	// setting our queue and pushing the root node as our start
	queue <int> parents;
	parents.push(0);

	while (!parents.empty())
	{
		int parent1, parent2; // represents the index for the parents in each subtree
		string left, right; // represents the value of the parents
		int leftChild, rightChild; // represents the index of left and right child

		// getting the current index for the parent/s
		if (parents.front() == 0)
		{
			// special case for when we do the root node
			parent1 = parent2 = parents.front();
			parents.pop();
		}
		else
		{
			// get index of the 2 parents from the queue
			parent1 = parents.front();
			parents.pop();
			parent2 = parents.front();
			parents.pop();

			// special case to bound check and determine if current node is a leaf node
			if (2 * parent1 + 1 >= size && 2 * parent2 + 2 >= size)
			{
				continue;
			}
		}
		
		// Loop that will iterate and get the child of the two parents
		// Will compare the left child or parent 1 to the right child of parent 2
		// Will inverse and compare right child of parent1 to left child of parent 2
		// Remember that all valid children are added to the queue
		int count = 0;
		while (count < 2)
		{
			// Getting child left to child right
			if (count == 0)
			{
				getChildren(leftChild, rightChild,left, right, parent1, parent2, strArr);
			}
			else if (count == 1) // Getting child right to child left
			{
				getChildren(leftChild, rightChild, left, right, parent2, parent1, strArr);
			}


			// Comparing the children
			if (left != right)
			{
				return "false";
			}
			else
			{
				// we ignore any null nodes
				// we treat them as the next parent in the queue only if they are not null
				if (left != "#" && right != "#")
				{
					// adding the valid children
					parents.push(leftChild);
					parents.push(rightChild);
				}
			}

			// special again for root node
			// we don't need to compare right to left for root
			if (parent1 == 0)
			{
				break;
			}
			else
			{
				// update the counter
				count++;
			}
		}
	}

	return "true";
}

int main() 
{
	string A[] = { "1", "2", "2", "3", "#", "#", "3" };
	string B[] = { "4", "3", "4" };
	string C[] = { "10", "2", "2", "#", "1", "1", "#" };
	string D[] = { "4" };
	string E[] = { "#" };
	string F[] = { "30", "#", "#" };
	string G[] = { "#", "10", "10" };
	string H[] = { "1", "2", "2", "3", "#", "#", "7" };

	cout << SymmetricTree(A, sizeof(A)/sizeof(A[0]))<< endl; // true
	cout << SymmetricTree(B, sizeof(B) / sizeof(B[0])) << endl; // false
	cout << SymmetricTree(C, sizeof(C) / sizeof(C[0])) << endl; // true
	cout << SymmetricTree(D, sizeof(D) / sizeof(D[0])) << endl; // true
	cout << SymmetricTree(E, sizeof(E) / sizeof(E[0])) << endl; // true
	cout << SymmetricTree(F, sizeof(F) / sizeof(F[0])) << endl; // true
	cout << SymmetricTree(G, sizeof(G) / sizeof(G[0])) << endl; // true
	cout << SymmetricTree(H, sizeof(H) / sizeof(H[0])) << endl; // false
	return 0;
}
