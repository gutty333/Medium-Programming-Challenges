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
Continue the process to see if all the letters can be found
*/


// From our first letter location
// This function will analyze the neighbors and check if it completes the word
bool findAdjacent(vector <vector <char> > letters, string value, int row,int col)
{
	int index = 1;

	// We continue to loop until the end of our current word
	while (index < value.length())
	{
		bool found = false;

		// Condition for boundary check and also check adjacent neighbors
		// In the case the index is in the first row
		if (row == 0)
		{
			if (letters[row + 1][col] == value[index])
			{
				index++;
				row++;
				found = true;
			}
			else if (col == 0)
			{
				if (letters[row][col + 1] == value[index])
				{
					index++;
					col++;
					found = true;
				}
				else if (letters[row+1][col + 1] == value[index])
				{
					index++;
					row++;
					col++;
					found = true;
				}
			}
			else if (col == 3)
			{
				if (letters[row][col - 1] == value[index])
				{
					index++;
					col--;
					found = true;
				}
				else if (letters[row + 1][col - 1] == value[index])
				{
					index++;
					row++;
					col--;
					found = true;
				}
			}
			else
			{
				if (letters[row][col + 1] == value[index])
				{
					index++;
					col++;
					found = true;
				}
				else if (letters[row + 1][col + 1] == value[index])
				{
					index++;
					row++;
					col++;
					found = true;
				}
				else if (letters[row][col - 1] == value[index])
				{
					index++;
					col--;
					found = true;
				}
				else if (letters[row + 1][col - 1] == value[index])
				{
					index++;
					row++;
					col--;
					found = true;
				}
			}
		}
		// In the case the index is in the last row
		else if (row == 3)
		{
			if (letters[row - 1][col] == value[index])
			{
				index++;
				row--;
				found = true;
			}
			else if (col == 0)
			{
				if (letters[row][col + 1] == value[index])
				{
					index++;
					col++;
					found = true;
				}
				else if (letters[row - 1][col + 1] == value[index])
				{
					index++;
					row--;
					col++;
					found = true;
				}
			}
			else if (col == 3)
			{
				if (letters[row][col - 1] == value[index])
				{
					index++;
					col--;
					found = true;
				}
				else if (letters[row - 1][col - 1] == value[index])
				{
					index++;
					col--;
					row--;
					found = true;
				}
			}
			else
			{
				if (letters[row][col + 1] == value[index])
				{
					index++;
					col++;
					found = true;
				}
				else if (letters[row - 1][col + 1] == value[index])
				{
					index++;
					row--;
					col++;
					found = true;
				}
				else if (letters[row][col - 1] == value[index])
				{
					index++;
					col--;
					found = true;
				}
				else if (letters[row - 1][col - 1] == value[index])
				{
					index++;
					row--;
					col--;
					found = true;
				}
			}
		}
		else
		{
			if (letters[row + 1][col] == value[index])
			{
				index++;
				row++;
				found = true;
			}
			else if (letters[row - 1][col] == value[index])
			{
				index++;
				row--;
				found = true;
			}
			else if (col == 0)
			{
				if (letters[row][col + 1] == value[index])
				{
					index++;
					col++;
					found = true;
				}
				else if (letters[row + 1][col + 1] == value[index])
				{
					index++;
					row++;
					col++;
					found = true;
				}
				else if (letters[row - 1][col + 1] == value[index])
				{
					index++;
					row--;
					col++;
					found = true;
				}
			}
			else if (col == 3)
			{
				if (letters[row][col - 1] == value[index])
				{
					index++;
					col--;
					found = true;
				}
				else if (letters[row + 1][col - 1] == value[index])
				{
					index++;
					row++;
					col--;
					found = true;
				}
				else if (letters[row - 1][col - 1] == value[index])
				{
					index++;
					row--;
					col--;
					found = true;
				}
			}
			else
			{
				if (letters[row][col + 1] == value[index])
				{
					index++;
					col++;
					found = true;
				}
				else if (letters[row + 1][col + 1] == value[index])
				{
					index++;
					found = true;
				}
				else if (letters[row][col - 1] == value[index])
				{
					index++;
					col--;
					found = true;
				}
				else if (letters[row + 1][col - 1] == value[index])
				{
					index++;
					row++;
					col--;
					found = true;
				}
				else if (letters[row - 1][col + 1] == value[index])
				{
					index++;
					row--;
					col++;
					found = true;
				}
				else if (letters[row][col - 1] == value[index])
				{
					index++;
					col--;
					found = true;
				}
				else if (letters[row - 1][col - 1] == value[index])
				{
					index++;
					row--;
					col--;
					found = true;
				}
			}
		}

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
			if (value == letters[row][col] && findAdjacent(letters,word,row,col))
			{
				cout << word << " was found" << endl;
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

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			cout << letterMatrix[row][col] << " ";
		}
		cout << endl;
	}

	// Iterate through the second element to analyze the words
	for (int x = 0; x < strArr[1].length(); x++)
	{
		if (strArr[1][x] == ',' || x == strArr[1].length() - 1)
		{
			if (x == strArr[1].length() - 1)
			{
				temp += strArr[1][x];
			}

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
		return "Good";
	}
}

int main() 
{
	string A[] = { "rbfg, ukop, fgub, mnry", "bog,bop,gup,fur,ruk" };
	string B[] = { "aaey, rrum, tgmn, ball", "all,ball,mur,raeymnl,tall,true,trum" };
	string C[] = { "aaey, rrum, tgmn, ball", "all,ball,mur,raeymnl,rumk,tall,true,trum,yes" };

	cout << BoggleSolver(A) << endl; // true
	cout << BoggleSolver(B) << endl; // true
	cout << BoggleSolver(C) << endl; // rumk,yes

	return 0;

}
