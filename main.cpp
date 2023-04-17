// Stephen Saffioti
// Program 4
// Due: 4/16/23

#include <iostream>
#include "Vertex.h"
#include "WeightedGraph.h"

using namespace std;

int main()
{
    WeightedGraph myGraph(5);
    Vertex* root;
    Vertex* pVertex;

    pVertex = new Vertex("A");
    myGraph.addVertex(pVertex);
    pVertex = new Vertex("B");
    myGraph.addVertex(pVertex);
    pVertex = new Vertex("C");
    myGraph.addVertex(pVertex);
    pVertex = new Vertex("D");
    myGraph.addVertex(pVertex);
    root = new Vertex("E");
    myGraph.addVertex(root);

    myGraph.addEdge(4, 0, 7);
    myGraph.addEdge(0, 3, 60);
    myGraph.addEdge(0, 2, 12);
    myGraph.addEdge(2, 3, 32);
    myGraph.addEdge(2, 1, 20);
    myGraph.addEdge(1, 0, 10);

    cout << "DFS: ";
    myGraph.DFS(root);
    cout << endl;

    cout << "BFS: ";
    myGraph.BFS(root);
    cout << endl;

    return 0;
}

