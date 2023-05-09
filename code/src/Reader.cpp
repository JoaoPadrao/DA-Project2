#include "../headers/Reader.h"
#include "../headers/Place.h"

/**
 * The method reads the shipping and stadiums toy graph file and stores the data in both the nodes and edges of the graph.
 * @param in stations file ifstream
 * @param graph
 */
void Reader::readShippingStadiumToysGraph(std::ifstream &in, Graph& graph) {

    std::string firstLine, aux;
    int srcID, destID;
    double dist;

    getline(in, firstLine); // to ignore the 1st line
    for (std::string line; getline(in, line);) {
        std::stringstream ss(line);
        getline(ss, aux, ',');
        srcID = std::stoi(aux);
        getline(ss, aux, ',');
        destID = std::stoi(aux);
        getline(ss, aux, '\n');
        dist = std::stod(aux);

        graph.addVertex(srcID);
        graph.addVertex(destID);
        graph.addBidirectionalEdge(srcID, destID, dist);

    }
}

/**
 * The method reads the tourism toy graph file and stores the data in both the nodes and edges of the graph.
 * @param in stations file ifstream
 * @param graph
 */
void Reader::readTourismToyGraph(std::ifstream &in, Graph& graph) {

    std::string firstLine, aux, src_name, dest_name;
    int srcID, destID, dist;

    getline(in, firstLine); // to ignore the 1st line
    for (std::string line; getline(in, line);) {
        std::stringstream ss(line);
        getline(ss, aux, ',');
        srcID = std::stoi(aux);
        getline(ss, aux, ',');
        destID = std::stoi(aux);
        getline(ss, aux, ',');
        dist = std::stoi(aux);
        getline(ss, src_name, ',');
        getline(ss, dest_name, '\n');

        auto *placeSrcPtr = new Place(srcID, src_name);
        auto *placeDestPtr = new Place(destID,dest_name);

        graph.addPlace(placeSrcPtr);
        graph.addPlace(placeDestPtr);
        graph.addBidirectionalEdgePlace(srcID, destID, dist);
    }
}

/**
 * The method reads the nodes from the real graph file and stores the data in the nodes of the graph.
 * @param in stations file ifstream
 * @param graph
 */
void Reader::readRealNodes(std::ifstream &in, Graph& graph) {
    std::string firstLine, aux;
    int ID;
    double longitude,latitude;

    getline(in, firstLine); // to ignore the 1st line
    for (std::string line; getline(in, line);) {
        std::stringstream ss(line);
        getline(ss, aux, ',');
        ID = std::stoi(aux);
        getline(ss, aux, ',');
        longitude = std::stod(aux);
        getline(ss, aux, '\n');
        latitude = std::stod(aux);

        auto *node = new Node(ID, longitude,latitude);
        graph.addNode(node);

    }
}

/**
 * The method reads the edges from the real graph file and stores the data in the edges of the graph.
 * @param in stations file ifstream
 * @param graph
 */
void Reader::readRealEdges(std::ifstream &in, Graph& graph) {
    std::string firstLine, aux;
    int srcID, destID;
    double dist;

    getline(in, firstLine); // to ignore the 1st line
    for (std::string line; getline(in, line);) {
        std::stringstream ss(line);
        getline(ss, aux, ',');
        srcID = std::stoi(aux);
        getline(ss, aux, ',');
        destID = std::stoi(aux);
        getline(ss, aux, '\n');
        dist = std::stod(aux);

        graph.addBidirectionalEdgeNode(srcID,destID,dist);

    }
}
