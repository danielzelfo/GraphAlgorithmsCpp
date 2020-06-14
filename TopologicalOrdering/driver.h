/*  Program: Depth First Search
 *	Author: Daniel Zelfo
 *	Class: CSCI 230
 *	Date: 5/11/2020
 *	Description: This program includes the TopologicalOrdering class, which can be used to output the topological ordering of a directed graph
 *               The TopologicalOrdering class inherits from the DFS class.
 *
 *
 * I certify that the code below is my own work.
 *
 *	Exception(s): N/A
 *
 */


#include <iostream>
#include "AdjacencyListGraph.h"
#include "TopologicalOrdering.h"

void topologicalOrderingMain()
{
	//building the DAG
	AdjacencyListGraph<string, int>* ag = new AdjacencyListGraph<string, int>(true);
	Vertex<string>* a = ag->insertVertex("A");
	Vertex<string>* b = ag->insertVertex("B");
	Vertex<string>* c = ag->insertVertex("C");
	Vertex<string>* d = ag->insertVertex("D");
	Vertex<string>* e = ag->insertVertex("E");

	Edge<int>* ba = ag->insertEdge(b, a, 1);
	Edge<int>* bc = ag->insertEdge(b, c, 1);
	Edge<int>* ad = ag->insertEdge(a, d, 1);
	Edge<int>* cd = ag->insertEdge(c, d, 1);
	Edge<int>* de = ag->insertEdge(d, e, 1);


	/*
		 A
	  /->   \->
	B		  D -> E
	  \->   /->
		 C
	
	*/

	//outputting the traversal
	TopologicalOrdering to(ag);


	cout << "Topological Ordering:\n  ";
	to.dfsTraversal(b);
}
