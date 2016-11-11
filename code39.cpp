// For this challenge you will attempt to split a long string of characters into actual words.
/*
have the function WordSplit(strArr) read the array of strings stored in strArr, which will contain 2 elements: the first element will be a sequence of characters, and the second element will be a long string of comma-separated words, in alphabetical order, that represents a dictionary of some arbitrary length. For example: strArr can be: ["hellocat", "apple,bat,cat,goodbye,hello,yellow,why"]. Your goal is to determine if the first element in the input can be split into two words, where both words exist in the dictionary that is provided in the second input. In this example, the first element can be split into two words: hello and cat because both of those words are in the dictionary.

Your program should return the two words that exist in the dictionary separated by a comma. So for the example above, your program should return hello,cat. There will only be one correct way to split the first element of characters into two words. If there is no way to split string into two words that exist in the dictionary, return the string not possible. The first element itself will never exist in the dictionary as a real word.
*/

#include <iostream>
#include <string>
using namespace std;

/*
extract the first element to use for comparison
analyze each word separated by comma
check if the first half of the target word can be found
if so, now search for the second half in the dictionary
if the first half was not found we can conclude it does not exist
*/

string WordSplit(string strArr[])
{
	string target = strArr[0];
	string temp,temp2,result;
	bool valid;
	int index; 

	// Loop to analyze each word separated by a comma in the second element/dictionary
	for (int x = 0; x < strArr[1].length(); x++)
	{
		valid = true;

		// Condition to check for first half
		// We also reset out comparison word/first half in the case we have not found one yet
		if (strArr[1][x] == ',' || x == strArr[1].length()-1)
		{
			// In case we are working with the last split word in our dictionary
			// Add that last character to our split word
			if (x == strArr[1].length() - 1)
			{
				temp += strArr[1][x];
			}

			// Loop to compare the first half with our target world
			for (int y = 0; y < temp.length(); y++)
			{
				if (target[y] != temp[y])
				{
					valid = false;
				}
			}

			// Reset the word if not found
			if (!valid)
			{
				temp = "";
			}
			else
			{
				index = temp.length(); // Keeps track of where we need to continue for comparing the second half

				cout << "Our first half is " << temp << endl;
				// Checks for the second half
				for (int z = 0; z < strArr[1].length(); z++)
				{
					// Similar condition for when analyzing the first half
					// The commas signify a new split word we can evaluate
					if (strArr[1][z] == ',' || z == strArr[1].length() - 1)
					{
						if (z == strArr[1].length() - 1)
						{
							temp2 += strArr[1][z];
						}

						// Comparing for the second half
						// Assuming the second half exist but we failed, this implies we evaluated the wrong first half
						// The other scenario is that no second half is found at all
						for (int i = index; i < temp2.length(); i++)
						{
							if (target[i] != temp2[i])
							{
								valid = false;
							}
						}
						
						if (!valid)
						{
							temp2 = "";
						}
						else
						{
							// Check that our 2 split words match the target
							result = temp+temp2;

							if (result == target)
							{
								result = temp + "," + temp2;
								return result;
							}
							else
							{
								temp2 = "";
							}
						}
					}
					else
					{
						temp2 += strArr[1][z];
					}
				}
			}
			temp = ""; // Reset in the case the second half failed
		}
		else // Continue to extract characters before reaching the next comma or the end
		{
			temp += strArr[1][x];
		}
	}

	return "not possible";
}

int main() 
{
	string A[] = { "hellocat", "apple,bat,cat,goodbye,hello,yellow,why"};
	string B[] = { "baseball", "a,all,b,ball,bas,base,cat,code,d,e,quit,z"};
	string C[] = { "abcgefd", "a,ab,abc,abcg,b,c,dog,e,efd,zzzz"};
	string D[] = { "test", "t,ab,abc,abcg,b,c,dog,e,efd,zzzz" };
	string E[] = { "abbbbcd", "a,ab,b,bbbcd,c,d,dog,elf,f,farm,go,goal,hello"};
	string F[] = { "az", "a,b,c,d,e,f,farm,g,goal,hello,world,x,y,z,zzzz" };


	//cout << WordSplit(A) << endl; // hello,cat
	//cout << WordSplit(B) << endl; // base,ball
	//cout << WordSplit(C) << endl; // abcg,efd
	//cout << WordSplit(D) << endl; // not possible
	//cout << WordSplit(E) << endl; // ab,bbbcd
	cout << WordSplit(F) << endl; // a,z
	return 0;
}