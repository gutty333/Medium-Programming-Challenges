#include <iostream>
#include <vector>
using namespace std;


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* head = NULL;
node* tail = NULL;


void enqueue(int value)
{
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;

	if (head == NULL)
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}


void dequeue()
{
	if (head == NULL)
	{
		return;
	}
	else if (head == tail)
	{
		node* temp = head;

		head = tail = NULL;

		delete (temp);
	}
	else
	{
		node* temp = head;

		head = head->next;

		delete (temp);
	}
}


int main() {
	




	node* test;
	node* test3;

	node* test2 = new node;
	test2->data = 12;
	test2->next = NULL;

	test = test3 = test2;

	cout << "Address of test is " << test << " and value is " << test->data << endl;
	cout << "Address of test3 is " << test3 << " and value is " << test3->data << endl;


	node* temp1 = test;
	delete (temp1);
	cout << "Address of test is " << test << " and value is " << test->data << endl;
	cout << "Address of test3 is " << test3 << " and value is " << test3->data << endl;
	

	int num = 12;

	vector <vector<int>> list(num);

	list[0].push_back(14);

	cout << list[0][0] << endl;



	return 0;
}
