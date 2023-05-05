#ifndef FEUP_DA_PROJ2_VERTEXPLACEEDGE_H
#define FEUP_DA_PROJ2_VERTEXPLACEEDGE_H

#include <string>
#include <vector>
#include "Place.h"

class EdgePlace;

class VertexPlace {
public:
    VertexPlace(Place* place);

    Place* getPlace();
    std::vector<EdgePlace *> getAdj() const;
    bool isVisited() const;
    bool isProcessing() const;
    unsigned int getIndegree() const;
    double getDist() const;
    EdgePlace *getPath() const;
    std::vector<EdgePlace *> getIncoming() const;

    void setVisited(bool visited);
    void setProcesssing(bool processing);
    void setIndegree(unsigned int indegree);
    void setDist(double dist);
    void setPath(EdgePlace *path);
    EdgePlace * addEdgePlace(VertexPlace *dest, double w);
    bool removeEdge(Place* place);
    void removeOutgoingEdges();

protected:
    Place* place;
    std::vector<EdgePlace *> adj;  // outgoing edges

    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    EdgePlace *path = nullptr;
    bool operator<(VertexPlace & vertex) const;

    std::vector<EdgePlace *> incoming; // incoming edges

    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS

};

/********************** Edge  ****************************/

class EdgePlace {
public:
    EdgePlace(VertexPlace *orig, VertexPlace *dest, double dist);

    VertexPlace * getDest() const;
    double getDistance() const;
    bool isSelected() const;
    VertexPlace * getOrig() const;
    EdgePlace *getReverse() const;
    double getFlow() const;

    void setSelected(bool selected);
    void setReverse(EdgePlace *reverse);
protected:
    VertexPlace * dest;
    double dist;

    // auxiliary fields
    bool selected = false;

    VertexPlace *orig;
    EdgePlace *reverse = nullptr;

};
#endif //FEUP_DA_PROJ2_VERTEXPLACEEDGE_H
