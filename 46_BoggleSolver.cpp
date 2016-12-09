// For this challenge you will attempt to find words in a matrix of letters.
/*
have the function BoggleSolver(strArr) read the array of strings stored in strArr, which will contain 2 elements: the first element will represent a 4x4 matrix of letters, and the second element will be a long string of comma-separated words each at least 3 letters long, in alphabetical order, that represents a dictionary of some arbitrary length. For example: strArr can be: ["rbfg, ukop, fgub, mnry", "bog,bop,gup,fur,ruk"]. Your goal is to determine if all the comma separated words as the second parameter exist in the 4x4 matrix of letters. For this example, the matrix looks like the following:

r b f g
u k o p
f g u b
m n r y

The rules to make a word are as follows:

1. A word can be constructed from sequentially adjacent spots in the matrix, where adjacent means moving horizontally, vertically, or diagonally in any direction.
2. A word cannot use the same location twice to construct itself.

The rules are similar to the game of Boggle. So for the example above, all the words exist in that matrix so your program should return the string true. If all the words cannot be found, then return a comma separated string of the words that cannot be found, in the order they appear in the dictionary.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
set up the first element into a matrix of letters
this will be easier to later check adjacent spots
iterate through the second element word by word
used the current word and analyzed if it can be found in our list 
The method we will use is start with the first letter, check if the list has that first letter
From the first letter check for adjacent options where the next letter is also matched
Check for multiple options that is if multiple matching letters are adjacent
analyze from one of the options and check if the word is found, if not try the other options
Continue the process to see if all the letters can be found
*/


// Starting our first letter location
// This function will analyze the neighbors and check if it completes the word
// It will also be used recursively to handle cases in which there are multiple adjacent matching letters
// It will follow that trail, analyzing multiple options, try one of the options, if fail try other options
// The process will continue until all options have been tried
bool findAdjacent(vector <vector <char> > letters, string value, int row,int col, int currentIndex, int lastIndex)
{
	int index = currentIndex;
	
	// Keep a record of our last step
	// To properly develop this program we could have a list that tracks all the steps we have taken
	// This will prevent us from going into those locations again
	// For this purpose we are only avoiding the last step taken
	int lastStep = lastIndex;
	
	// We continue to loop until the end of our current word
	while (index < value.length())
	{
		bool found = false;

		// Conditions for boundary check and also check adjacent neighbors
		// Checking up
		if (lastStep != 1)
		{
			if (row != 0 && letters[row - 1][col] == value[index])
			{
				index++; // update the index of our target word
				row--; // update row/cols for the movement
				lastStep = 0; // update our the last location

				// Recursive call to now analyze this path
				found = findAdjacent(letters, value, row, col, index, lastStep);

				// If this path failed, bring the index back down to analyze other adjacent neighbors
				if (!found)
				{
					index--;
				}
			}
		}

		// Checking left
		if (lastStep != 2)
		{
			if (col != 0 && letters[row][col - 1] == value[index])
			{
				index++;
				col--;
				lastStep = 3;
				found = findAdjacent(letters, value, row, col, index, lastStep);
				if (!found)
				{
					index--;
				}
			}
		}

		// Checking down
		if (lastStep != 0)
		{
			if (row != 3 && letters[row + 1][col] == value[index])
			{
				index++;
				row++;
				lastStep = 1;
				found = findAdjacent(letters, value, row, col, index, lastStep);
				if (!found)
				{
					index--;
				}
			}
		}

		// Checking right
		if (lastStep != 3)
		{
			if (col != 3 && letters[row][col + 1] == value[index])
			{
				index++;
				col++;
				lastStep = 2;
				found = findAdjacent(letters, value, row, col, index, lastStep);
				if (!found)
				{
					index--;
				}
			}
		}

		// Checking diagonal top left
		if (lastStep != 4)
		{
			if (row != 0 && col != 0 && letters[row - 1][col - 1] == value[index])
			{
				index++;
				row--;
				col--;
				lastStep = 5;
				found = findAdjacent(letters, value, row, col, index, lastStep);
				if (!found)
				{
					index--;
				}
			}
		}

		// Checking diagonal top right
		if (lastStep != 6)
		{
			if (row != 0 && col != 3 && letters[row - 1][col + 1] == value[index])
			{
				index++;
				row--;
				col++;
				lastStep = 7;
				found = findAdjacent(letters, value, row, col, index, lastStep);
				if (!found)
				{
					index--;
				}
			}
		}

		// Checking diagonal bottom left
		if (lastStep != 7)
		{
			if (row != 3 && col != 0 && letters[row + 1][col - 1] == value[index])
			{
				index++;
				row++;
				col--;
				lastStep = 6;
				found = findAdjacent(letters, value, row, col, index, lastStep);
				if (!found)
				{
					index--;
				}
			}
		}

		// Checking diagonal bottom right
		if (lastStep != 5)
		{
			if (row != 3 && col != 3 && letters[row + 1][col + 1] == value[index])
			{
				index++;
				row++;
				col++;
				lastStep = 4;
				found = findAdjacent(letters, value, row, col, index, lastStep);
			}
		}
		
		// Condition if no adjacent correct letter was found
		if (!found)
		{
			return false;
		}
	}
	
	return true;
}

// Check and find first letter of current word in our matrix
bool search(vector <vector <char> > letters, char value, string word)
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (value == letters[row][col] && findAdjacent(letters,word,row,col, 1, -1))
			{
				return true;
			}
		}
	}
	return false;
}

// Analyze current word
bool boogle(vector <vector <char> > letters, string value)
{
	if (search(letters, value[0], value))
	{
		return true;
	}
	else
	{
		return false;
	}
}

string BoggleSolver(string strArr[]) 
{
	vector <vector <char> > letterMatrix(4);

	// Loop to extract the values of the first element and create a 4x4 matrix of letters
	for (int x = 0,row = 0; x < strArr[0].length(); x++)
	{
		if (strArr[0][x] == ',')
		{
			row++;
		}
		else if (strArr[0][x] >= 'a'&& strArr[0][x] <= 'z' || strArr[0][x] >= 'A' && strArr[0][x] <= 'Z')
		{
			letterMatrix[row].push_back(strArr[0][x]);
		}
	}
	
	string temp;
	string errors;

	// Iterate through the second element to analyze the words
	for (int x = 0; x < strArr[1].length(); x++)
	{
		// Condition to separate the words
		if (strArr[1][x] == ',' || x == strArr[1].length() - 1)
		{
			if (x == strArr[1].length() - 1)
			{
				temp += strArr[1][x];
			}

			// If the word was not found in our matrix store it
			if (!boogle(letterMatrix, temp))
			{
				errors += temp;
				errors += ',';
			}
			temp.clear();
		}
		else if (strArr[1][x] >= 'a'&& strArr[1][x] <= 'z' || strArr[1][x] >= 'A' && strArr[1][x] <= 'Z')
		{
			temp += strArr[1][x];
		}
	}

	if (errors.length() > 0)
	{
		errors.erase(errors.end() - 1);
		return errors;
	}
	else
	{
		return "true";
	}
}

int main() 
{
	string A[] = { "rbfg, ukop, fgub, mnry", "bog,bop,gup,fur,ruk" };
	string B[] = { "aaey, rrum, tgmn, ball", "all,ball,mur,raeymnl,tall,true,trum" };
	string C[] = { "aaey, rrum, tgmn, ball", "all,ball,mur,raeymnl,rumk,tall,true,trum,yes" };
	string D[] = { "abfr, ryut, gmei, fadc", "abyba" };
	string E[] = { "abfr, ryut, gmei, fadc", "abyba,cdeicz" };

	cout << BoggleSolver(A) << endl; // true
	cout << BoggleSolver(B) << endl; // true
	cout << BoggleSolver(C) << endl; // rumk,yes
	cout << BoggleSolver(D) << endl; // abyba
	cout << BoggleSolver(E) << endl; // abyba,cedicz

	return 0;
}
