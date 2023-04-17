#include "WeightedGraph.h"
#include "Vertex.h"
#include <vector>
#include <iostream>
#include <queue>


WeightedGraph::WeightedGraph(int size)
{
    nmbVertices = 0;
    maxVertices = size;

    vertices.resize(size);
    marks.resize(size);

    int rows = size;
    int columns = size;
    edges.resize(rows, vector<int>(columns, 0));
}

void WeightedGraph::addVertex (Vertex* aVertex)
{
    vertices[nmbVertices] = aVertex;
    for (int i=0; i<maxVertices; i++) {
        edges[nmbVertices][i] = NULL_EDGE;
        edges[i][nmbVertices] = NULL_EDGE;
    }
    nmbVertices++;
}

void WeightedGraph::addEdge(int fromVertex, int toVertex, int weight)
{
    int row;
    int column;
    row = indexIs(vertices[fromVertex]);
    column = indexIs(vertices[toVertex]);
    edges[row][column] = weight;
}

int WeightedGraph::indexIs(Vertex* aVertex)
{
    int i = 0;
    while (i<nmbVertices) {
        if (vertices[i] == aVertex) {
            return i;
        }
        i++;
    }
    return -1;
}

void WeightedGraph::clearMarks()
{
    for (int i=0; i< maxVertices; i++) {
        marks[i] = false;
    }
}

void WeightedGraph::doDFS(Vertex* aVertex)
{
    int index = indexIs(aVertex);
    if (index == -1) {
        return;
    }
    marks[index] = true;
    cout << aVertex->title << " ";
    for (int i = 0; i < maxVertices; i++) {
        if (edges[index][i] != NULL_EDGE && !marks[i]) {
            doDFS(vertices[i]);
        }
    }
}


void WeightedGraph::DFS(Vertex* aVertex)
{
    clearMarks();
    doDFS(aVertex);
}

void WeightedGraph::doBFS(Vertex* aVertex)
{
    queue<Vertex*> q;
    int row = indexIs(aVertex);
    marks[row] = true;
    q.push(aVertex);

    while (!q.empty()) {
        Vertex* v = q.front();
        q.pop();
        cout << v->getTitle() << " ";

        int row = indexIs(v);
        for (int i = 0; i < maxVertices; i++) {
            if (edges[row][i] != NULL_EDGE) {
                Vertex* w = vertices[i];
                if (!marks[i]) {
                    marks[i] = true;
                    q.push(w);
                }
            }
        }
    }
}



void WeightedGraph::BFS(Vertex* aVertex)
{
    clearMarks();
    doBFS(aVertex);
}


