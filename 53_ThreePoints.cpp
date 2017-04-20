// For this challenge you will be plotting a line on a Cartesian grid.
/*
have the function ThreePoints(strArr) read the array of strings stored in strArr which will always contain 3 elements and be in the form: ["(x1,y1)", "(x2,y2)", "(x3,y3)"]. Your goal is to first create a line formed by the first two points (that starts from the first point and moves in the direction of the second point and that stretches in both directions through the two points), and then determine what side of the line point 3 is on. The result will either be right, left, or neither. For example: if strArr is ["(1,1)", "(3,3)", "(2,0)"] then your program should return the string right because the third point lies to the right of the line formed by the first two points.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

/*
extract the values of each point
convert to integer for ease of use
compare the distance between each point
*/

string ThreePoints(string strArr[]) 
{
	vector <string> points;
	vector <double> values;

	for (int x = 0; x < 3; x++)
	{
		int middle;
		middle = strArr[x].find(',');

		// extract the x value from current point
		points.push_back(strArr[x].substr(1, middle - 1));
		
		// extract the y value form current point
		points.push_back(strArr[x].substr(middle + 1, (strArr[x].size() - middle + 1) - 1));
	}

	// Convert to ints for comparing the x values
	for (int x = 0; x < points.size(); x++)
	{
		double temp;

		istringstream(points[x]) >> temp;
		values.push_back(temp);
	}

	// Find distance
	double distance1 = sqrt(pow(values[4] - values[0], 2) + pow(values[5] - values[1], 2));
	double distance2 = sqrt(pow(values[4] - values[2], 2) + pow(values[5] - values[3], 2));
	cout << distance1 << " and " << distance2 << endl;
	// Find mid point
	double x = (values[0] + values[2]) / 2.0;
	double y = (values[1] + values[3]) / 2;

	cout << x << endl;
	if (values[4] == x)
	{
		return "neither";
	}
	else if (values[4] > x)
	{
		return "right";
	}
	else
	{
		return "left";
	}
}

int main() 
{
	string A[] = { "(5000,5001)", "(-5001,-5000)", "(0,601)" };
	string B[] = { "(0,-3)", "(-2,0)", "(0,0)" };
	string C[] = { "(0,0)", "(0,5)", "(0,2)" };
	string D[] = { "(0,1)", "(-3,0)", "(-1,0)" };
	string E[] = { "(0,5)", "(0,-5)", "(1,1)" };
	string F[] = { "(100,100)", "(-1,-1)", "(5,1)" };
	cout << ThreePoints(A) << endl; // right
	cout << ThreePoints(B) << endl; // right
	cout << ThreePoints(C) << endl; // neither
	cout << ThreePoints(D) << endl; // left
	cout << ThreePoints(E) << endl; // left
	cout << ThreePoints(F) << endl; // left
	return 0;
}