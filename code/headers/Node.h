#ifndef FEUP_DA_PROJ2_NODE_H
#define FEUP_DA_PROJ2_NODE_H

class Node {
public:
    Node(int id, double longitude, double latitude);

    int getID() const;
    double getLongitude() const;
    double getLatitude() const;
    bool operator==(const Node& n) const;
    bool operator!=(const Node& n) const;
private:
    int id_;
    double longitude_;
    double latitude_;
};
#endif //FEUP_DA_PROJ2_NODE_H
