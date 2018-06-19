// For this challenge you will determine how to multiply a number to find a duplicate pair.
/*
have the function PairSearching(num) take the num parameter being passed and perform the following steps. First take all the single digits of the input number (which will always be a positive integer greater than 1) and add each of them into a list. Then take the input number and multiply it by any one of its own integers, then take this new number and append each of the digits onto the original list. Continue this process until an adjacent pair of the same number appears in the list. Your program should return the least number of multiplications it took to find an adjacent pair of duplicate numbers.

For example: if num is 134 then first append each of the integers into a list: [1, 3, 4]. Now if we take 134 and multiply it by 3 (which is one of its own integers), we get 402. Now if we append each of these new integers to the list, we get: [1, 3, 4, 4, 0, 2]. We found an adjacent pair of duplicate numbers, namely 4 and 4. So for this input your program should return 1 because it only took 1 multiplication to find this pair.

Another example: if num is 46 then we append these integers onto a list: [4, 6]. If we multiply 46 by 6, we get 276, and appending these integers onto the list we now have: [4, 6, 2, 7, 6]. Then if we take this new number, 276, and multiply it by 2 we get 552. Appending these integers onto the list we get: [4, 6, 2, 7, 6, 5, 5, 2]. Your program should therefore return 2 because it took 2 multiplications to find a pair of adjacent duplicate numbers (5 and 5 in this case).
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

/*
will be a BFS approach to analyze the possible paths
first we create a list from input number
we keep a record of list, number, and multiplication count
following the rules we traverse each value of current list and multiply it to the number
each possible scenario will be treated as a path we can take
at each scenario we checking if current list has adjacent pairs
we continue the traversal until an adjacent pair is found
*/

// method to check if our current list has any adjacent pairs
bool findPair(vector <int> list)
{
	for (int x = 0; x < list.size() - 1; x++)
	{
		if (list[x] == list[x + 1])
		{
			return true;
		}
	}
	return false;
}

// helper function which will break the number down and add its digits to the list
vector<int> getList(int num)
{
	vector <int> list;

	while (num)
	{
		int temp = num % 10;

		list.push_back(temp);

		num /= 10;
	}

	reverse(list.begin(), list.end());

	return list;
}

int PairSearching(int num) 
{
	// initial starting values
	vector <int> startingList;
	vector <int> values;
	values.push_back(num);
	values.push_back(0);

	map< vector<int>, vector<int> > startingTable;
	startingTable[startingList] = values;

	queue< map< vector<int>, vector<int> > >  listPair;
	listPair.push(startingTable);

	// BFS traversal
	while (!listPair.empty())
	{
		// getting the current list with its state
		map< vector<int>, vector<int> > tablePair = listPair.front();

		// list of integers
		vector <int> currentList;

		// current number
		int currentTotal;

		// multiplication count
		int currentCount; 

		// getting the current content (list,number,count)
		for (auto x = tablePair.begin(); x != tablePair.end(); x++)
		{
			currentList = x->first;
			currentTotal = x->second[0];
			currentCount = x->second[1];
		}

		// appending the new integers to the list
		vector <int> temp = getList(currentTotal);
		for (int x = 0; x < temp.size(); x++)
		{
			currentList.push_back(temp[x]);
		}

		listPair.pop();

		// checking if current list of integers has adjacent pair
		if (findPair(currentList))
		{
			return currentCount;
		}

		// traverse the current list to analyze each path
		for (int x = 0; x < currentList.size(); x++)
		{
			map< vector<int>, vector<int> > newTable;
			vector <int> newItems;

			// updating our multiplication count and number value
			newItems.push_back(currentTotal * currentList[x]);
			newItems.push_back(currentCount + 1);
			newTable[currentList] = newItems;

			// adding new path to our queue
			listPair.push(newTable);
		}
	}
}

int main() 
{
	cout << PairSearching(134)<< endl; // 1
	cout << PairSearching(46)<< endl; // 2
	cout << PairSearching(8)<< endl; // 3
	cout << PairSearching(198)<< endl; // 2
	cout << PairSearching(2) << endl; // 3
	return 0;
}