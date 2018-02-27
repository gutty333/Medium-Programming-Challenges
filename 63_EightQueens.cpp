// This challenge will require knowledge of chess pieces and their movements.
/*
have the function EightQueens(strArr) read strArr which will be an array consisting of the locations of eight Queens on a standard 8x8 chess board with no other pieces on the board. The structure of strArr will be the following: ["(x,y)", "(x,y)", ...] where (x,y) represents the position of the current queen on the chessboard (x and y will both range from 1 to 8 where 1,1 is the bottom-left of the chessboard and 8,8 is the top-right). Your program should determine if all of the queens are placed in such a way where none of them are attacking each other. If this is true for the given input, return the string true otherwise return the first queen in the list that is attacking another piece in the same format it was provided.

For example: if strArr is ["(2,1)", "(4,2)", "(6,3)", "(8,4)", "(3,5)", "(1,6)", "(7,7)", "(5,8)"] then your program should return the string true. The corresponding chessboard of queens for this input is below (taken from Wikipedia).
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool checkVertical(vector < vector<char> >, int, int);
bool checkHorizontal(vector < vector <char> >, int, int);
bool checkDiagonal(vector < vector <char> >, int, int);

/*
solution would involve first creating an empty chessboard
we would analyze the elements from the input string to position where the queens would go
starting from the first queen in the list
we analyze all possible paths (vertical, horizontal, diagonal)
if the current queen is attack any other we return it
else continue with the next queen to  analyze
if no attacks where found we return true
*/
string EightQueens(string strArr[]) 
{
	// creating the empty chess board
	vector < vector <char> > chessBoard(8);
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			chessBoard[x].push_back('-');
		}
	}

	// analyzing the string input to locate the locations of each queen
	for (int x = 0; x < 8; x++)
	{
		int currentRow = 8 - ((int)strArr[x][1]-48);
		int currentCol = (int)strArr[x][3] - 1 - 48;

		// updating the chessboard with current queen location
		chessBoard[currentRow][currentCol] = 'q';
	}

	// checking all queens for any attacks
	for (int x = 0; x < 8; x++)
	{
		int row = 8 - ((int)strArr[x][1] - 48);
		int col = (int)strArr[x][3] - 1 - 48;
		
		// condition to check no attacks where found in all the possible attacks routes for the current queen
		if (!(checkVertical(chessBoard, row, col) && checkHorizontal(chessBoard, row, col) && checkDiagonal(chessBoard, row, col)))
		{
			return strArr[x];
		}
	}

	return "true";
}

// method to check if any attacks happen while analyzing the vertical of current queen
bool checkVertical(vector < vector<char> > board, int row, int col)
{
	for (int x = 0; x < 8; x++)
	{
		if (x == row)
		{
			continue;
		}

		// condition to find an attack
		if (board[x][col] == 'q')
		{
			return false;
		}
	}

	return true;
}

// method to check if any attacks happen horizontal to the current queen
bool checkHorizontal(vector < vector<char> > board, int row, int col)
{
	for (int x = 0; x < 8; x++)
	{
		if (x == col)
		{
			continue;
		}

		if (board[row][x] == 'q')
		{
			return false;
		}
	}

	return true;
}

// method to check if any attacks happen diagonal to the current queen
bool checkDiagonal(vector < vector<char> > board, int row, int col)
{
	int currentRow = row;
	int currentCol = col;

	// to bottom right diagonal direction
	currentRow++;
	currentCol++;
	while (currentCol < 8 && currentRow < 8)
	{
		if (board[currentRow][currentCol] == 'q')
		{
			return false;
		}
		currentRow++;
		currentCol++;
	}

	// to top right diagonal direction
	currentRow = row - 1;
	currentCol = col + 1;
	while (currentCol < 8 && currentRow >= 0)
	{
		if (board[currentRow][currentCol] == 'q')
		{
			return false;
		}
		currentRow--;
		currentCol++;
	}

	// to bottom left diagonal direction
	currentRow = row + 1;
	currentCol = col - 1;
	while (currentCol >= 0 && currentRow < 8)
	{
		if (board[currentRow][currentCol] == 'q')
		{
			return false;
		}
		currentRow++;
		currentCol--;
	}

	// to top left diagonal direction
	currentRow = row - 1;
	currentCol = col - 1;
	while (currentCol >= 0 && currentRow >= 0)
	{
		if (board[currentRow][currentCol] == 'q')
		{
			return false;
		}
		currentRow--;
		currentCol--;
	}

	return true;
}

int main() 
{
	string A[] = { "(2,1)", "(4,2)", "(6,3)", "(8,4)", "(3,5)", "(1,6)", "(7,7)", "(5,8)" };
	string B[] = { "(2,1)", "(4,3)", "(6,3)", "(8,4)", "(3,4)", "(1,6)", "(7,7)", "(5,8)" };
	string C[] = { "(2,1)", "(5,3)", "(6,3)", "(8,4)", "(3,4)", "(1,8)", "(7,7)", "(5,8)" };

	cout << EightQueens(A) << endl; // true
	cout << EightQueens(B) << endl; // (2,1)
	cout << EightQueens(C) << endl; // (5,3)
	return 0;

}