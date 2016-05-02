// For this challenge you will determine what period of the day gives the most free time.
// have the function MostFreeTime(strArr) read the strArr parameter being passed which will represent a full day and will be filled with events that span from time X to time Y in the day. The format of each event will be hh:mmAM/PM-hh:mmAM/PM. For example, strArr may be ["10:00AM-12:30PM","02:00PM-02:45PM","09:10AM-09:50AM"]. Your program will have to output the longest amount of free time available between the start of your current event and the end of your last event in the format: hh:mm. The start event should be the earliest event in the day and the latest event should be the latest event in the day. The output for the previous input would therefore be 01:30 (with the earliest event in the day starting at 09:10AM and the latest event ending at 02:45PM). The input will contain at least 3 events and the events may be out of order. 

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

// Function used to determine the time difference between the events
double timeDifference(string currentEvent, string nextEvent, string time1, string time2)
{
	double currentTime, nextTime;
	currentEvent[2] = nextEvent[2] = '.';
	istringstream(currentEvent) >> currentTime;
	istringstream(nextEvent) >> nextTime;

	if (currentEvent.substr(currentEvent.length() - 2) != "00" && nextEvent.substr(nextEvent.length() - 2) == "00")
	{
		nextTime += 0.60;
		nextTime -= 1;
	}
	
	// Conditions to calculate the difference
	if (time1 == time2 && (currentEvent.substr(0, 2) == "12" && nextEvent.substr(0, 2) != "12"))
	{
		return (nextTime + 12.00) - currentTime;
	}
	else if (time1 == time2)
	{
		return nextTime - currentTime;
	}
	else
	{
		return (nextTime + 12.00) - currentTime;
	}
}

string MostFreeTime(string strArr[], int size) {
	int index;
	string current, current2, current3, temp, temp2, temp3;
	bool swap;

	// Loop to order the events
	do
	{
		swap = false;
		for (int x = 0; x < size-1; x++)
		{
			current = strArr[x].substr(0, 2); // current hour
			current2 = strArr[x].substr(5, 2); // current time frame
			current3 = strArr[x].substr(3, 2); // current minute
			temp = strArr[x+1].substr(0, 2); // next event hour
			temp2 = strArr[x+1].substr(5, 2); //  next event time frame
			temp3 = strArr[x + 1].substr(3, 2); // next event minute

			// Conditions to compare based on time and if early or late in the day
			if (current == temp && current2 == temp2 && current3 > temp3)
			{
				temp = strArr[x];
				strArr[x] = strArr[x + 1];
				strArr[x + 1] = temp;
				swap = true;
			}
			if ((temp < current && current != "12") && ((current2 == "AM" && temp2 == "AM") || (current2 == "PM" && temp2 == "PM")))
			{
				temp = strArr[x];
				strArr[x] = strArr[x + 1];
				strArr[x + 1] = temp;
				swap = true;
			}
			else if ((temp > current && temp == "12") && ((current2 == "AM" && temp2 == "AM") || (current2 == "PM" && temp2 == "PM")))
			{
				temp = strArr[x];
				strArr[x] = strArr[x + 1];
				strArr[x + 1] = temp;
				swap = true;
			}
			else if ((temp < current || temp > current) && current2 == "PM" && temp2 == "AM")
			{
				temp = strArr[x];
				strArr[x] = strArr[x + 1];
				strArr[x + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

	double value;
	double high = 0;
	// Loop to find the most free time
	for (int y = 0; y < size-1; y++)
	{
		// Value we use the function to find the difference between the current and next event time
		// It takes the end time of current event and beginning time of next event
		// The AM and PM will help with calculating the difference
		value = timeDifference(strArr[y].substr(8, 5), strArr[y + 1].substr(0, 5), strArr[y].substr(strArr[y].length() - 2), strArr[y+1].substr(5,2));

		if (value > high) // Keep track of which provides the most free time
		{
			high = value;
		}
	}
	
	// Convert the highest difference value back to a string for editing
	stringstream convert;
	convert << fixed << setprecision(2) << high;
	string freeTime = convert.str();
	// Assuring that the output is in a time format
	// Example if 4.32 it should be 04:32
	if (freeTime.length() != 5)
	{
		freeTime.insert(0, "0");
	}
	freeTime[2] = ':';

	return freeTime;
}
// Note, looking back at the code we could have eliminate having an extra condition and logic for dealing with 12, by checking the hour and set to zero if 12. Example if temp == 12 , temp == 0
// Also the conditions could have been left to only one single if else, meaning just check if the next event is later in the date, if true continue else swap.

int main() {
	// keep this function call here
	/* Note: In C++ you current have to initialize an array and set
	it equal to the stdin to test your code with arrays. */
	string A[] = { "12:15PM-02:00PM", "09:00AM-10:00AM", "10:30AM-12:00PM" };
	string B[] = { "12:15PM-02:00PM", "09:00AM-12:11PM", "02:02PM-04:00PM" };
	string C[] = { "10:00AM-12:30PM", "02:00PM-02:45PM", "09:10AM-09:50AM" };
	string D[] = { "06:00AM-08:00PM", "09:09PM-09:11PM", "08:10PM-09:00PM", "08:02PM-08:04PM" };
	cout << MostFreeTime(A, sizeof(A) / sizeof(A[0])) << endl; // 00:30
	cout << MostFreeTime(B, sizeof(B) / sizeof(B[0])) << endl; // 00:04
	cout << MostFreeTime(C, sizeof(C) / sizeof(C[0])) << endl; // 01:30
	cout << MostFreeTime(D, sizeof(D) / sizeof(D[0])) << endl; // 00:09

	return 0;
}