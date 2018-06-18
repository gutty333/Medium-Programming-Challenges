// For this challenge you will be determining the areas of rectangles.
// have the function OverlappingRectangles(strArr) read the strArr parameter being passed which will represent two rectangles on a Cartesian coordinate plane and will contain 8 coordinates with the first 4 making up rectangle 1 and the last 4 making up rectangle 2. It will be in the following format: ["(0,0),(2,2),(2,0),(0,2),(1,0),(1,2),(6,0),(6,2)"] Your program should determine the area of the space where the two rectangles overlap, and then output the number of times this overlapping region can fit into the first rectangle. For the above example, the overlapping region makes up a rectangle of area 2, and the first rectangle (the first 4 coordinates) makes up a rectangle of area 4, so your program should output 2. The coordinates will all be integers. If there's no overlap between the two rectangles return 0. 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
traverse the string array to extract the points of each rectangle
first locate smallest and largest vertical/horizontal points of each
we then calculate the area of first rectangle
to locate points of overlapping rectangles we do a comparison of lowest and highest X and Y points
calculate are of overlapping rectangle after collecting its width and height
*/

// method to get the lowest and highest x and y points for each rectangle
void getPoints(string data, int start, int end, int& lowX, int& highX, int& lowY, int& highY)
{
	string num;
	bool firstRecord = false;
	bool firstRecord2 = false;

	// traverse the string to analyze the current points
	for (int y = start; y < end; y++)
	{
		// condition to collect x and y point value
		if ((data[y] >= '0' && data[y] <= '9') || data[y] == '-')
		{
			num.push_back(data[y]);
		}
		else if (data[y] == ',' && !num.empty()) // finding the lowest and highest horizontal x point value 
		{
			istringstream convert(num);

			// first records are automatically collected
			if (!firstRecord)
			{
				convert >> lowX;
				convert >> highX;
				firstRecord = true;
			}
			else
			{
				// comparison done to collect lowest and highest
				int temp;
				convert >> temp;

				if (temp < lowX)
				{
					lowX = temp;
				}
				else if (temp > highX)
				{
					highX = temp;
				}
			}

			// reset for recording next pair of points
			num.clear();
		}
		else if (data[y] == ')')
		{
			istringstream convert(num);

			if (!firstRecord2)
			{
				convert >> lowY;
				convert >> highY;
				firstRecord2 = true;
			}
			else
			{
				int temp;
				convert >> temp;

				if (temp < lowY)
				{
					lowY = temp;
				}
				else if (temp > highY)
				{
					highY = temp;
				}
			}

			num.clear();
		}
	}
}

int OverlappingRectangles(string strArr[]) 
{
	// points representing both our rectangles
	int rectangle1_lowX;
	int rectangle1_highX;
	int rectangle1_lowY;
	int rectangle1_highY;

	int rectangle2_lowX;
	int rectangle2_highX;
	int rectangle2_lowY;
	int rectangle2_highY;

	// section to locate the separator for the both rectangle points
	int midIndex = 0;
	string data = strArr[0];
	for (int x = 0; x < data.length(); x++)
	{
		if (data[x] == ',')
		{
			midIndex++;
		}

		if (midIndex == 8)
		{
			midIndex = x;
			break;
		}
	}

	// getting the desired point values for rectangle 1
	getPoints(data, 0, midIndex, rectangle1_lowX, rectangle1_highX, rectangle1_lowY, rectangle1_highY);

	// getting the desired point values for rectangle 2
	getPoints(data, midIndex+1, data.length(), rectangle2_lowX, rectangle2_highX, rectangle2_lowY, rectangle2_highY);

	// area of rectangle1
	int rectangle1Area = (rectangle1_highX - rectangle1_lowX) * (rectangle1_highY - rectangle1_lowY);

	// X and Y distance of the overlapping rectangle
	int overlappingX;
	int overlappingY;

	// condition to calculate width of overlapping rectangle
	if (rectangle2_lowX >= rectangle1_lowX && rectangle2_lowX < rectangle1_highX)
	{
		if (rectangle2_highX >= rectangle1_highX)
		{
			overlappingX = rectangle1_highX - rectangle2_lowX;
		}
		else
		{
			overlappingX = rectangle2_highX - rectangle2_lowX;
		}
	}
	else if (rectangle2_lowX < rectangle1_lowX && rectangle2_highX > rectangle1_lowX)
	{
		overlappingX = rectangle2_highX - rectangle1_lowX;
	}
	else
	{
		// no overlapping
		return 0;
	}

	// condition to calculate height of overlapping rectangle
	if (rectangle2_lowY >= rectangle1_lowY && rectangle2_lowY < rectangle1_highY)
	{
		if (rectangle2_highY >= rectangle1_highY)
		{
			overlappingY = rectangle1_highY - rectangle2_lowY;
		}
		else
		{
			overlappingY = rectangle2_highY - rectangle2_lowY;
		}
	}
	else if (rectangle2_lowY < rectangle1_lowY && rectangle2_highY > rectangle1_lowY)
	{
		overlappingY = rectangle2_highY - rectangle1_lowY;
	}
	else
	{
		return 0;
	}

	// area of overlapping rectangle
	int overlappingArea = overlappingX * overlappingY;

	return rectangle1Area / overlappingArea;
}

int main() 
{
	string A[] = { "(0,0),(0,-2),(3,0),(3,-2),(2,-1),(3,-1),(2,3),(3,3)" };
	string B[] = { "(0,0),(5,0),(0,2),(5,2),(2,1),(5,1),(2,-1),(5,-1)" };
	string C[] = { "(0,0),(2,2),(2,0),(0,2),(1,0),(1,2),(6,0),(6,2)" };
	string D[] = { "(1,0),(1,1),(4,0),(4,1),(2,0),(4,0),(2,1),(4,1)" };
	string E[] = { "(5,0),(-2,0),(5,-1),(-2,-1),(3,-1),(5,-1),(3,56),(5,56)" };
	string F[] = { "(1,0),(1,1),(4,0),(4,1),(5,0),(27,0),(5,-25),(27,-25)" };
	string G[] = { "(1,0),(1,1),(4,0),(4,1),(3,0),(4,0),(3,1),(4,1)" };
	string H[] = { "(0,0),(0,-2),(3,0),(3,-2),(2,-2),(3,-2),(2,20),(3,20)" };

	cout << OverlappingRectangles(A) << endl; // 6
	cout << OverlappingRectangles(B) << endl; // 3
	cout << OverlappingRectangles(C) << endl; // 2
	cout << OverlappingRectangles(D) << endl; // 1
	cout << OverlappingRectangles(E) << endl; // 3
	cout << OverlappingRectangles(F) << endl; // 0
	cout << OverlappingRectangles(G) << endl; // 3
	cout << OverlappingRectangles(H) << endl; // 3
	return 0;
}
