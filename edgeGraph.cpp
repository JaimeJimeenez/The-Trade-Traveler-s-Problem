#include "edgeGraph.h"

edgeGraph::edgeGraph(int firstVertex, int nextVertex, int costs)
{
	this->firstVertex = firstVertex;
	this->nextVertex = nextVertex;
	this->costs = costs;
}
