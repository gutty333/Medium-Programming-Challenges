#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ofstream test("person.txt");

	test << "Jake" << endl;
	test << "Age 23" << endl;
	test << "Income is 47" << endl;
	test.close();

	test.open("person.txt", ios::app);

	for (int x = 0; x < 5; x++)
	{
		test << x + 1 << ". Hello there" << endl;
	}
	test.close();


	ifstream test2("person.txt");

	string line;
	char letter;
	if (test2.is_open())
	{
		cout << "file opened correctly" << endl;

		while (test2.get(letter))
		{
			cout << letter << endl;
		}
	}
	

	double num = 2.95;
	cout << int(num) << endl;

	return 0;
}