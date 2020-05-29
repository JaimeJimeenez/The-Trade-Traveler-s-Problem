#pragma once

class edgeGraph
{
public:

	edgeGraph(int firstVertex, int nextVertex, int costs);
	int firstVertex;
	int nextVertex;
	int costs;
};

