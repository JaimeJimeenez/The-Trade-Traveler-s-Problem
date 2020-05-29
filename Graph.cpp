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
	//Se inicializa la variable minimo como una variable que posee un elemento nulo
	int minim{ Graph::INFINITE };
	//Se recorre cada elemento de los vertices mediante un for
	for (int i{ 1 }; i <= vertices; i++) {
		//Se buscará el coste minimo de los vertices tal que el iterador i pertenzca al conjunto W i el coste aportado por dicha arista sea menor que el actual
		if (W.isPart(i) && costs(i, v) < minim) {
			//Se modifica el valor del coste minimo
			minim = costs(i, v);
			w = i;
		}
	}
	//Se devuelve la arista de dos vertices con coste minimo
	return edgeGraph(v, w, minim);
}


std::list<edgeGraph> Graph::travelingSalesmanNeighbour(int startVertex)
{
	//Se inicializa el conjunto V con todos los vertices del grafo
	Set V{ vertices };
	for (int i{ 1 }; i < vertices; i++)
		V.insert(i);

	//Se inicializa el conjunto T con el vertice de partida (startVertex)
	Set T(vertices);
	T.insert(startVertex);

	//Se incializa el conjunto W con todos los vertices no seleccionados
	Set W{ V.substract(T) };

	//Se crea una lista de aristas llamada tour
	std::list <edgeGraph> tour;

	int u{ startVertex };

	//Mientras que los conjuntos T y V no posean los mismos elementos
	do {
		//Se busca la arista de coste minimo
		for (int w{ 1 }; w < W.Size(); w++)
			if (W.isPart(w) && T.isPart(u)) {
				//Añade dicha arista a través de la función MinimumEdgeCost
				tour.push_back(MinimumEdgeCost(W, u, w));
				//Se inserta el vertice escogido en el conjunto T
				T.insert(w);
				//Se elimina el vertice escogido del conjunto W
				W.erase(w);
				//Se traspasa el vertice u al vertice w, es decir, el vertice actual es el w
				u = w;
			}
	} while (!T.isEqual(V));

	//Se devuelve la lista de aristas tour
	return tour;
}

std::list<edgeGraph> Graph::travelingSalesmanPrim(int startVertex)
{
	//Se inicializa el conjunto V con todos los vertices del grafo
	Set V{ vertices };
	for (int i{ 1 }; i < vertices; i++)
		V.insert(i);
	
	//Se inicializa el conjunto T con el vertice de partida (startVertex)
	Set T(vertices);
	T.insert(startVertex);

	//Se inicializa el conjunto W con todos los vertices no seleccionados
	Set W{ V.substract(T) };

	//Se crea una lista de aristas llamada tour
	std::list <edgeGraph> tour;

	//Se crea un vector que almacena el grado de los vertices, este vector estará inicializado a 0
	std::vector<std::vector<int>> d(vertices, std::vector<int>(vertices, 0));

	int u{ startVertex };

	//Mientras que los conjuntos T y V no posean los mismos elementos
	do {
		for (int w{ 1 }; w < W.Size(); w++) {
			if (W.isPart(w) && T.isPart(u) && edges.at(w).at(u) < 2) {
				//Incrementa el grados de los vertices u y w
				d.at(w).at(u)++;
				//Añade la arista a la lista de aristas (tour)
				tour.push_back(MinimumEdgeCost(W, u, w));
				//Se añade el vertice w al conjunto T
				T.insert(w);
				//Se elimina dicho vertice del conjunto de W
				W.erase(w);
			}
		}
	} while (!T.isEqual(V));

	//Se devuelve la lista de aristas tour
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
