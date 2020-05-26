#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <list>

#include "edgeGraph.h"
#include "Set.h"

class Graph
{
public:

	Graph(int vertices);
	~Graph();

	void insert(int v, int w, int cost);
	int cost(int v, int w);

	std::shared_ptr<int> dijkstra();
	Graph prim();
	std::list<edgeGraph> travelingSalesmanNeighbour();
	std::list<edgeGraph> travelingSalesmanPrim();
	std::string printVector(std::string s);

	std::string print(std::string s);
	std::string depth(int start);

	int Vertices() const { return vertices; }

private:

	static const int INFINITE = std::numeric_limits<unsigned short int>::max();

	int vertices;
	std::vector<std::vector<std::shared_ptr<int>>> edges;
	int notVisitedVertex(const std::vector<std::shared_ptr<bool>>& visited , int vertices);
	std::string depth(int vertex, std::vector<std::shared_ptr<bool>>& visited);
	static void MinimunEdgeCost(Graph, Set, Set, int&, int&);
	
	
};

