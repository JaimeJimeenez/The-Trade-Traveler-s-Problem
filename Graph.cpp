#include "Graph.h"

#include <sstream>

Graph::Graph(int vertices) :
	vertices{ vertices },
	//Iniciliazamos el vector de vectores de punteros al valor maximo
	edges{ std::vector < std::vector<int> >(vertices, std::vector<int>(Graph::INFINITE)) }
{

}

Graph::~Graph()
{

}

void Graph::insert(int v, int w, int cost)
{
	if (v >= 1 && v <= vertices && w >= 1 && w <= vertices) edges.at(v - 1).at(w - 1) = cost;
}

int Graph::costs(int v, int w)
{
	return (v >= 1 && v <= vertices && w >= 1 && w <= vertices) ? edges.at(v - 1).at(w - 1) : Graph::INFINITE;
}

edgeGraph Graph::MinimumEdgeCost(const Set& W, int v, int w)
{
	int minim{ Graph::INFINITE };
	for (int i{ 1 }; i <= vertices; i++) {
		if (W.isPart(i) && costs(i, v) < minim) {
			minim = costs(i, v);
			w = i;
		}
	}

	return edgeGraph (v, w, minim);
}

std::list<edgeGraph> Graph::travelingSalesmanNeighbour(int startVertex)
{
	Set V{ vertices };
	for (int i{ 1 }; i < vertices; i++)
		V.insert(i);

	Set T(vertices);
	T.insert(startVertex);

	Set W{ V.substract(T) };

	std::list <edgeGraph> tour;

	int u{ startVertex };

	do {
		for (int w{ 1 }; w < W.Size(); w++) 
			if (W.isPart(w) && T.isPart(u)) {
				tour.push_back(MinimumEdgeCost(W, u, w));
				T.insert(w);
				W.erase(w);
				u = w;
			}
	} while (!T.isEqual(V));
	
	return tour;
}

std::list<edgeGraph> Graph::travelingSalesmanPrim(int startVertex)
{
	Set V{ vertices };
	for (int i{ 1 }; i < vertices; i++)
		V.insert(i);

	Set T(vertices);
	T.insert(startVertex);

	Set W{ V.substract(T) };

	std::list <edgeGraph> tour;

	std::vector<std::vector<int>> d(vertices, std::vector<int>(vertices, 0));
	
	int u{ startVertex };

	do{
		for (int w{ 1 }; w < W.Size(); w++) {
			if(W.isPart(w) && T.isPart(u) && edges.at(w).at(u) < 2) {
				d.at(w).at(u)++;
				tour.push_back(MinimumEdgeCost(W, u, w));
				T.insert(w);
				W.erase(w);
			}
		}
	} while (!T.isEqual(V));

	return tour;
}

std::string Graph::printVector(const std::string& s)
{
	return s;
}

std::string Graph::print(const std::string& s)
{
	std::stringstream ss;

	std::cout << s;

	return s;
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
	return 0;
}

std::string Graph::depth(int vertex, std::vector<std::shared_ptr<bool>>& visited)
{
	std::stringstream ss;
	visited.at(vertex) = std::make_shared<bool>(true);

	ss << vertex + 1 << " ";
	for (int i{ 0 }; i < vertices; i++)
		if (edges.at(vertex).at(i) != Graph::INFINITE && !visited.at(i)) ss << depth(i, visited);

	return ss.str();
}
