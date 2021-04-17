#include <iostream>
#include <vector>
#include<algorithm>
#include "travelling_salesman.h"
using namespace std;

int V=-1;
int num_of_nodes;
int g[10][10]; 


void TVS::DisplayGraph(){
	cout << "\n \t Graph \n";
	cout << "------------------------" << endl;
	for(int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			cout<< " "<< g[i][j];
		}
		cout << endl;
	}
	cout << "------------------------" << endl;
}


void TVS::AddNodes(){
	if (V == num_of_nodes) {
		cout << "------------------------------------------------------------------------------------------------------------------"<<endl;
		cout << "You can not add new nodes. The graph has already "<<num_of_nodes <<" nodes. After deletation you can add node "<<endl;
		cout << "------------------------------------------------------------------------------------------------------------------"<<endl;
		return;
	}
	V++;
	cout << "Node " << V << " is added " << endl;
	for (int i = 0; i < V; ++i) {
		g[i][V - 1] = 0;
		g[V - 1][i] = 0;
	}
}

void TVS::AddEdges(int i, int j, int distance) {
	
	if (i == j) {
		cout << "Same node";
	}
	if ((i >= V) || (j > V)) {
		cout << "Node does not exists";
	}
	else {
		g[j][i] = distance;
		g[i][j] = distance;
	}
}


void TVS::RemoveNodes(int node)
{
	if (node > V) {
		cout << "\n Node does not exist";
		return;
	}
	else {
	    int i;
		while (node < V) {
			for (i = 0; i < V; ++i) {
				g[i][node] = g[i][node + 1];
			}
			for (i = 0; i < V; ++i) {
				g[node][i] = g[node + 1][i];
			}
			node++;
		}

		V--;
	}
}



int TVS::TravellingSalesMan(int start_node)
{
	vector<int> nodes;
	int cost_of_shortest_path = 9999999;
	int cost_at_particular_node;
	
	for (int i = 0; i < V; i++) {
		if (i != start_node) {
			nodes.push_back(i);
		}
	}

	// calculate cost for all possible path and finally select the path that has minimum cost
	while(next_permutation(nodes.begin(), nodes.end())) {
		int cost_of_current_path = 0;
		int initial_node = start_node;
		for (int i = 0; i < nodes.size(); i++) {
			cost_at_particular_node = g[initial_node][nodes[i]];
			cost_of_current_path = cost_of_current_path + cost_at_particular_node;
			initial_node = nodes[i];
		}
		cost_at_particular_node = g[initial_node][start_node];
		cost_of_current_path = cost_of_current_path + cost_at_particular_node;
		cost_of_shortest_path = min(cost_of_shortest_path, cost_of_current_path);
	}
		
	return cost_of_shortest_path;
}

// graph initialization
void TVS::init() {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			g[i][j] = -1;
		}
	}

}


void TVS::GiveInputToTheGraph() {
	int distance;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (i == j) {
				g[i][j] = 0; // distance of the same node 0
			}
			else if (i != j && g[i][j] == -1) {
				cout << "Distance between node " << i + 1 << " and " << j + 1 << ": ";
				cin >> distance;
				g[i][j] = distance; // consider undirected graph
				g[j][i] = distance; // consider undirected graph
			}
			else {
				continue;
			}
		}
	}
}


int main(){
	TVS tvs;
	int distance;
	int node;
	int choice;
	while (true) {
		cout << "\n----------------------------------------------------------------------" << endl;
		cout << "Press 1. Create a graph" << endl;
		cout << "Press 2. Remove a node from a graph" << endl;
		cout << "Press 3. Add a new node " << endl;
		cout << "Press 4. Calculate shortest path (using travelling salesman) " << endl;
		cout << "Press 5. Display the graph " << endl;
		cout << "Press 6. Exit the program " << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cin >> choice;

		if (choice == 1) {
			cout << "Number of node: ";
			cin >> V;
			num_of_nodes = V;
			tvs.init();
			cout << "Give distances from one node to another node " << endl;
			tvs.GiveInputToTheGraph();
		}

		else if (choice == 2) {
			if (V == -1) {
				cout << "There is no node in the graph. At first create a graph " << endl;

			}

			else {
				cout << "Remove node from the following " << endl;
				for (int i = 0; i < V; i++) {
					cout << "Node no: " << i + 1 << "\n";
				}
				int rmnode;
				cin >> rmnode;
				tvs.RemoveNodes(rmnode);
			}
	
		}

		else if (choice == 3) {
			if (V == -1) {
				cout << "You can not add new node. At first create graph " << endl;
			}

			else {
				tvs.AddNodes();
				for (int i = 0; i < V; i++) {
					cout << "Distance from " << V << " to " << i << endl;
					cin >> distance;
					tvs.AddEdges(V, i, distance);
				}

			}
		}

		else if (choice == 4) {
			int starting_node;
			cout << "What is the starting node from the following nodes " << endl;
			for (int i = 0; i < V; i++) {
				cout << "Node " << i + 1 << "\n";
			}
			cout << "Starting node: ";
			cin >> starting_node;
			cout << "--------------------------------------------------------------------------------------" << endl;;
			cout << "The cost of the shortest path is " << tvs.TravellingSalesMan(starting_node) << endl;
			cout << "--------------------------------------------------------------------------------------" << endl;;
		}

		else if (choice == 5) {
			if (V == -1) {
				cout << "The graph is empty. At first create a graph";
			}
			else {
				tvs.DisplayGraph();

			}
		}

		else if (choice == 6) {
			cout << "Exit the program" << endl;
			return 0;
		}


	}

	
	return 0;
}