#include "../headers/Reader.h"

void Reader::readEdges(std::ifstream &in, Graph& graph) {
    std::string aux;
    int srcID, destID;
    double dist;
    bool isFirst = true;

    for (std::string line; getline(in, line);) {
        if (isFirst) {
            isFirst = false;
            if (line[0] != '0') continue;
        }

        std::stringstream ss(line);
        getline(ss, aux, ',');
        srcID = std::stoi(aux);
        getline(ss, aux, ',');
        destID = std::stoi(aux);
        getline(ss, aux, '\n');
        dist = std::stod(aux);

        Vertex* src = nullptr;
        Vertex* dest = nullptr;

        for (auto v : graph.getVertexSet()) {
            if (v == nullptr) continue;
            if (v->getId() == srcID) src = v;
            if (v->getId() == destID) dest = v;
        }

        if (src == nullptr) {
            src = graph.addVertex(srcID);
        }

        if (dest == nullptr) {
            dest = graph.addVertex(destID);
        }

        graph.addBidirectionalEdge(src, dest, dist);
    }
}


void Reader::readNodes(std::ifstream &in, Graph& graph) {
    std::string aux;
    int id;
    double longitude, latitude;
    bool isFirst = true;

    for (std::string line; getline(in, line);) {
        if (isFirst) {
            isFirst = false;
            if (line[0] != '0') continue;
        }

        std::stringstream ss(line);
        getline(ss, aux, ',');
        id = std::stoi(aux);
        getline(ss, aux, ',');
        longitude = std::stod(aux);
        getline(ss, aux, '\n');
        latitude = std::stod(aux);

        graph.getVertexSet()[id]->setCoords(longitude, latitude);
    }
}