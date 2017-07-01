#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Report
{
private:
	string name;
	string description;
	int age;
	int income;
	string filename;
	ofstream write;

public:
	Report();
	string getName();
	string getDescription();
	string getFileName();
	int getAge();
	int getIncome();

	void setName(string);
	void setDescription(string);
	void setFileName(string);
	void setAge(int);
	void setIncome(int);
	void createFile();

};


Report::Report()
{
	name = "";
	description = "";
	age = income = 0;
	filename = "test.txt";
}

void Report::setName(string n)
{
	name = n;
}
void Report::setDescription(string d)
{
	description = d;
}
void Report::setFileName(string f)
{
	filename = f;
	filename += ".txt";
}
void Report::setAge(int a)
{
	age = a;
}
void Report::setIncome(int i)
{
	income = i;
}


string Report::getName()
{
	return name;
}
string Report::getDescription()
{
	return description;
}
string Report::getFileName()
{
	return filename;
}
int Report::getAge()
{
	return age;
}
int Report::getIncome()
{
	return income;
}

void Report::createFile()
{
	write.open(filename);

	write << "Report for " << name << endl;
	write << "Your age is " << age << endl;
	write << "Your income is " << income << endl;
	write << description << endl;

	write.close();
}


int main()
{
	string name, description, filename;
	int age, income;


	cout << "Welcome, please enter your name" << endl;
	getline(cin, name);
	cout << "What is your age" << endl;
	cin >> age;
	cout << "What is your income" << endl;
	cin >> income;
	cout << "Enter a description" << endl;
	cin.ignore();
	getline(cin, description);
	cout << "Enter a filename" << endl;
	cin >> filename;


	Report person;

	person.setName(name);
	person.setAge(age);
	person.setDescription(description);
	person.setIncome(income);
	person.setFileName(filename);
	person.createFile();


	ifstream result(person.getFileName());
	cout << endl;
	if (result.is_open())
	{
		string line;

		while (getline(result, line))
		{
			cout << line << endl;
		}
	}
	else
	{
		cout << "Unable to open the file " << person.getFileName() << endl;
		return -1;
	}






	return 0;
}