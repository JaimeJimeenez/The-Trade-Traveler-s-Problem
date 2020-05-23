#include "Graph.h"
#include <sstream>

Graph::Graph(int vertex)
{
	this->vertex = vertex;

	edge = new int* [vertex];

	for (int i{ 0 }; i < vertex; i++) edge[i] = new int[vertex];

	for (int i{ 0 }; i < vertex; i++) {
		for (int j{ 0 }; j < vertex; j++) edge[i][j] = Graph::INFINITE;
	}
}

Graph::Graph(int, std::vector<std::vector<int>>)
{
}

Graph::~Graph()
{
}

void Graph::insert(int firstVertex, int nextVertex, int cost)
{
	if (firstVertex >= 1 && firstVertex <= vertex && nextVertex >= 1 && nextVertex <= vertex) edge[firstVertex - 1][nextVertex - 1] = cost;
}

int Graph::costs(int firstVertex, int nextVertex)
{
	return (firstVertex >= 1 && firstVertex <= vertex && nextVertex >= 1 && nextVertex <= vertex) ? edge[firstVertex - 1][nextVertex - 1] : Graph::INFINITE;
}

int Graph::totalVertex()
{
	return vertex;
}

int* Graph::dijkstra(Graph)
{
	return nullptr;
}

Graph Graph::prim(Graph)
{
	
}

std::initializer_list<edgeGraph> Graph::travelingSalesmanNeighbour(Graph actualGraph, int actualVertex)
{
	
}

std::initializer_list<edgeGraph> Graph::travelingSalesmanPrim(Graph, int)
{
	return std::initializer_list<edgeGraph>();
}

std::string Graph::print(std::string s)
{
	std::stringstream ss;

	ss << "\n" << s << "\n";
	for (int i{ 0 }; i < vertex; i++) {
		ss << "\n[" << (i + 1) << "] ";
		for (int j{ 0 }; j < vertex; j++) {
			if (edge[i][j] == Graph::INFINITE) ss << " -- ";
			else {
				if (edge[i][j] < 10) ss << " " << edge[i][j] << " ";
				else ss << " " << edge[i][j] << " ";
			}
		}
	}
	ss << "\n";

	return ss.str();
}
