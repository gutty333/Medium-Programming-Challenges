//Program array_set1_q1.cpp
#include <iostream>
#include <vector>
using namespace std;

void print(vector <int> list)
{
	for (int x = 0; x < list.size(); x++)
	{
		cout << list[x] << endl;
	}
}

// Bubble Sort
/*
1. iterate through the list and compare each pair
2. if you make a change anywhere check the list again
3. if no changes were made than the list is ordered
*/
void bubbleSort(vector <int> list)
{
	bool swap;

	do
	{
		swap = false;

		for (int x = 0; x < list.size() - 1; x++)
		{
			if (list[x] >  list[x + 1])
			{
				int temp = list[x];
				list[x] = list[x + 1];
				list[x + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

	print(list);
}



// Selection Sort
/*
1. Check the list for the largest or smallest value
2. keep track of the indexes so you can swap the values
3. analyze the list again but this time excluding the previous index
4. again check for the next largest or smallest value
5. swap the values and continue to iterate the list
*/
void selectionSort(vector <int>& list)
{
	for (int current = 0; current < list.size(); current++)
	{
		int maxIndex = current;

		for (int y = current; y < list.size(); y++)
		{
			if (list[y] < list[maxIndex])
			{
				maxIndex = y;
			}
		}

		int temp = list[current];
		list[current] = list[maxIndex];
		list[maxIndex] = temp;
	}

	print(list);
}


// Linear Search
/*
1. compare the target to all the elements in the list
2. if the list reaches the end than the target was not found
*/
void linearSearch(vector <int> list, int value)
{
	for (int x = 0; x < list.size(); x++)
	{
		if (list[x] == value)
		{
			cout << "Value found" << endl;
			return;
		}
	}

	cout << "Value not found" << endl;
}


// Binary Search
/*
1. make sure that the list is ordered/sorted
2. begin breaking it in half
3. if the target is the mid point we found the value
4. if is not the midpoint compare to see which other half we analyze
5. continue the process of checking if the midpoint is the value
6. if the index reaches the end or the beginning than the target was not found
7. also if you are in the middle and no more progress can be made than the target was not found
*/
void binarySearch(vector <int> list, int value)
{
	int start = 0;
	int end = list.size();
	int mid;

	while (end > 0 && start < end)
	{
		mid = (start+end)/2;
		if (list[mid] == value)
		{
			cout << "Value found" << endl;
			return;
		}
		else if (mid == start)
		{
			break;
		}
		else if (value < list[mid])
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
	}

	cout << "Value not found" << endl;
}


int main()
{
	int list[] = { 100, 43, 565, 32, 123, 545, 333, 12, 100, 4535, 23, 541, 2343, 34, 22 };
	int size = sizeof(list) / sizeof(list[0]);
	vector <int> combine;
	combine.insert(combine.begin(), list, list + size);

	cout << "Original" << endl;
	print(combine);

	cout << endl << "Sorted" << endl;
	//bubbleSort(combine);

	selectionSort(combine);

	cout << endl << "Finding Values" << endl;

	binarySearch(combine, 100);
	binarySearch(combine, 334);
	binarySearch(combine, 12);
	binarySearch(combine, 10);
	binarySearch(combine, 4535);
	binarySearch(combine, 2343);
	return 0;
}
