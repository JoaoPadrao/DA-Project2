#ifndef FEUP_DA_PROJ2_GRAPH_H
#define FEUP_DA_PROJ2_GRAPH_H

#include "VertexEdge.h"
#include "../headers/Place.h"

class Graph {
public:
    /*
    * Auxiliary function to find a vertex with a given ID.
    */
    Vertex *findVertex(const int &id) const;
    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(const int &id);


    bool addPlace(Place *place);

    Vertex *findPlace(const int &id) const;

    bool addNode(Node *node);

    Vertex * findNode(const int &id) const;

    /*
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const int &sourc, const int &dest, double w);
    bool addBidirectionalEdge(const int &sourc, const int &dest, double w);
    bool addBidirectionalEdgePlace(const int &sourc, const int &dest, double w);
    bool addBidirectionalEdgeNode(const int &sourc, const int &dest, double w);

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
