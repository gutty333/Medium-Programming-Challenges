#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Print List function
void print(int list[], int size)
{
	for (int x = 0; x < size; x++)
	{
		cout << list[x] << endl;
	}
}

// BubbleSort
void bubbleSort(int list[], int size)
{
	bool swap = true;

	while (swap)
	{
		swap = false;

		for (int x = 0; x < size - 1; x++)
		{
			if (list[x] > list[x + 1])
			{
				int temp = list[x];
				list[x] = list[x + 1];
				list[x + 1] = temp;
				swap = true;
			}
		}
	}
}

void bubbleSort2(int list[], int size)
{
	iterate:
	for (int x = 0; x < size - 1; x++)
	{
		if (list[x] > list[x + 1])
		{
			int temp = list[x];
			list[x] = list[x + 1];
			list[x + 1] = temp;
			goto iterate;
		}
	}
}

void bubbleSort3(int list[], int size)
{
	for (int x = 0; x < size - 1;)
	{
		if (list[x] > list[x + 1])
		{
			int temp = list[x];
			list[x] = list[x + 1];
			list[x + 1] = temp;
			x--;
		}
		else
		{
			x++;
		}
	}
}


// Selection Sort
void selectionSort(int list[], int size)
{
	for (int x = 0; x < size-1; x++)
	{
		int minIndex = x;

		for (int y = x + 1; y < size; y++)
		{
			if (list[y] < list[minIndex])
			{
				minIndex = y;
			}
		}

		if (minIndex != x)
		{
			int temp = list[x];
			list[x] = list[minIndex];
			list[minIndex] = temp;
		}
	}
}


// Linear Search
void linearSearch(int list[], int size, int value)
{
	for (int x = 0; x < size; x++)
	{
		if (list[x] == value)
		{
			cout << "Found" << endl;
			return;
		}
	}
	cout << "Not Found" << endl;
}

// Binary Search
void binarySearch(int list[], int start, int size, int value)
{
	while (start <= size)
	{
		int mid = (start + size) / 2;

		if (list[mid] == value)
		{
			cout << "Found" << endl;
			return;
		}
		else if (value < list[mid])
		{
			size = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	cout << "Not Found" << endl;
}





// Merge Sort
void merge(int list[], int start, int mid, int end)
{
	vector <int> temp(end);
	int index = start;
	int x = start;
	int y = mid;


	while (x < mid && y < end)
	{
		if (list[x] < list[y])
		{
			temp[index] = list[x];
			x++;
		}
		else
		{
			temp[index] = list[y];
			y++;
		}
		index++;
	}

	if (x < mid)
	{
		while (x < mid)
		{
			temp[index] = list[x];
			x++;
			index++;
		}
	}
	else if (y < end)
	{
		while (y < end)
		{
			temp[index] = list[y];
			y++;
			index++;
		}
	}


	for (int x = start; x < end; x++)
	{
		list[x] = temp[x];
	}

}

void mergeSort(int list[], int start, int end)
{
	if (start + 1 == end)
	{
		return;
	}

	int mid = (start + end) / 2;

	mergeSort(list, start, mid);
	mergeSort(list, mid, end);
	merge(list, start, mid, end);
}




int main()
{
	int list[] = { 100, 43, 565, 32, 123, 545, 333, 12, 100, 4535, 23, 62,541, 2343, 34, 22 };
	int size = sizeof(list) / sizeof(list[0]);

	cout << "ORIGINAL LIST" << endl;
	print(list, size);

	cout << endl << "SORTED LIST" << endl;
	//selectionSort(list, size);
	mergeSort(list, 0, size);
	print(list, size);

	/*cout << endl << "FINDING VALUES" << endl;
	binarySearch(list, 0, size, 12);
	binarySearch(list, 0, size, 123);
	binarySearch(list, 0, size, 101);
	binarySearch(list, 0, size, 65);
	binarySearch(list, 0, size, 4535);*/

	return 0;

}