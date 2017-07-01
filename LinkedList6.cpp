#include <iostream>
using namespace std;


struct node
{
	int data;
	node* next;
	node* prev;
};


void print(node* list)
{
	while (list)
	{
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
}


void insertNode(node*& list, int value)
{
	node* temp = new node;
	temp->data = value;
	temp->prev = NULL;
	temp->next = NULL;

	if (list == NULL)
	{
		list = temp;
	}
	else
	{
		node* current = list;

		while (current->next != NULL)
		{
			current = current->next;
		}


		current->next = temp;
		temp->prev = current;

	}
}


// Will insert values in a sorted order each time
void insertSort(node*& list, int value)
{
	node* temp = new node;
	temp->data = value;
	temp->prev = NULL;
	temp->next = NULL;

	if (list == NULL)
	{
		list = temp;
		return;
	}

	if (temp->data < list->data)
	{
		temp->next = list;
		list->prev = temp;
		list = temp;
		return;
	}
	

	node* current = list;

	while (current->next != NULL)
	{
		if (temp->data < current->next->data)
		{
			node* temp2 = current->next;
			current->next = temp;
			temp->next = temp2;
			temp->prev = current;
			temp2->prev = temp;
			return;
		}

		current = current->next;
	}

	if (temp->data < current->data)
	{
		node* temp3 = current->prev;

		temp->next = current;
		current->prev = temp;
		temp->prev = temp3;
		temp3->next = temp;
	}
	else
	{
		current->next = temp;
		temp->prev = current;
	}
}

int main()
{
	node* list = NULL;

	insertSort(list, 12);
	insertSort(list, 4);
	insertSort(list, 6);
	print(list);

	insertSort(list, 5);
	insertSort(list, 3);
	insertSort(list, 10);
	insertSort(list, 11);
	print(list);


	return 0;
}