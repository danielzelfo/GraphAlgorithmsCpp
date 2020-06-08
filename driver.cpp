/*  Program: Dijkstra's Shortest Path Algorithm v1.1 (EXTRA CREDIT)
 *	Author: Daniel Zelfo
 *	Class: CSCI 230
 *	Date: 5/19/2020
 *	Description: This program includes Dijkstra's algorithm for the shortest path in a directed graph
 *               The shortestPathLengths function takes a graph and a starting vertex as parameters. It returns a map with each vertex and the shorted path to it.
 *               v1.1: The map now has the length of the shortest path and a vector of vertices representing the shortest path from the start vertex to all the vertices
 *
 * I certify that the code below is my own work.
 *
 *	Exception(s): N/A
 *
 */


#include <iostream>
#include "Graph.h"
#include "AdjacencyListGraph.h"
#include "DijkstraShortestPath.h"




int main()
{

    cout << "Dijkstra's Shortest Path Algorithm\n\n";
    //setting up the graph
    AdjacencyListGraph<string, int> g;

    Vertex<string>* a = g.insertVertex("A");
    Vertex<string>* b = g.insertVertex("B");
    Vertex<string>* c = g.insertVertex("C");
    Vertex<string>* d = g.insertVertex("D");
    Vertex<string>* e = g.insertVertex("E");
    g.insertEdge(b, a, 3);
    g.insertEdge(b, c, 4);
    g.insertEdge(a, e, 10);
    g.insertEdge(a, d, 5);
    g.insertEdge(c, d, 2);
    g.insertEdge(e, c, 6);
    g.insertEdge(d, e, 3);


    //outputting the shorted path length from vertex b to vertex e
    cout << "shortest path length from B to E: " << shortestPathLengths(g, b)[e].first << endl;

    //outputting the shorted path from vertex b to vertex e
    cout << "shortest path length from B to E: ";
    vector< Vertex<string>* > direction = shortestPathLengths(g, b)[e].second;
    for (int i = 0; i < direction.size(); i++)
        cout << direction[i]->getElement() << (i != direction.size() - 1 ? "->" : "\n");

}
