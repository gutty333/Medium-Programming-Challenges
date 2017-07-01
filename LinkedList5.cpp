#include <iostream>
using namespace std;
// Double linked list personal practice

struct node
{
	int data;
	node* next;
	node* prev;
};

// Printing the list
void print(node* list)
{
	while (list)
	{
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
}

// Inserting a node at the end
void insertNode(node*& list, int value)
{
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;
	temp->prev = NULL;

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

		temp->prev = current;
		current->next = temp;
	}
}

// Deleting the last node
void deleteNode(node*& list)
{
	if (list->next == NULL)
	{
		list = NULL;
	}
	else
	{
		node* current = list;

		while (current->next != NULL)
		{
			current = current->next;
		}

		current->prev->next = current->next;
		delete(current);
	}
}

// Reversing the list
void reverseList(node*& list)
{
	node* current = list;
	while (current->next != NULL)
	{
		node* temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		current = temp;
	}

	current->next = current->prev;
	current->prev = NULL;
	list = current;
}


// Inserting a node at a specific location
void insertNode2(node*& list, int value, int index)
{
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;
	temp->prev = NULL;

	if (index == 1)
	{
		temp->next = list;
		list->prev = temp;
		list = temp;
	}
	else
	{
		node* current = list;

		for (int x = 0; x < index-2; x++)
		{
			current = current->next;
		}

		temp->prev = current;
		temp->next = current->next;
		current->next->prev = temp;
		current->next = temp;

	}
}

int main()
{
	node* list= NULL;
	insertNode(list, 2);
	insertNode(list, 4);
	insertNode(list, 6);
	insertNode(list, 8);
	insertNode(list, 10);
	insertNode(list, 12);
	print(list);


	reverseList(list);
	print(list);
	
	insertNode2(list, 33, 1);
	insertNode2(list, 45, 3);
	print(list);

	reverseList(list);
	print(list);
	return 0;
}