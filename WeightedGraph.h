#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <vector>
#include "Vertex.h"

using namespace std;

class WeightedGraph
{
public:
    WeightedGraph(int size);
    void addVertex(Vertex* aVertex);
    void addEdge(int fromVertex, int toVertex, int weight);
    int indexIs(Vertex* aVertex);
    void clearMarks();
    void doDFS(Vertex* aVertex);
    void DFS(Vertex* aVertex);
    void doBFS(Vertex* aVertex);
    void BFS(Vertex* aVertex);
    void checkPath(Vertex source, Vertex destination);

private:
    static const int NULL_EDGE = 0;
    int nmbVertices;
    int maxVertices;
    vector<Vertex*> vertices;
    vector<bool> marks;
    vector<vector<int>> edges;

};

#endif
