#pragma once
#include <iostream>
#include <vector>

#include "edgeGraph.h"
#include "Set.h"

class Graph
{
public:

	Graph(int);
	Graph(int, std::vector<std::vector<int>>);
	~Graph();

	void insert(int, int, int);

	int costs(int, int);
	int totalVertex();

	static int* dijkstra(Graph);
	static Graph prim(Graph);
	static std::initializer_list<edgeGraph> travelingSalesmanNeighbour(Graph, int);
	static std::initializer_list<edgeGraph> travelingSalesmanPrim(Graph, int);
	static std::string printVector(std::string, int*, int);

	std::string print(std::string);
	std::string depth(int);

private:

	static const int INFINITE = std::numeric_limits<unsigned short int>::max();

	int vertex;
	int** edge;
	int notVisitedVertex(bool*, int);

	static void MinimunEdgeCost(Graph, Set, Set, int&, int&);
	
	std::string depth(int, bool*&);
};

