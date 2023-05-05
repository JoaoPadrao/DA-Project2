#include "../headers/VertexPlaceEdge.h"
#include "../headers/Place.h"

/************************* Vertex  **************************/

VertexPlace::VertexPlace(Place* place) : place(place) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
EdgePlace * VertexPlace::addEdgePlace(VertexPlace *d, double w) {
    auto newEdge = new EdgePlace(this, d, w);
    adj.push_back(newEdge);
    d->incoming.push_back(newEdge);
    return newEdge;
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
bool VertexPlace::removeEdge(Place* place) {
    bool removedEdge = false;
    auto it = adj.begin();
    while (it != adj.end()) {
        EdgePlace *edge = *it;
        VertexPlace *dest = edge->getDest();
        if (dest->place == place) {
            it = adj.erase(it);
            auto it2 = dest->incoming.begin();
            while (it2 != dest->incoming.end()) {
                if ((*it2)->getOrig()->getPlace()== place) {
                    it2 = dest->incoming.erase(it2);
                }
                else {
                    it2++;
                }
            }
            delete edge;
            removedEdge = true; // allows for multiple edges to connect the same pair of vertices (multigraph)
        }
        else {
            it++;
        }
    }
    return removedEdge;
}


bool VertexPlace::operator<(VertexPlace & vertex) const {
    return this->dist < vertex.dist;
}

Place* VertexPlace::getPlace(){
    return this->place;
}
std::vector<EdgePlace*> VertexPlace::getAdj() const {
    return this->adj;
}

bool VertexPlace::isVisited() const {
    return this->visited;
}

bool VertexPlace::isProcessing() const {
    return this->processing;
}

unsigned int VertexPlace::getIndegree() const {
    return this->indegree;
}

double VertexPlace::getDist() const {
    return this->dist;
}

EdgePlace *VertexPlace::getPath() const {
    return this->path;
}

std::vector<EdgePlace *> VertexPlace::getIncoming() const {
    return this->incoming;
}


void VertexPlace::setVisited(bool visited) {
    this->visited = visited;
}

void VertexPlace::setProcesssing(bool processing) {
    this->processing = processing;
}

void VertexPlace::setIndegree(unsigned int indegree) {
    this->indegree = indegree;
}

void VertexPlace::setDist(double dist) {
    this->dist = dist;
}

void VertexPlace::setPath(EdgePlace *path) {
    this->path = path;
}



/********************** Edge  ****************************/

EdgePlace::EdgePlace(VertexPlace *orig, VertexPlace *dest, double dist): orig(orig), dest(dest), dist(dist) {}

VertexPlace * EdgePlace::getDest() const {
    return this->dest;
}

double EdgePlace::getDistance() const {
    return this->dist;
}

VertexPlace * EdgePlace::getOrig() const {
    return this->orig;
}

EdgePlace *EdgePlace::getReverse() const {
    return this->reverse;
}

bool EdgePlace::isSelected() const {
    return this->selected;
}



void EdgePlace::setSelected(bool selected) {
    this->selected = selected;
}

void EdgePlace::setReverse(EdgePlace *reverse) {
    this->reverse = reverse;
}

