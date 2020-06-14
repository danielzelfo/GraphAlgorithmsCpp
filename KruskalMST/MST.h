#pragma once
#include <list>
#include <queue>
#include <map>

#include "Graph.h"
#include "AdjacencyListGraph.h"
#include "disjoint_sets.h"


struct CompareEdge {
    bool operator()(Edge<int>* const& e1, Edge<int>* const& e2) {
        return e1->getElement() > e2->getElement();
    }
};


list<Edge<int>*> MST(AdjacencyListGraph<string, int> g) {
    // tree is where we will store result as it is computed
    list<Edge<int>*> tree;
    // pq entries are edges of graph, with weights as keys
    priority_queue<Edge<int>*, vector<Edge<int>*>, CompareEdge> pq;
    // union-find forest of components of the graph
    UnionFind<Vertex<string>*> forest;
    
    for (Vertex<string>* v : g.getVertices())
        forest.makeSet(v);

    for (Edge<int>* e : g.getEdges())
        pq.push(e);

    int size = g.numVertices();
    // while tree not spanning and unprocessed edges remain...
    while (tree.size() != size - 1 && !pq.empty()) {
        //minimum edge in priorityQueue
        Edge<int>* edge = pq.top();
        //two sets that include the two endpoint elements of the current edge
        UnionFind<Vertex<string>*>::Iterator a = forest._find(g.endVertices(edge)[0]), b = forest._find(g.endVertices(edge)[1]);

        pq.pop();

        //making sure they are two different sets
        if(a!=b){
                //adding the edge to the tree and joining the two sets
                tree.push_back(edge);
                forest._union(a, b);
        }
        
    }

    return tree;
}