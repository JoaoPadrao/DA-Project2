#include <iostream>
#include "../headers/Graph.h"
#include <algorithm>
#include <valarray>

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
                if (e == nullptr) continue;
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

/**
* Finds the shortest path that visits all vertices in the graph using the Triangular Approximation Heuristic algorithm\n
* Complexity:
* @param path reference to a vector of vertices that represents the shortest path found so far
* @return double that represents the cost of the best path
*/
double Graph::tsp_TRIANG_approx(std::vector<Vertex*> &path) {
    double cost = 0.0;
    Vertex* vertex_0 = Graph::findVertex(0);
    int last_index = path.size();
    for(int i = 0; i < path.size()-1;i++){
        cost += Graph::calculateDistance(path[i],path[i+1]);
    }
    cost += Graph::calculateDistance(path[last_index-1],vertex_0);
    return cost;
}

double Graph::calculateShipping(std::vector<Vertex*> &path){
    double cost = 0.0;
    Vertex* vertex_0 = Graph::findVertex(0);
    int last_index = path.size();
    double sum = 0.0;

    for(auto v : path){
        sum += v->getDist();
    }
    sum = sum / path.size(); // Average of the all edges (distance)


    for(int i = 0; i < path.size() -1; i++){
        double dist = Graph::dist(path[i],path[i+1]);
        if(dist == -1){
            dist = sum;
        }
        cost += dist;
    }

    if(Graph::dist(path[last_index-1],vertex_0) == -1){
        cost += sum;
    }
    else cost += Graph::dist(path[last_index-1],vertex_0);

    return cost;
}

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

/**
 * This method finds a vertex in the graph with a certain id \n
 * Complexity: O(V) V-> number of vertices
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

Vertex* Graph::addVertex(const int &id) {
    if (id >= vertexSet.size()) vertexSet.resize(id + 1, nullptr);

    if (vertexSet[id] == nullptr) vertexSet[id] = new Vertex(id);
    return vertexSet[id];
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

bool Graph::addBidirectionalEdge(Vertex* v1, Vertex* v2, double w) {
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    auto e2 = v2->addEdge(v1, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

/**
 * Calculates the minimum spanning tree of the graph using Prim's algorithm.
 * Complexity: O(|V|+|E|*log|V|) V-> number of vertices; E-> number of edges
 * @return Vector containing the vertices of the minimum spanning tree.
 */
std::vector<Vertex *> Graph::mstPrim() {
    MutablePriorityQueue<Vertex> q;
    std::vector<Vertex *> res;
    for (auto v: vertexSet) {
        v->setVisited(false);
        if (v == *vertexSet.begin()) {
            v->setDist(0);
            v->setPath(nullptr);
        } else {
            v->setDist(INT_MAX);
        }
        q.insert(v);
    }
    while (!q.empty()) {
        auto u = q.extractMin();
        res.push_back(u);
        u->setVisited(true);
        for (auto w: u->getAdj()) {
            if (w == nullptr) continue;
            auto v = w->getDest();
            if (!v->isVisited() && w->getDistance() < v->getDist()) {
                v->setPath(w);
                v->setDist(w->getDistance());
                q.decreaseKey(v);
            }
        }
    }
    return res;
}

/**
 * Adds the IDs of the destination vertices, for each vertex, to the destination vertex vector.
 * Complexity: O(|V|) V-> number of vertices;
 */
void Graph::addVectorPath() {
    for (auto v : vertexSet) {
        if (v->getPath() != nullptr) {
            auto initial_vertex = v->getPath()->getOrig();
            std::vector<int>& initVertexVector = initial_vertex->getDestVertexVector();
            initVertexVector.push_back(v->getPath()->getDest()->getId());
        }
    }
}

/**
 * Calculates the distance between two vertices in the graph.
 * The function calculate the distance using the existing distance value stored in the graph between the two vertices.
 * If there is no edge, it uses the Haversine formula to calculate the distance.
 * Complexity: O(V+E) V-> number of vertices; E-> number of edges
 * @param v1 Pointer to the first vertex.
 * @param v2 Pointer to the second vertex.
 * @return The distance between the two vertices.
 */
double Graph::calculateDistance(Vertex *v1,Vertex *v2){
    double distance = Graph::dist(v1,v2);
    if (distance == -1.0){
        distance = Graph::Haversine(v1,v2);
    }
    return distance;
}

/**
 * Performs a depth-first search (DFS) starting from a given vertex.
 * Complexity: O(V*n) V-> number of vertices; n-> number of vertices in vector
 * @param v Pointer to the starting vertex for the DFS.
 * @param visited Reference to a vector to store the visited vertices.
 */
void Graph::dfs(Vertex* v, std::vector<Vertex*>& visited) {
    visited.push_back(v);
    v->setVisited(true);

    for (auto w : v->getDestVertexVector()) {
        auto u = Graph::findVertex(w);
            if(!u->isVisited()) {
                dfs(u, visited);
            }
        }
}

/**
 * Calculate the distance between two vertices
 * Complexity: O(V+E) V-> number of vertices; E-> number of edges
 * @param source Pointer to the source vertex.
 * @param dest Pointer to the destination vertex.
 * @return The distance between the two vertices if there is an edge between them,or -1.0 if not.
 */
double Graph::dist(Vertex *source, Vertex *dest) {
    try {
        Edge* edge = source->getAdj()[dest->getId()];
        if (edge == nullptr) return -1;
        return edge->getDistance();
    } catch (const std::out_of_range&) {
        return -1;
    }
}

/**
 * Calculates the Haversine distance between two vertex
 * Complexity: O(1)
 * @param v1 Pointer to the first vertex.
 * @param v2 Pointer to the second vertex.
 * @return The Haversine distance between the two vertex.
 */
double Graph::Haversine(Vertex* v1, Vertex* v2) {
    double v1_lat_rad = (v1->getCoords()->latitude * M_PI) / 180.0;
    double v2_lat_rad = (v2->getCoords()->latitude * M_PI) / 180.0;
    double v1_lon_rad = (v1->getCoords()->longitude * M_PI) / 180.0;
    double v2_lon_rad = (v2->getCoords()->longitude * M_PI) / 180.0;

    double delta_lat = v2_lat_rad  - v1_lat_rad;
    double delta_lon = v2_lon_rad - v1_lon_rad;
    double aux = std::sin(delta_lat / 2.0) * std::sin(delta_lat / 2.0) + std::cos(v1_lat_rad) * std::cos(v2_lat_rad) * std::sin(delta_lon / 2.0) * std::sin(delta_lon / 2.0);
    double c = 2.0 * std::atan2(std::sqrt(aux), std::sqrt(1.0 - aux));
    double earthradius = 6371000.0;
    return earthradius * c;
}


double Graph::nearestNeighbour(std::vector<Vertex*> &path) {
    double cost = 0;
    for(Vertex* v: vertexSet) {
        v->setVisited(false);
    }

    Vertex* currentVertex = findVertex(0);
    path.clear();
    path.push_back(currentVertex);
    currentVertex->setVisited(true);

    while (path.size() < getNumVertex()) {
        double minDistance = LONG_MAX;
        Vertex* nextVertex = nullptr;

        for (Edge* edge : currentVertex->getAdj()) {
            if (edge == nullptr) continue;
            Vertex* neighbor = edge->getDest();
            if (!neighbor->isVisited() && edge->getDistance() < minDistance) {
                minDistance = edge->getDistance();
                nextVertex = neighbor;
            }
        }

        if (nextVertex != nullptr) {
            cost += minDistance;
            nextVertex->setVisited(true);
            path.push_back(nextVertex);
            currentVertex = nextVertex;
        }
    }

    cost += calculateDistance(path[path.size() - 1], path[0]);

    return cost;
}

double Graph::tsp_Heuristic(std::vector<Vertex*> &path) {
    double cost = nearestNeighbour(path);

    bool improved = true;
    while (improved) {
        improved = false;

        for (int i = 0; i < path.size() - 2; i++) {
            for (int j = i + 2; j < path.size() - 1; j++) {
                double oldCost = calculateDistance(path[i], path[i + 1]) + calculateDistance(path[j], path[j + 1]);
                double newCost = calculateDistance(path[i], path[j]) + calculateDistance(path[i + 1], path[j + 1]);

                if (newCost < oldCost) {
                    std::reverse(path.begin() + i + 1, path.begin() + j + 1);
                    cost -= oldCost - newCost;
                    improved = true;
                }
            }
        }
    }

    return cost;
}

