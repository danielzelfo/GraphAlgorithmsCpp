#pragma once
#include <iostream>
#include "DFS.h"
#include "Graph.h"
#include "Decorator.h"

using namespace std;

class TopologicalOrdering : public DFS {


	void startVisit(Vertex<string>* v) {
		if (!isVisited(v))
			cout << v->getElement() << " ";
	}

	void traverseDiscovery(Edge<int>* e, Vertex<string>* from) {
		vector<Edge<int>*> inc = graph->incomingEdges(graph->opposite(from, e));
		for (int i = 0; i < inc.size(); ++i)
			if (!isVisited(graph->opposite(graph->opposite(from, e), inc[i]))){
				dfsTraversal(graph->opposite(graph->opposite(from, e), inc[i]));
				return;
			}
			
	}
	void finishVisit(Vertex<string>* v) {
		visit(v);
	}


public:
    TopologicalOrdering(Graph<string, int>* g) : DFS(g) { }
};