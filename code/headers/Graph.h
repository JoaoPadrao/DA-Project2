#ifndef FEUP_DA_PROJ2_GRAPH_H
#define FEUP_DA_PROJ2_GRAPH_H

#include "VertexEdge.h"

class Graph {
public:
    /*
    * Auxiliary function to find a vertex with a given ID.
    */
    Vertex *findVertex(const int &id) const;

    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns a pointer do that vertex
     */
    Vertex* addVertex(const int &id);

    double dist(int source, int dest);

    double dist(Vertex* source, Vertex* dest);

    double calculateDistance(Vertex *v1,Vertex *v2);

    void dfs(Vertex* v, std::vector<Vertex*>& visited);

    double Haversine(Vertex* v1, Vertex* v2);


    void backtracking(std::vector<Vertex*> &path, std::vector<Vertex*> currPath, double currCost, double &bestCost, int
    index);

    double tspBT(std::vector<Vertex*> &path);

    double tsp_TRIANG_approx(std::vector<Vertex*> &path);
    double calculateShipping(std::vector<Vertex*> &path);
    /*
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const int &sourc, const int &dest, double w);

    bool addBidirectionalEdge(Vertex* v1, Vertex* v2, double w);

    std::vector<Vertex *> mstPrim();
    void addVectorPath();
    int getNumVertex() const;
    std::vector<Vertex *> getVertexSet() const;

protected:
    std::vector<Vertex *> vertexSet;    // vertex set


    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;
};

#endif //FEUP_DA_PROJ2_GRAPH_H
