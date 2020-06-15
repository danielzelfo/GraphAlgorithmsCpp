#pragma once
#include "../Graph.h"
#include "../AdjacencyMatrixGraph.h"

//Floyd-Warshall transitive closure algorithm
void transitiveClosure(AdjacencyMatrixGraph& g) {
    for (Vertex<string>* k : g.getVertices())
        for (Vertex<string>* i : g.getVertices())
            // verify that edge (i,k) exists in the partial closure
            if (i != k && g.getEdge(i, k) != 0)
                for (Vertex<string>* j : g.getVertices())
                    // verify that edge (k,j) exists in the partial closure
                    if (i != j && j != k && g.getEdge(k, j) != 0)
                        // if (i,j) not yet included, add it to the closure
                        if (g.getEdge(i, j) == 0)
                            g.insertEdge(i, j, 1);
}