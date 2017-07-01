#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include <filesystem>
using namespace std;


int testFunc(int num)
{
	int result = 0;
	while (num > 0)
	{
		int temp = num % 10;
		result += temp * temp;
		num /= 10;
	}

	return result;
}


void testFunc2(int number)
{
	/*
	take input and get the square of each digit
	check the sum
	if not 1 take that sum and repeat

	*/
	//Write your solution code below this line
	
	int cycle_no, finalNumber;
	for (int x = 1; x <= 10; x++)
	{
		// Break the number down to calculate the sum
		int sum = 0;
		while (number > 0)
		{
			int temp = number % 10;
			number /= 10;

			sum += temp*temp;
		}

		if (sum == 1)
		{
			finalNumber = number;
			cycle_no = x;
			break;
		}
		else
		{
			number = sum;
			if (x == 10)
			{
				finalNumber = number;
				cycle_no = x;
			}
		}
	}

	cout << "The number is " << finalNumber << " and the cycle is " << cycle_no << endl;
}


void finalFunc(int num)
{
	int maxRPM = num * 8;
	cout << "The limit is " << maxRPM << endl;
	for (int x = 1; x <= 10; x++)
	{
		int sum = 0;
		int original = num;

		// Getting sum of RPM digits
		while (num > 0)
		{
			int temp = num % 10;
			sum += temp*temp;
			num /= 10;
		}

		// Multiply by 323
		sum *= 323;

		// Getting last 2 number
		// since we wont do the shift of the last digit we will exclude it
		int count = 3;
		int temp = 0;
		while (count > 0)
		{
			if (count == 3)
			{
				original /= 10;
				count--;
				continue;
			}
			else if (count == 2)
			{
				temp = original % 10;
				original /=10;
				temp += (original % 10) * 10;
				break;
			}
		}

		num = sum + temp;
		cout << "The rpm is " << num << " and the year is " << x << endl;
		if (num > maxRPM)
		{
			break;
		}
	}
}

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


	
	for (int x = 1; x <= 100; x++)
	{
		if (x % 3 == 0 && x % 5 == 0)
		{
			cout << "FizzBuzz" << endl;
		}
		else if (x % 3 == 0)
		{
			cout << "Fizz" << endl;
		}
		else if (x % 5 == 0)
		{
			cout << "Buzz" << endl;
		}
		else
		{
			cout << x << endl;
		}
	}


	cout << setfill('-') << setw(9) << "hi" << endl;

	/*string num;
	cout << "Enter a number" << endl;
	cin >> num;

	for (int x = num.length() - 1; x >= 0; x--)
	{
		if (num[x] == '9')
		{
			num[x] = '0';
		}
		else
		{
			num[x] = char(int(num[x]) + 1);
			break;
		}
	}
	cout << "the result is " << num << endl;*/

	srand(time(0));

	for (int x = 0; true; x++)
	{
		int num = rand()%19;

		if (num == 10)
		{
			cout << "Number was 10 " << num << endl;
			break;
		}
		else
		{
			cout << num << endl;
		}
	}


	cout << testFunc(234) << endl;


	cout << "Here " << endl;
	testFunc2(108);
	testFunc2(454);


	finalFunc(7824);
	return 0;

	
}