#pragma once
#include <iostream>
#include "DFS.h"
#include "Graph.h"
#include "Decorator.h"

using namespace std;

class TopologicalOrdering : public DFS {
	int n;
	
public:

	void startVisit(Vertex<string>* v) {
		if (!isVisited(v)) {
			bool g = true;
			vector<Edge<int>*> inc = graph->incomingEdges(v);
			for (int i = 0; i < inc.size(); ++i)
				if (!isVisited(graph->opposite(v, inc[i]))) {
					dfsTraversal(graph->opposite(v, inc[i]));
					g = false;
				}

			if(g)
				cout << v->getElement() << " ";
		}
			
		
	}

	bool isDone() {
		return n >= graph->getVertices().size();
	}


    TopologicalOrdering(Graph<string, int>* g) : DFS(g) { }
};