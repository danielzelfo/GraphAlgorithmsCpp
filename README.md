# GraphAlgorithmsCpp
A Collection of Graph Algorithms in C++

[![Run on Repl.it](https://repl.it/badge/github/danielzelfo/GraphAlgorithmsCpp)](https://repl.it/github/danielzelfo/GraphAlgorithmsCpp)

## KruskalMST
Kruskal’s Minimum Spanning Tree Algorithm in C++

This program includes the *MST* function, which returns a list of edges that make up a minimum spanning tree of a given graph. The *MST* function uses Kruskal's algorithm. The *MST* function uses the disjoint sets and priority queue data structures.


## TopologicalOrdering
C++ Topological Ordering Algorithm

This program includes the *TopologicalOrdering* class, which can be used to output the topological ordering of a directed graph. The *TopologicalOrdering* class inherits from the *DFS* class.


## DijkstraShortestPath
Dijkstra's Shortest Path Algorithm in C++

This program includes Dijkstra's algorithm for the shortest path in a directed graph. The *shortestPathLengths* function takes a graph and a starting vertex as parameters. It returns a map with each vertex and the shortest path to it. 
The map also has the length of the shortest path and a vector of vertices representing the shortest path from the start vertex to all the vertices.


## TransitiveClosure
C++ Floyd Warshall Transitive Closure Algorithm

This program includes the Floyd-Warshall transitive closure algorithm. The *transitiveClosure* function will alter the graph passed as a parameter to the transitive closure of itself by inserting edges.


## DFS
C++ Depth First Search Algorithm

This program includes the *DFS* class, which can be used to traverse a graph. The driver tests the *DFS* class using an *AdjacencyListGraph*. The *DFS* class uses decorators to see if a vertex or edge has been visited. For that reason, the *Vertex* and *Edge* classes in the Graph.h file need to inherit from the *Decorator* class.