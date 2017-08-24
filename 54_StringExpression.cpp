// For this challenge you will convert a string of written numbers to an actual number.
/*
have the function StringExpression(str) read the str parameter being passed which will contain the written out version of the numbers 0-9 and the words "minus" or "plus" and convert the expression into an actual final number written out as well. For example: if str is "foursixminustwotwoplusonezero" then this converts to "46 - 22 + 10" which evaluates to 34 and your program should return the final string threefour. If your final answer is negative it should include the word "negative."
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;


/*
NOT FINISHED

*/


string StringExpression(string str) 
{
	return "test";
}

int main()
{
	cout << StringExpression("onezeropluseight") << endl; // oneeight
	cout << StringExpression("oneminusoneone") << endl; // negativeonezero
	cout << StringExpression("foursixminustwotwoplusonezero") << endl; // threefour

	map <string, int> list;

	list["one"] = 1;
	list["two"] = 2;
	list["three"] = 3;

	for (int x = 1; x <= list.size(); x++)
	{
		cout << list[x] << endl;
	}
	
	return 0;
}
