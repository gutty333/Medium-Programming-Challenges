// For this challenge you will determine what period of the day gives the most free time.
// have the function MostFreeTime(strArr) read the strArr parameter being passed which will represent a full day and will be filled with events that span from time X to time Y in the day. The format of each event will be hh:mmAM/PM-hh:mmAM/PM. For example, strArr may be ["10:00AM-12:30PM","02:00PM-02:45PM","09:10AM-09:50AM"]. Your program will have to output the longest amount of free time available between the start of your first event and the end of your last event in the format: hh:mm. The start event should be the earliest event in the day and the latest event should be the latest event in the day. The output for the previous input would therefore be 01:30 (with the earliest event in the day starting at 09:10AM and the latest event ending at 02:45PM). The input will contain at least 3 events and the events may be out of order. 

#include <iostream>
#include <string>
using namespace std;

string MostFreeTime(string strArr[], int size) {

	// code goes here   
	return strArr[0];

}

int main() {

	// keep this function call here
	/* Note: In C++ you first have to initialize an array and set
	it equal to the stdin to test your code with arrays. */

	string A[] = { "12:15PM-02:00PM", "09:00AM-10:00AM", "10:30AM-12:00PM" };
	string B[] = { "12:15PM-02:00PM", "09:00AM-12:11PM", "02:02PM-04:00PM" };
	string C[] = { "10:00AM-12:30PM", "02:00PM-02:45PM", "09:10AM-09:50AM" };
	cout << MostFreeTime(A, sizeof(A) / sizeof(A[0])) << endl; // 00:30
	cout << MostFreeTime(B, sizeof(B) / sizeof(B[0])) << endl; // 00:04
	cout << MostFreeTime(C, sizeof(C) / sizeof(C[0])) << endl; // 01:30
	return 0;

}