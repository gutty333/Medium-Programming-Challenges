// For this challenge you will determine whether HTML elements are nested correctly.
/*
have the function HTMLElements(str) read the str parameter being passed which will be a string of HTML DOM elements and plain text. The elements that will be used are: b, i, em, div, p. For example: if str is "<div><b><p>hello world</p></b></div>" then this string of DOM elements is nested correctly so your program should return the string true.

If a string is not nested correctly, return the first element encountered where, if changed into a different element, would result in a properly formatted string. If the string is not formatted properly, then it will only be one element that needs to be changed. For example: if str is "<div><i>hello</i>world</b>" then your program should return the string div because if the first <div> element were changed into a <b>, the string would be properly formatted.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
only analyze html elements
store the tags as they appear in order
check the current open tag and make sure it has no errors
continue iterating and analyze the other open tags
remember an open tag must have a closing tag of its own
*/

bool search(vector <int> list, int value)
{
	for (int x = 0; x < list.size(); x++)
	{
		if (value == list[x])
		{
			return true;
		}
	}
	return false;
}

string HTMLElements(string str) 
{
	vector <string> elements;
	string temp;

	// Loop to extract the html elements
	for (int x = 0; x < str.length(); x++)
	{
		// marks the end of a tag that we must store in the list
		if (str[x] == '>' || x == str.length() - 1)
		{
			// Storing the last tag if is it a valid element
			if (x == str.length() - 1 && temp[0] == '<')
			{
				temp += str[x];
				elements.push_back(temp);
				break;
			}
			
			if (temp[0] == '<')
			{
				temp += str[x];
				elements.push_back(temp);
			}

			temp.clear(); // clear the string to create new valid elements
		}
		else if (str[x] == '<')
		{
			temp += str[x];
		}
		else if (temp.length() > 0 && temp[0] == '<')
		{
			temp += str[x];
		}
	}

	// In the case we only have one html element
	if (elements.size() == 1)
	{
		elements[0].erase(elements[0].begin());
		elements[0].erase(elements[0].end() - 1);
		return elements[0];
	}

	// Loop to analyze open tags
	// It will step through each tag and check for duplicates
	// If any are encountered we need to check they have their own closing tag
	for (int x = 0; x < elements.size()-1; x++)
	{
		// Condition to only analyze opening tags
		if (elements[x][1] != '/')
		{
			string temp = elements[x];
			// Setting up the current open tag and correct closing tag to use for comparison
			string currentClose = temp.insert(1, "/");
			string currentOpen = elements[x];
			vector <int> indexLocations;

			int close = 0; // Checks how many correct closing tags we have
			int closeNeeded = 1; // Details how many correct closing tags we currently need

			int index=x+1;

			// Loop to check for any elements similar to our current
			for (int y = x + 1; y < elements.size(); y++)
			{
				if (currentOpen == elements[y])
				{
					// Update our need amount since we now have a duplicate that also requires a closing tag
					closeNeeded++;
					index = y;
				}
			}

			// Loop to check if the open tags were properly close
			for (int i = 1; i < closeNeeded; i++)
			{
				bool duplicateClose = false;
				for (index; index < elements.size(); index++)
				{
					// Check if a closing was found for the duplicate
					if (elements[index] == currentClose)
					{
						duplicateClose = true;

						indexLocations.push_back(index);
						// Update our index to avoid repeating the same closing tag
						index++;
						break;
					}
				}

				// Condition to check that the duplicate was correctly closed
				if (duplicateClose)
				{
					// Update our closing tag
					close++;
				}
				else
				{
					// Edit the string so we return the HTML element without the < > symbols
					currentOpen.erase(currentOpen.begin());
					currentOpen.erase(currentOpen.end() - 1);
					return currentOpen;
				}
			}

			// After we analyze the duplicate, we check back on the current to find its closing pair
			for (int y = x + 1; y < elements.size(); y++)
			{
				// Condition to make sure that the closing tag we find has not been used previously
				if (elements[y] == currentClose && !(search(indexLocations, y)))
				{
					close++;
					break;
				}
			}
			
			// Condition to check that the current open tag was valid and had its closing tag
			// For example if we had 2 duplicates we need a total of 3 closing tags which includes one for the current also
			if (close != closeNeeded)
			{
				currentOpen.erase(currentOpen.begin());
				currentOpen.erase(currentOpen.end()-1);
				return currentOpen;
			}
		}
	}

	return "true";
}

int main() 
{
	cout << HTMLElements("<div><b><p>hello world</p></b></div>") << endl; // true
	cout << HTMLElements("<div><i>hello</i>world</b>") << endl; // div
	cout << HTMLElements("<div><div><b></b></div></p>") << endl; // div
	cout << HTMLElements("<div>abc</div><p><em><i>test test test</b></em></p>") << endl; // i
	cout << HTMLElements("hello world<p></p><div><em><b></b></em></p>") << endl; // div
	cout << HTMLElements("<div>") << endl; // div
	cout << HTMLElements("<p><p><em></em><p></p><i></p>") << endl; // i
	cout << HTMLElements("<em></em><em></em><p></b>") << endl; // p

	return 0;
}