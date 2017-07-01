#include <iostream>
using namespace std;

struct node
{
	int value;
	node* next;
};

int main()
{
	node* head;
	head = new node;
	head->value = 10;
	head->next = NULL;


	
	int count = 0;
	node* current = head;

	cout << "The starting root is " << head << endl << endl; 

	while (count < 5)
	{
		int lastValue = current->value;
		node* temp = new node;

		cout << endl << "\t" << ". Original = " << lastValue << " address is " << current << endl;
		cout << "\t" << ". Plus 2 = " << 2 + lastValue << endl;

		temp->value = 2+lastValue;
		temp->next = NULL;

		cout << "\t" << ". Temp Node Value = " << temp->value << endl;

		while (current->next != NULL)
		{
			current = current->next;
		}

		
		cout << "\t" << ". After Temp Node Value = " << temp->value << " Address is " << temp << endl;
		current->next = temp;

		current = current->next;
		cout << "\t" << ". Current Node Value = " << current->value << " address is " << current << endl;
		count++;
	}



	cout << endl << "Result " << head <<  endl;

	while (head)
	{
		cout << "Value " << head->value << endl;
		head = head->next;
	}



	int test = 20;
	int* test2 = &test;
	*test2 = 70;
	test2 = new int;
	*test2 = 100; 

	cout << endl << endl << "Original " << test << " and address is " << &test << endl;
	cout << "Pointer " << *test2 << " and address is " << test2 << endl;

	return 0;
}