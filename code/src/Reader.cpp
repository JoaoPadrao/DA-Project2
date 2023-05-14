#include "../headers/Reader.h"

/**
 * The method reads the shipping and stadiums toy graph file and stores the data in both the nodes and edges of the graph.
 * @param in stations file ifstream
 * @param graph
 */
void Reader::readEdges(std::ifstream &in, Graph& graph) {
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
