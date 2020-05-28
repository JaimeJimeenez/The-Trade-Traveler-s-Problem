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

Graph Graph::prim(Graph G)
{
	//Se inicializa V con todos los vertices de G
	Set V(G.Vertices());
	for (int i{ 1 }; i <= G.Vertices(); i++) {
		V.insert(i);
	}

	//Se inicializa U con el vertice inicial (1)
	Set U(1);
	U.insert(1);

	//Se inicializa W con los elementos no iguales de V y U
	Set W(G.Vertices());
	W = V.substract(U);

	Graph T(G.Vertices());

	while (!U.isEqual(V)) {
		int i{ 1 };
		int j{ 1 };
		for (i; i < U.Size(); i++) {
			for (j; j < V.Size(); j++) {
				MinimunEdgeCost(G, U, V, i, j);
			}
		}
		U.add(i);
		V.erase(j);
	}
}

std::list<edgeGraph> Graph::travelingSalesmanNeighbour()
{

}

std::list<edgeGraph> Graph::travelingSalesmanPrim()
{

}

std::string Graph::printVector(std::string s)
{
	std::stringstream ss;

	std::cout << s;


}

std::string Graph::print(std::string s)
{
	std::stringstream ss;

	std::cout << s;
}

void Graph::MinimunEdgeCost(Graph G, Set U, Set W, int& u, int& w)
{
	if (W.isPart(w) && U.isPart(u)) {
		G.cost(u, w);
	}
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
