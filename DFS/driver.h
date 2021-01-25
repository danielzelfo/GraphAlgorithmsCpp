/*  Program: Depth First Search
 *	Author: Daniel Zelfo
 *	Class: CSCI 230
 *	Date: 5/11/2020
 *	Description: This program includes the DFS class, which can be used to traverse a graph. The driver tests the DFS class using an AdjacencyListGraph.
 *               The DFS class uses decorators to see if a vertex or edge has been visited. For that reason, the Vertex and Edge classes in the Graph.h file need to inherit from the Decorator class.
 *
 *
 * I certify that the code below is my own work.
 *
 *	Exception(s): N/A
 *
 */

#include <iostream>
#include "DFS1.h"
#include "../AdjacencyListGraph.h"

void dfsMain()
{
	//creating the graph
	AdjacencyListGraph<string, int>* ag = new AdjacencyListGraph<string, int>();
	Vertex<string>* a = ag->insertVertex("A");
	Vertex<string>* b = ag->insertVertex("B");
	Vertex<string>* c = ag->insertVertex("C");
	Vertex<string>* d = ag->insertVertex("D");
	Vertex<string>* e = ag->insertVertex("E");

	Edge<int>* ab = ag->insertEdge(a, b, 1);
	Edge<int>* ad = ag->insertEdge(a, d, 1);
	Edge<int>* bc = ag->insertEdge(b, c, 1);
	Edge<int>* cd = ag->insertEdge(c, d, 1);
	Edge<int>* de = ag->insertEdge(d, e, 1);

	//depth first search on the graph starting at vertex A
	DFS1 dfs(ag);
	dfs.initialize();
	dfs.dfsTraversal(a);
}
