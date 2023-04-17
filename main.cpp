#include <iostream>
#include <queue>
#include "WeightedGraph.h"
#include "Vertex.h"

using namespace std;

int main() {
    WeightedGraph graph(5);
    Vertex *A = new Vertex("A");
    Vertex *B = new Vertex("B");
    Vertex *C = new Vertex("C");
    Vertex *D = new Vertex("D");
    Vertex *E = new Vertex("E");

    graph.addVertex(A);
    graph.addVertex(B);
    graph.addVertex(C);
    graph.addVertex(D);
    graph.addVertex(E);

    graph.addEdge(0, 2, 12);
    graph.addEdge(0, 3, 60);
    graph.addEdge(1, 0, 10);
    graph.addEdge(2, 1, 20);
    graph.addEdge(2, 3, 32);
    graph.addEdge(4, 0, 7);

    cout << "DFS: ";
    graph.DFS(E);
    cout << "Cost: " << graph.getDFSCost() << endl << endl;

    cout << "BFS: ";
    graph.BFS(E);
    cout << "Cost: " << graph.getBFSCost() << endl << endl;

    if (graph.pathExists(A, D)) {
        cout << "There is a path from A to D." << endl;
    } else {
        cout << "There is no path from A to D." << endl;
    }
    if (graph.pathExists(E, B)) {
        cout << "There is a path from E to B." << endl;
    } else {
        cout << "There is no path from E to B." << endl;
    }
    if (graph.pathExists(C, E)) {
        cout << "There is a path from C to E." << endl;
    } else {
        cout << "There is no path from C to E." << endl;
    }
    return 0;
}
