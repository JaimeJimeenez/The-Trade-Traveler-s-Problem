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
	int costs(int v, int w);


	std::list<edgeGraph> travelingSalesmanNeighbour(int startVertex);
	std::list<edgeGraph> travelingSalesmanPrim(int startVertex);
	std::string printVector(const std::string& s);
	std::string print(const std::string& s);
	std::string depth(int start);

	int Vertices() const { return vertices; }

private:

	static const int INFINITE = std::numeric_limits<unsigned short int>::max();

	int vertices;
	std::vector<std::vector<int>> edges; //Quitado std::shared_ptr
	int notVisitedVertex(const std::vector<std::shared_ptr<bool>>& visited , int vertices);
	std::string depth(int vertex, std::vector<std::shared_ptr<bool>>& visited);
	edgeGraph MinimumEdgeCost(const Set& W, int v, int w);

};

