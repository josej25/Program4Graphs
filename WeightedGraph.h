#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <vector>
#include "Vertex.h"


class WeightedGraph
{
    public:
        WeightedGraph(int);
        void addVertex(Vertex* aVertex);
        void addEdge(int fromVertex, int toVertex, int weight);
       // bool isFull();
        void doDFS(Vertex* aVertex);
        void doBFS(Vertex* aVertex);
        void DFS(Vertex* aVertex);
        void BFS(Vertex* aVertex);
        int getDFSCost();
        int getBFSCost();
        bool pathExists(Vertex *source, Vertex *destination);
    protected:
        int indexIs(Vertex* aVertex);
        void clearMarks();
        void calculateCost(int &cost, int row, int col);

    private:
        static const int NULL_EDGE = 0;
        vector<Vertex*> vertices;
        vector<vector <int>> edges;
        vector<bool> marks;
        int nmbVertices;
        int maxVertices;
        int dfsCost;
        int bfsCost;
};

#endif // WEIGHTEDGRAPH_H
