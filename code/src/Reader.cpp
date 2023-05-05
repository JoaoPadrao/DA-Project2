#include "../headers/Reader.h"
#include "../headers/Place.h"


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