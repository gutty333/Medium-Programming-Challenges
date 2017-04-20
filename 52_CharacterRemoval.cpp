// For this challenge you will attempt to modify a word and then find it within a dictionary.
/*
have the function CharacterRemoval(strArr) read the array of strings stored in strArr, which will contain 2 elements: the first element will be a sequence of characters representing a word, and the second element will be a long string of comma-separated words, in alphabetical order, that represents a dictionary of some arbitrary length. For example: strArr can be: ["worlcde", "apple,bat,cat,goodbye,hello,yellow,why,world"]. Your goal is to determine the minimum number of characters, if any, can be removed from the word so that it matches one of the words from the dictionary. In this case, your program should return 2 because once you remove the characters "c" and "e" you are left with "world" and that exists within the dictionary. If the word cannot be found no matter what characters are removed, return -1.

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// NOT FINISHED


/*
have a list of the dictionary
compare each of the dictionary words to the target word
remove any letters from the target word not found in the current dictionary word
Check if that dictionary word is found after cleaning the target word
keep track of the character removal
*/

int CharacterRemoval(string strArr[])
{
	string word = strArr[0];
	int minRemoval = word.size() * 100;
	bool found = false;

	vector <string> list;
	string tempWord;

	// Have a list of the dictionary words
	for (int x = 0; x < strArr[1].size(); x++)
	{
		if (strArr[1][x] == ',')
		{
			list.push_back(tempWord);
			tempWord.clear();
		}
		else
		{
			tempWord.push_back(strArr[1][x]);

			if (x == strArr[1].size() - 1)
			{
				list.push_back(tempWord);
			}
		}
	}

	for (int x = 0; x < list.size(); x++)
	{
		int removal = 0;
		string temp;
		
		// Loop to remove non related characters from the target word when compared to the dictionary
		for (int y = 0; y < word.size(); y++)
		{
			if (list[x].find(word[y]) == -1)
			{
				removal++;
			}
			else
			{
				temp.push_back(word[y]);
			}
		}
		

		if (temp.size() > list[x].size())
		{

		}


		// Condition for if the current dictionary word is included in the target word
		if (temp.find(list[x]) != -1)
		{
			cout << "We found " << list[x] << " from " << temp << endl;
			found = true;

			if (temp.size() > list[x].size())
			{
				removal += temp.size() - list[x].size();
			}

			if (removal < minRemoval)
			{
				minRemoval = removal;
			}
		}

	}

	if (found)
	{
		return minRemoval;
	}
	else
	{
		return -1;
	}
}

int main() 
{
	string A[] = { "worlcde", "apple,bat,cat,goodbye,hello,yellow,why,world" };
	string B[] = { "baseball", "a,all,b,ball,bas,base,cat,code,d,e,quit,z" }; 
	string C[] = { "apbpleeeef", "a,ab,abc,abcg,b,c,dog,e,efd,zzzz" };
	string D[] = { "abcdefabcdef", "a,b,bfabcde,c,d,e,ee,eee,eeee,eeeeeeeee,fabc,go,goo,gooo" };
	cout << CharacterRemoval(A) << endl; // 2
	cout << CharacterRemoval(B) << endl; // 4
	cout << CharacterRemoval(C) << endl; // 8
	cout << CharacterRemoval(D) << endl; // 5

	return 0;
}