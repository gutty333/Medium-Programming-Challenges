#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <filesystem>
using namespace std;

int main()
{
	int list[] = { 4, 6, 7, 91, 23 };
	int list2[] = { 1, 56, 13, 8, 9 };

	vector <int> combine;
	int size = sizeof(list) / sizeof(list[0]);
	combine.insert(combine.begin(), list, list+size);
	size = sizeof(list2) / sizeof(list2[0]);
	combine.insert(combine.end(), list2, list2 + size);
	
	vector <int>::iterator test;
	test = combine.end()-1;

	cout << "the array length of list is " << sizeof(list) / sizeof(list[0]) << endl;

	for (int x = 0; x < combine.size(); x++)
	{
		cout << combine[x] << endl;
	}

	cout << char(97) << " and " << int('b') << endl;
	

	
	ofstream newFile;
	newFile.open("hiFile.txt");

	newFile << "hello world how are you doing" << endl;
	newFile.close();


	return 0;
}