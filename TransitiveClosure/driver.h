/*  Program: Floyd-Warshall Transitive Closure Program
 *	Author: Daniel Zelfo
 *	Class: CSCI 230
 *	Date: 5/19/2020
 *	Description: This program includes the Floyd-Warshall transitive closure algorithm.
 *               The transitiveClosure function will alter the graph passed as a parameter to the transitive closure of itself by inserting edges.
 *
 * I certify that the code below is my own work.
 *
 *	Exception(s): N/A
 *
 */

#include <iostream>
#include "../AdjacencyMatrixGraph.h"
#include "TransitiveClosure.h"



void transitiveClosureMain()
{
    //setting up the graph
    AdjacencyMatrixGraph g;

    Vertex<string>* a = g.insertVertex("A");
    Vertex<string>* b = g.insertVertex("B");
    Vertex<string>* c = g.insertVertex("C");
    Vertex<string>* d = g.insertVertex("D");
    Vertex<string>* e = g.insertVertex("E");

    g.insertEdge(b, a, 1);
    g.insertEdge(b, c, 1);
    g.insertEdge(a, e, 1);
    g.insertEdge(a, d, 1);
    g.insertEdge(c, d, 1);
    g.insertEdge(e, c, 1);
    g.insertEdge(d, e, 1);


    //ouputting the original matrix representation of the graph
    cout << "Original matrix: " << endl;
    g.printMatrix();

    //running the transitiveClosure function on the graph
    cout << "\nChanging the graph to the transitive closure of itself...\n\n";
    transitiveClosure(g);

    //ouputting the resulting matrix representation of the graph
    cout << "Updated matrix: " << endl;
    g.printMatrix();

}
