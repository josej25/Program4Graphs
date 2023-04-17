#include "WeightedGraph.h"
#include "Vertex.h"
#include <iostream>
#include <queue>

WeightedGraph::WeightedGraph(int size) {
    nmbVertices = 0;
    maxVertices = size;

    vertices.resize(size);
    marks.resize(size);
    int rows = size;
    int columns = size;
    edges.resize(rows, vector<int>(columns, 0));
}

void WeightedGraph::addVertex(Vertex *aVertex) {
    vertices[nmbVertices] = aVertex;
    for (int i = 0; i < maxVertices; i++) {
        edges[nmbVertices][i] = NULL_EDGE;
        edges[i][nmbVertices] = NULL_EDGE;
    }
    nmbVertices++;
}

void WeightedGraph::addEdge(int fromVertex, int toVertex, int weight) {
    int row;
    int column;
    row = indexIs(vertices[fromVertex]);
    column = indexIs(vertices[toVertex]);
    edges[row][column] = weight;
}

int WeightedGraph::indexIs(Vertex *aVertex) {
    int i = 0;
    while (i < nmbVertices) {
        if (vertices[i] == aVertex) {
            return i;
        }
        i++;
    }
    return -1;
}

void WeightedGraph::clearMarks() {
    for (int i = 0; i < maxVertices; i++) {
        marks[i] = false;
    }
}


void WeightedGraph::DFS(Vertex *aVertex) {
    clearMarks();
    dfsCost = 0;
    doDFS(aVertex);
}

void WeightedGraph::BFS(Vertex *aVertex) {
    clearMarks();
    bfsCost = 0;
    doBFS(aVertex);
}

void WeightedGraph::doDFS(Vertex *aVertex) {
    int ix, ix2;

    if (aVertex == NULL) return;

    cout << aVertex->title << " ";
    ix = indexIs(aVertex);
    marks[ix] = true;
    for (int i = 0; i < nmbVertices; i++) {
        ix2 = indexIs(vertices[i]);
        if (edges[ix][ix2] != NULL_EDGE) {
            if (!marks[i]) {
                int currentCost = edges[ix][ix2];
                dfsCost += currentCost;
                cout << "(" << currentCost << ") ";
                doDFS(vertices[i]);
            }
        }
    }
}

void WeightedGraph::doBFS(Vertex *aVertex) {
    if (aVertex == NULL) return;

    queue<Vertex *> que;
    bfsCost = 0;
    int ix, ix2;

    clearMarks();

    ix = indexIs(aVertex);
    marks[ix] = true;
    que.push(aVertex);

    while (!que.empty()) {
        aVertex = que.front();
        que.pop();
        cout << aVertex->title << " ";

        ix = indexIs(aVertex);
        for (int i = 0; i < nmbVertices; i++) {
            ix2 = indexIs(vertices[i]);
            if (edges[ix][ix2] != NULL_EDGE && !marks[i]) {
                int currentCost = edges[ix][ix2];
                bfsCost += currentCost;
                cout << "(" << currentCost << ") ";
                marks[i] = true;
                que.push(vertices[i]);
            }
        }
    }
}


int WeightedGraph::getDFSCost() {
    return dfsCost;
}

int WeightedGraph::getBFSCost() {
    return bfsCost;
}

void WeightedGraph::calculateCost(int &cost, int row, int col) {
    if (edges[row][col] != NULL_EDGE) {
            cost += edges[row][col];
    }
    }

bool WeightedGraph::pathExists(Vertex *source, Vertex *destination) {
    clearMarks();
    queue<Vertex *> que;
    int ix, ix2;
    ix = indexIs(source);
    marks[ix] = true;
    que.push(source);

while (!que.empty()) {
    Vertex *current = que.front();
    que.pop();

    if (current == destination) {
        return true;
    }

    ix = indexIs(current);
    for (int i = 0; i < nmbVertices; i++) {
        ix2 = indexIs(vertices[i]);
        if (edges[ix][ix2] != NULL_EDGE && !marks[i]) {
            marks[i] = true;
            que.push(vertices[i]);
        }
    }
}
return false;
}
