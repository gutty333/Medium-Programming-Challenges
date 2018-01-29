#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// structure to represent a vertex
struct node
{
	int cost;
	bool visited;
	vector <int> neighborsCost;
};

void shortestPath(vector <node*>& graph, int source)
{
	queue <node*> list;
	graph[source - 1]->cost = 0;
	list.push(graph[source - 1]);

	// applying a simple BFS
	while (!list.empty())
	{
		node* current = list.front();
		list.pop();
		current->visited = true;

		// checking the neighbors of our current node
		// we are always updating the distance to neighbors if we find a more optimal value
		for (int x = 0; x < current->neighborsCost.size(); x++)
		{
			int cost = current->neighborsCost[x];

			// condition that checks if there is a connection and if the current connection has not yet been visited
			if (cost != -1 && graph[x]->visited == false)
			{
				// doing edge relaxation
				// analyze the current cost it take from current to that node
				// if the current path there is the best choice, we update its cost
				int newCost = cost + current->cost;
				if (newCost < graph[x]->cost)
				{
					graph[x]->cost = newCost;
				}

				// adding the neighbor to our queue
				list.push(graph[x]);
			}
		}
	}
}

int main()
{
	int n;
	int source;

	string filename;
	cout << "enter file name (include the extension)" << endl;
	cin >> filename;

	ifstream readFile(filename);

	readFile >> n; // get the number of vertices
	readFile >> source; //  get the source node

	// setting up our graph
	vector <node*> graph;
	for (int x = 0; x < n; x++)
	{
		graph.push_back(new node);
		graph[x]->cost = 1000*100; // by default we set them all to infinity in this case just setting a high value
		graph[x]->visited = false;
	}

	// loop to extract cost of each distance from current node
	int index = 0;
	int count = 0;
	while (index < n)
	{
		string temp;
		readFile >> temp;
		int num;

		// condition utilize to convert to an int data type
		if (temp != "-")
		{
			num = stoi(temp);
		}
		else
		{
			num = -1;
		}
		
		// adding it to current list
		// note no connections as signaled as -1
		graph[index]->neighborsCost.push_back(num);

		// keeping track of which node we are modifying
		count++;
		if (count == n)
		{
			count = 0;
			index++;
		}
	}

	// calling our shortest path method
	shortestPath(graph, source);

	// outputting the result
	for (int x = 0; x < graph.size(); x++)
	{
		if (source == x + 1)
		{
			continue;
		}
		
		cout << "(" << source << " -> " << x + 1 << ") = " << graph[x]->cost << endl;
	}
	
	return 0;
}