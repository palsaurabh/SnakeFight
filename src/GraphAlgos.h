#ifndef GRAPHALGOS_H
#define GRAPHALGOS_H

#include <iostream>
#include <vector>
#include <map>

class Graph
{
public:
    Graph();
    Graph(std::string fileName);
    void printGraph();
    /*DFS returns a list of connected vertices (one component) in the graph*/
    std::vector<int> DFS(int startVertex);
private:
    int numNodes;
    int numEdges;
    bool weighted;
    bool directed;
    std::vector<std::vector<int>> edgeList;
    std::vector<int> weightList;
    std::vector<int> nodeList;
    std::map<int, std::vector<int>> adjacencyList;
    std::vector<std::vector<bool>> adjacencyMatrix;
    /*
    readGraph() takes in the fileName and extracts all the Nodes in the file
    File format is as follows:

    N (Num Nodes), E (Num Edges), W (weighted/non-weighted)
    n1 n2 n3 n4 ... nn  (list of vertices)
    u, v, w     (edge 1)
    u1, v1, w1  (edge 2)
    u2, v2, w2  (edge 3)
    ....
    un, vn, wn  (edge n)

    D (Directional/non-directional)
    E.g. for 10 Nodes, 10 Edges, Non-weighted, Non-directional 
    10 10 0
    1 2 3 4 5 6 7 8 9 10
    1 3
    3 5
    5 1
    1 6
    6 2
    5 6
    2 5
    7 10
    4 7
    10 9
    0 
    */
    int readGraph(const std::string fileName);
    int populateAdjacencyMatrix();
    int populateAdjacencyList();
};

#endif /*GRAPHALGOS_H*/