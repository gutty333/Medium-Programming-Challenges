#include <iostream>
#include <string>
using namespace std;


struct Node
{
	int value;
	Node* next;
};

struct Fruit
{
	string name;
	Fruit* next;
};

void addFruit(Fruit* list, string name)
{
	Fruit* temp;
	temp = new Fruit;
	temp->name = name;
	temp->next = NULL;

	//Fruit* current = list;
	
	while (list->next != NULL)
	{
		list = list->next;
	}

	list->next = temp;
	list = list->next;
}

int main()
{
	Node* start;
	start = new Node;
	start->value = 8;
	start->next = NULL;
	

	Node* middle;
	middle = new Node;
	middle->value = 12;
	middle->next = NULL;

	Node* end;
	end = new Node;
	end->value = 18;
	end->next = NULL;

	cout << start << endl;
	cout << middle << endl;
	cout << end << endl;


	start->next = middle;
	middle->next = end;

	Node* current = start;
	current->value = 4;
	while (current != NULL)
	{
		cout << "The value is " << current->value << endl;
		current = current->next;
	}
	
	cout << endl << endl;
	Fruit* list;
	list = new Fruit;
	list->name = "apple";
	list->next = NULL;

	addFruit(list, "banana");
	addFruit(list, "cherry");
	addFruit(list, "mango");
	addFruit(list, "pear");
	addFruit(list, "tomato");
	
	
	while (list != NULL)
	{
		cout << "The value is " << list->name << endl;
		list = list->next;
	}

	return 0;
}