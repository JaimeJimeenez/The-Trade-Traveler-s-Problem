#include "Graph.h"

#include <sstream>

Graph::Graph(int vertices) :
	vertices{ vertices },
	//Iniciliazamos el vector de vectores de punteros al valor maximo
	edges{ std::vector < std::vector<std::shared_ptr<int>> >(vertices, std::vector<std::shared_ptr<int>>(Graph::INFINITE)) }
{

}

Graph::~Graph()
{

}

void Graph::insert(int v, int w, int cost)
{
	if (v >= 1 && v <= Vertices() && w >= 1 && w <= Vertices()) edges.at(v - 1).at(w - 1) = std::make_shared<int>(cost);
}

int Graph::cost(int v, int w)
{
	return (v >= 1 && v <= Vertices() && w >= 1 && w <= Vertices()) ? *edges.at(v - 1).at(w - 1) : Graph::INFINITE;
}



std::shared_ptr<int> Graph::dijkstra()
{

}

Graph Graph::prim()
{

}

std::list<edgeGraph> Graph::travelingSalesmanNeighbour()
{

}

std::list<edgeGraph> Graph::travelingSalesmanPrim()
{

}

std::string Graph::printVector(std::string s)
{

}

std::string Graph::print(std::string s)
{

}

void Graph::MinimunEdgeCost(Graph, Set, Set, int&, int&)
{

}

std::string Graph::depth(int start)
{
	std::stringstream ss;

	std::vector<std::shared_ptr<bool>> visited(vertices, std::make_shared<bool>(false));

	ss << "\nDeth tour: \n";
	int newVertex{ start - 1 };
	do {
		ss << "\n" << depth(newVertex, visited);
		newVertex = notVisitedVertex(visited, vertices);
	} while (vertices != -1);

	ss << "\n";

	return ss.str();
}

int Graph::notVisitedVertex(const std::vector<std::shared_ptr<bool>>& visited, int vertices)
{

}

std::string Graph::depth(int vertex, std::vector<std::shared_ptr<bool>>& visited)
{
	std::stringstream ss;
	visited.at(vertex) = std::make_shared<bool>(true);

	ss << vertex + 1 << " ";
	for (int i{ 0 }; i < vertices; i++)
		if (*edges.at(vertex).at(i) != Graph::INFINITE && !visited.at(i)) ss << depth(i, visited);

	return ss.str();
}
