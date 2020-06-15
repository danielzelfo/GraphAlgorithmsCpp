#pragma once
#include "../Decorator.h"
#include "../Graph.h"

using namespace std;

// Created by T. Vo for CSCI 230
// Based on C++ code fragment of Goodrich book 

// Make sure that Vertex<string> and Edge<int> is-a Decorator

class DFS {										// generic DFS
protected: 										// member data
	Graph<string, int> *graph;								// the graph
	Vertex<string> *start;								// start vertex
	Object *yes, *no;							// decorator values

public:											// member functions
	DFS(Graph<string, int>*g);								// constructor
	void initialize();							// initialize a new DFS
	void dfsTraversal(Vertex<string> *v);				// recursive DFS utility
												// overridden functions
	virtual void startVisit(Vertex<string> *v) {}		// arrived at v
												// discovery edge e
	virtual void traverseDiscovery(Edge<int>* e, Vertex<string>* from) {}
	// back edge e
	virtual void traverseBack(Edge<int> *e, Vertex<string> *from) {}
	virtual void finishVisit(Vertex<string> *v) {}			// finished with v
	virtual bool isDone() const { return false; }	// finished?
													
	void visit(Vertex<string> *v) { v->set("visited", yes); }
	void visit(Edge<int> *e) { e->set("visited", yes); }
	void unvisit(Vertex<string> *v) { v->set("visited", no); }
	void unvisit(Edge<int> *e) { e->set("visited", no); }
	bool isVisited(Vertex<string> *v) { return v->get("visited") == yes; }
	bool isVisited(Edge<int> *e) { return e->get("visited") == yes; }
};

DFS::DFS(Graph<string, int>*g) : graph(g), yes(new Object), no(new Object) {}

void DFS::initialize() {
	list<Vertex<string> *> verts = graph->getVertices();
	for (auto pv = verts.begin(); pv != verts.end(); ++pv)
		unvisit(*pv);							// mark vertices unvisited

	list<Edge<int> *> edges = graph->getEdges();
	for (auto pe = edges.begin(); pe != edges.end(); ++pe)
		unvisit(*pe);							// mark edges unvisited
}

void DFS::dfsTraversal(Vertex<string> *v) {
	startVisit(v);  visit(v);					// visit v and mark visited
	vector<Edge<int> *> incident = graph->outgoingEdges(v);
	auto pe = incident.begin();
	while (!isDone() && pe != incident.end()) {	// visit v's incident edges
		Edge<int> *e = *pe++;
		if (!isVisited(e)) {					// discovery edge?
			visit(e);							// mark it visited

			Vertex<string> *w = graph->opposite(v, e);	// get opposing vertex


			//cout << "Visited " << v->getElement() << " - " << e->getElement() << " - " << w->getElement() << endl;

			if (!isVisited(w)) {				// unexplored?
				traverseDiscovery(e, v);		// let's discover it
				if (!isDone()) dfsTraversal(w);	// continue traversal
			}
			else traverseBack(e, v);			// process back edge
		}
	}
	if (!isDone()) finishVisit(v);				// finished with v
}
