#include <iostream>
#include "../headers/Graph.h"
#include <algorithm>

/**
 * Return the distance of the edge connecting the source vertex with the destination vertex or -1 if there is no edge\n
 * Complexity: O(V+E) V-> number of vertices; E-> number of edges
 * @param source id of the source vertex
 * @param dest id of the destination vertex
 * @return weight of the edge / -1 if the edge doesn't exist
 */
double Graph::dist(int source, int dest) {
    for (auto v : vertexSet) {
        if (v->getId() == source) {
            for (auto e : v->getAdj()) {
                if (e->getDest()->getId() == dest) {
                    return e->getDistance();
                }
            }
        }
    }
    return -1;
}

/**
 * This function performs the backtracking algorithm to find the shortest path that visits all the vertices in the graph\n
 * Complexity: O(V!) V-> number of vertices
 * @param path reference to a vector of vertices that represents the shortest path found so far
 * @param currPath vector of vertices that represents the current path being explored
 * @param currCost double that represents the current cost of the path being explored
 * @param bestCost reference to a double that represents the cost of the best path found so far
 */
void Graph::backtracking(std::vector<Vertex*> &path, std::vector<Vertex*> currPath, double currCost, double &bestCost, int index) {
    if (index == vertexSet.size()) {
        double dist = Graph::dist(currPath[index-1]->getId(), 0);
        if (dist != -1) {
            currCost += dist;
            if (currCost < bestCost) {
                bestCost = currCost;
                path = currPath;
            }
        }

        return;
    }

    for (int i = 1; i < vertexSet.size(); i++) {
        double dist = Graph::dist(currPath[index - 1]->getId(), i);
        Vertex* vertex = findVertex(i);
        if (dist != -1 && currCost + dist < bestCost && std::find(currPath.begin(), currPath.end(), vertex) == currPath
        .end()) {
            currPath[index] = vertex;
            backtracking(path, currPath, currCost + dist, bestCost, index+1);
        }
    }
}

/**
 * Finds the shortest path that visits all vertices in the graph using the backtracking algorithm\n
 * Complexity: O(V!) V-> number of vertices
 * @param path reference to a vector of vertices that represents the shortest path found so far
 * @return double that represents the cost of the best path
 */
double Graph::tspBT(std::vector<Vertex*> &path) {
    std::vector<Vertex*> currPath(vertexSet.size(), nullptr);
    double bestCost = LONG_MAX;
    currPath[0] = vertexSet[0];
    backtracking(path, currPath, 0, bestCost, 1);

    return bestCost;
}

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

/**
 * This method finds a vertex in the graph with a certain id \n
 * Complexity: O(V) V-> number of vertices;
 * @param id id to be searched
 * @return pointer to the vertex / null pointer if it doesn't exist
 */
Vertex * Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}

Vertex *Graph::findPlace(const int &id) const {
    for (auto v : vertexSet)
        if (v->getPlace()->getID() == id)
            return v;
    return nullptr;
}

Vertex *Graph::findNode(const int &id) const {
    for (auto v : vertexSet)
        if (v->getNode()->getID() == id)
            return v;
    return nullptr;
}


bool Graph::addVertex(const int &id) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id));
    return true;
}

bool Graph::addPlace(Place *place) {
    if (findPlace(place->getID()) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(place));
    return true;
}

bool Graph::addNode(Node *node) {
    if (findNode(node->getID()) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(node));
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}

bool Graph::addBidirectionalEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    auto e2 = v2->addEdge(v1, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

bool Graph::addBidirectionalEdgePlace(const int &sourc, const int &dest, double w) {
    auto v1 = findPlace(sourc);
    auto v2 = findPlace(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    auto e2 = v2->addEdge(v1, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

bool Graph::addBidirectionalEdgeNode(const int &sourc, const int &dest, double w) {
    auto v1 = findNode(sourc);
    auto v2 = findNode(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    auto e2 = v2->addEdge(v1, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}