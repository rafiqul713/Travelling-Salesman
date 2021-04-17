#pragma once

class TVS {
public:

	void DisplayGraph();
	void AddNodes();
	void AddEdges(int i, int j, int distance);
	void RemoveNodes(int node);
	int TravellingSalesMan(int start_node);
	void GiveInputToTheGraph();
	void init();
};