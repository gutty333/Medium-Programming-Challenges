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
	for (int current = 0; current < list.size()-1; current++)
	{
		int maxIndex = current;

		for (int y = current+1; y < list.size(); y++)
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
6. the end case is when the 2 end points cross
7. that is to say that the start should always be smaller than the end
*/
void binarySearch(vector <int> list, int value)
{
	int start = 0;
	int end = list.size();
	int mid;

	while (start <= end)
	{
		mid = (start+end)/2;
		if (list[mid] == value)
		{
			cout << "Value found" << endl;
			return;
		}
		else if (value < list[mid])
		{
			end = mid-1;
		}
		else
		{
			start = mid+1;
		}
	}

	cout << "Value not found" << endl;
}


// Binary Search Recursive
/*
1. Same as iterative method
2. The important thing is the base case which is, continue if the start point is less than or equal to the end point
*/
void binarySearch(vector <int> list, int start, int end, int value)
{
	if (start <= end)
	{
		int mid = (start + end) / 2;

		if (list[mid] == value)
		{
			cout << "value found" << endl;
			return;
		}
		else if (value < list[mid])
		{
			binarySearch(list, start, mid-1, value);
		}
		else
		{
			binarySearch(list, mid+1, end, value);
		}
	}
	else
	{
		cout << "value not found" << endl;
	}

}



// Merge Array Function
// Function used to finally merge the sub arrays back into a larger array.
void mergeArray(vector <int>& list, int start, int mid, int end)
{
	vector <int> final(end);
	int index = start;

	
	for (int x = start, y = mid; x < mid || y < end;)
	{
		// If the subarrays have not been finished continue to compare which element from which array to add
		// For example if you add from subarray 1 than increment the index after using its value
		if (x < mid && y < end)
		{
			if (list[x] < list[y])
			{
				final[index] = list[x];
				index++;
				x++;
			}
			else
			{
				final[index] = list[y];
				index++;
				y++;
			}
		}
		// If one of the subarrays reached the end, find out which one still needs to be copied
		else
		{
			if (x < mid)
			{
				for (x; x < mid; x++)
				{
					final[index] = list[x];
					index++;
				}
			}
			else
			{
				for (y; y < end; y++)
				{
					final[index] = list[y];
					index++;
				}
			}
		}
	}


	cout << endl<< "COPYING VALUES" << endl;
	cout << "Start = " << start << endl;
	cout << "End = " << end << endl;
	for (int x = start; x < end; x++)
	{
		cout << final[x] << endl;
		list[x] = final[x];
	}
}

// Merge Sort
/*
1. Break the list into 2 sub arrays
2. Separately sort those arrays in either decreasing or increasing order
3. With the 2 sub arrays use them to merge them back into the final  result
4. You will need an index for both to keep track of which sub array you finish iterating first
5. This is because we will be comparing each element and insert the appropriate one to the final result
6. Note that one sub array will reach the end first
*/
void mergeSort(vector <int>& list, int start,int end)
{
	cout << endl << "Before condition" << endl;
	cout << "Start = " << start << endl;
	cout << "End = " << end << endl;
	
	if (start + 1 == end)
	{
		cout << "Only 1 element" << endl;
		return;
	}


	int mid = (start + end) / 2;

	cout << endl << "WE have more than 1 element" << endl;
	cout << "Start = " << start << endl;
	cout << "End = " << end << endl;
	cout << "Mid  = " << mid << endl;

	cout << "\t\t MERGE SORT FOR SUBARRAY 1" << endl;
	mergeSort(list, start, mid);

	cout << "\t\t MERGE SORT FOR SUBARRAY 2" << endl;
	mergeSort(list, mid, end);

	cout << endl << "WE NOW SWAP" << endl;
	mergeArray(list, start, mid, end);
	
}

int main()
{
	int list[] = { 100, 43,23,66 };
	int size = sizeof(list) / sizeof(list[0]);
	vector <int> combine;
	combine.insert(combine.begin(), list, list + size);

	//cout << "Original" << endl;
	//print(combine);

	cout << endl << "Sorted" << endl;
	
	//bubbleSort(combine);

	//selectionSort(combine);

	mergeSort(combine, 0, combine.size());
	cout << endl << endl;
	//print(combine);

	/*cout << endl << "Finding Values" << endl;
	binarySearch(combine, 0, combine.size(), 100);
	binarySearch(combine, 0, combine.size(), 331);
	binarySearch(combine, 0, combine.size(), 12);
	binarySearch(combine, 0, combine.size(), 10);
	binarySearch(combine, 0, combine.size(), 4535);
	binarySearch(combine, 0, combine.size(), 2343);*/
	return 0;
}
