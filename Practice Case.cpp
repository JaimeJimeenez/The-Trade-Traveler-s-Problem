#include <iostream>

#include "Graph.h"
#include "Set.h"
#include "edgeGraph.h"

std::vector <std::vector <int>> writeVertices() {
	std::vector <std::vector <int>> returnVector(20, std::vector<int>(20, 0));
	int imputCost;
	for (int i{ 0 }; i < 20; i++) {
		for (int j{ 0 }; j < 20; j++) {
			std::cout << "Cost: ";
			std::cin >> imputCost;
			returnVector.at(i).at(j) = imputCost;
		}
	}
	return returnVector;
};

int main() {

	std::vector <std::vector <int>> costsEdges = writeVertices();
	Graph newGraph(20, costsEdges);


	return 0;
}
