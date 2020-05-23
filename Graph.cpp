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

int* Graph::dijkstra(Graph actualGraph)
{
	Set V(actualGraph.totalVertex());

	for (int i{ 0 }; i < actualGraph.totalVertex(); i++) V.inserts(i);
	
}

Graph Graph::prim(Graph actualGraph)
{
	
}

std::initializer_list<edgeGraph> Graph::travelingSalesmanNeighbour(Graph actualGraph, int actualVertex)
{
	
}

std::initializer_list<edgeGraph> Graph::travelingSalesmanPrim(Graph, int)
{
	return std::initializer_list<edgeGraph>();
}

std::string Graph::printVector(std::string, int*, int)
{
	return std::string();
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

std::string Graph::depth(int start)
{
	std::stringstream ss;
	bool* visited = new bool[vertex];

	for (int i{ 0 }; i < vertex; i++) visited[i] = false;

	ss << "\nDepth tour \n";

	int newVertex = start - 1;

	do {
		ss << "\n" << depth(newVertex, visited);
		newVertex = notVisitedVertex(visited, vertex);
	} while (vertex != -1);

	ss << "\n";

	return ss.str();
}

int Graph::notVisitedVertex(bool* visited, int vertex)
{
	for (int i{ 0 }; i < totalVertex(); i++) {
		if (edge[vertex] == edge[i]) return vertex;
	}
	return -1;
}

void Graph::MinimunEdgeCost(Graph, Set, Set, int&, int&)
{
}

std::string Graph::depth(int vertex, bool*& visited)
{
	std::stringstream ss;

	visited[vertex] = true;

	ss << vertex + 1 << " ";
	
	for (int i{ 0 }; i < vertex; i++) {
		if (edge[vertex][i] != Graph::INFINITE && !visited[i]) ss << depth(i, visited);
	}

	return ss.str();
}
