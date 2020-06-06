#pragma once

#include <iostream>
#include "DFS.h"

using namespace std;

class DFS1 : public DFS {
	void traverseDiscovery(Edge<int>* e, Vertex<string>* from) {
		cout << from->getElement() << " " << e->getElement() << " " << graph->opposite(from, e)->getElement() << endl;
	}
	

public:

	DFS1(Graph<string, int>* g) : DFS(g) { }
};