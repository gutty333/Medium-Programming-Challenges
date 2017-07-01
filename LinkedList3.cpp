#include <iostream>
#include <string>
using namespace std;

struct node
{
	int value;
	node* next;
};


void addBack(node* list, int value)
{
	node* temp = new node;
	temp->value = value;
	temp->next = NULL;


	while (list->next != NULL)
	{
		list = list->next;
	}

	list->next = temp;
}

void addFront(node*& list, int value)
{
	node* temp = new node;
	temp->value = value;
	temp->next = NULL;

	temp->next = list;
	list = temp;
}

void printList(node* list)
{
	cout << endl << "RESULT" << endl;
	while (list)
	{
		cout << list->value << endl;
		list = list->next;
	}
}

void removeBack(node* list)
{
	while (list->next != NULL)
	{
		
		if (list->next->next == NULL)
		{

			list->next = NULL;
			return;
		}
		list = list->next;
	}

}


void removeFront(node*& list)
{
	list = list->next;
}

void searchValue(node* list, int value)
{
	while (list)
	{
		if (list->value == value)
		{
			cout << "FOUND" << endl;
			return;
		}

		list = list->next;
	}

	cout << "NOT FOUND" << endl;
}

int main()
{
	node* list = new node;
	list->value = 10;
	list->next = NULL;


	printList(list);

	addBack(list, 20);
	addBack(list, 30);
	addBack(list, 40);
	addBack(list, 50);
	addBack(list, 60);

	printList(list);


	addFront(list, 5);
	addFront(list, 7);
	addBack(list, 80);

	printList(list);

	cout << endl << "Remove Test" << endl;
	removeBack(list);
	removeBack(list);
	printList(list);
	removeFront(list);
	printList(list);


	searchValue(list, 40);
	searchValue(list, 80);
	searchValue(list, 5);


	return 0;
}