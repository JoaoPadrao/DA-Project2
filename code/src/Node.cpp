#include "../headers/Node.h"

Node::Node(int id,double longitude, double latitude) : id_(id),longitude_(longitude),latitude_(latitude) {}


int Node::getID() const {
    return id_;
}
double Node::getLongitude() const {
    return longitude_;
}
double Node::getLatitude() const {
    return latitude_;
}

bool Node::operator==(const Node& n) const {
    return id_ == n.id_;
}

bool Node::operator!=(const Node& n) const {
    return id_ != n.id_;
}