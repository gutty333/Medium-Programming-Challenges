#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool globe(string);
bool eyespot(string);
bool leg(string);


/*
must start with one or more A's 
the number of A's determines the size of the globe
A's are followed by CAT or TAC
is terminated by a single A
*/
bool globe(string input)
{
	string temp;
	int x = 0;

	// traverse the whole string 
	while (x < input.length())
	{
		// proceed as we come across the A's
		if (input[x] == 'A')
		{
			x++;
		}
		else
		{
			// condition to check the following substring after the A's
			// we traverse 3 steps if the strings match else we signal the sequence is not valid
			temp = input.substr(x, 3);

			if (temp == "TAC" || temp == "CAT")
			{
				x += 3;
			}
			else
			{
				return false;
			}
		}
	}

	// checking that the end only has a single A
	if (input[input.length() - 1] == 'A' && input[input.length() - 2] != 'A')
	{
		return true;
	}
	
	return false;
}

/*
starts with a T
if is on a stalk it will include legs
if not on a stalk it will have the pattern AG until the end
terminates with AG
*/
bool eyespot(string input)
{
	// assure the first base starts with T
	if (input[0] == 'T')
	{
		int x = 1;

		// traverse the string
		while (x < input.length())
		{
			// check if it is on a stalk
			if (input[x] == 'C')
			{
				int y;
				// loop to locate the end of a possible leg
				for (y = x; y < input.length() - 2; y++)
				{
					if (input[y] == 'T')
					{
						break;
					}
				}

				// condition to check the leg found is valid
				if (leg(input.substr(x, (y - x) + 1)))
				{
					x = y + 1;
				}
				else
				{
					return false;
				}
			}
			else if (input[x] == 'A' && input[x+1] == 'G') // condition checking the alternative of not being on a stalk
			{
				x += 2;
			}
			else
			{
				return false;
			}
		}

		return true;
	}

	return false;
}


/*
starts with a C
followed by one or more G's
the number of G's determine the length of the leg
terminated with a T
*/
bool leg(string input)
{
	// condition checking for first and last characters
	if (input[0] == 'C' && input[input.length() - 1] == 'T')
	{
		int x = 1; 

		// all characters in between the start and end must be a G
		while (x < input.length() - 1)
		{
			if (input[x] != 'G')
			{
				return false;
			}
			x++;
		}

		return true;
	}

	return false;
}

/*
the string will include a single head and is followed by one or more body segments
the head has a globe and ore or more eyespots

the single or multiple body segments consist of a globe followed by one or more legs
*/
bool squirmy(string input)
{
	bool globeFound = false;
	bool eyepotFound = false;
	bool legFound = false;
	int lastindex = 0;

	for (int x = 4; x < input.length(); x++)
	{
		// locate the globe
		if (!globeFound && globe(input.substr(lastindex, (x + 1) - lastindex)))
		{
			globeFound = true;
			lastindex = x + 1;
			x++;
		}
		// condition to locate the one or more eye spots
		else if (globeFound && eyespot(input.substr(lastindex, (x + 1) - lastindex)))
		{
			eyepotFound = true;
			globeFound = false;

			lastindex = x + 1;
			x++;
		}
		// locating the one or more legs
		else if (globeFound && eyepotFound && leg(input.substr(lastindex, (x + 1) - lastindex)))
		{
			legFound = true;

			lastindex = x + 1;
			x++;
		}
		else
		{
			legFound = false;
		}
	}

	if (globeFound && eyepotFound && legFound)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	vector <string> chromosomes;

	// taking input for the chromosomes
	int num;
	cin >> num;
	for (int x = 0; x < num; x++)
	{
		string temp;
		cin >> temp;
		chromosomes.push_back(temp);
	}


	cout << "SQUIRMY OUTPUT" << endl;
	for (int x = 0; x < num; x++)
	{
		cout << "Case " << x + 1 << ": " << (squirmy(chromosomes[x]) ? "YES" : "NO" )<< endl;
	}
	cout << "END OF OUTPUT" << endl;

	return 0;
}