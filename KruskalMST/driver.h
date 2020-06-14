
/*  Program: Minimum Spanning Tree
 *	Author: Daniel Zelfo
 *	Class: CSCI 230
 *	Date: 6/2/2020
 *	Description: This program includes the MST function, which returns a list of edges that make up a minimum spanning tree of a given graph
 *               The MST function uses Kruskal's algorithm. The MST function uses the disjoint sets and priority queue data structures.
 *
 * I certify that the code below is my own work.
 *
 *	Exception(s): N/A
 *
 */

#include <iostream>
#include "Graph.h"
#include "AdjacencyListGraph.h"
#include "MST.h"

int main()
{
    //the graph
    AdjacencyListGraph<string, int> g;

    Vertex<string>* a = g.insertVertex("A");
    Vertex<string>* b = g.insertVertex("B");
    Vertex<string>* c = g.insertVertex("C");
    Vertex<string>* d = g.insertVertex("D");
    Vertex<string>* e = g.insertVertex("E");

    g.insertEdge(a, b, 3);
    g.insertEdge(a, d, 5);
    g.insertEdge(a, e, 5);
    g.insertEdge(b, c, 4);
    g.insertEdge(c, d, 2);
    g.insertEdge(d, e, 5);
    g.insertEdge(c, e, 3);


    //outputting the minimum spanning tree and its total cost
    int totalCost = 0;
    list<Edge<int>*> l = MST(g);
    cout << "Minimum Spanning tree: " << endl;
    for (Edge<int>* e : l){
        totalCost += e->getElement();
        cout << g.endVertices(e)[0]->getElement() << "-" << e->getElement() << "-" << g.endVertices(e)[1]->getElement() << " ";
    }
    cout << "\nTotal cost: " << totalCost << endl;
}
