#include <iostream>
#include <string>
using namespace std;


struct node
{
	int data;
	node* next;
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

// Insert Node at the end
void insertNode(node*& list, int value)
{
	node* temp = new node;
	temp->data = value;
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
	}
}

// Delete the last node
void deleteNode(node*& list)
{
	if (list->next == NULL)
	{
		list = NULL;
	}
	else
	{
		node* current = list;

		while (current->next->next != NULL)
		{
			current = current->next;
		}

		node* temp = current->next;
		current->next = temp->next;

		delete(temp);
	}
}

// Reverse linked list function
void ReverseList(node*& list)
{
	node* current = list;
	node* prev = NULL;
	

	while (current->next != NULL)
	{
		node* next = current->next;
		current->next = prev;
		prev = current;
		
		current = next;
	}

	current->next = prev;
	list = current;
}

int main()
{
	node* list = NULL;

	insertNode(list, 4);
	insertNode(list, 6);
	insertNode(list, 8);
	insertNode(list, 12);
	insertNode(list, 14);
	insertNode(list, 16);
	print(list);

	deleteNode(list);
	deleteNode(list);
	print(list);

	ReverseList(list);
	print(list);

	insertNode(list, 32);
	insertNode(list, 24);
	insertNode(list, 46);
	print(list);

	ReverseList(list);
	print(list);

	return 0;
}