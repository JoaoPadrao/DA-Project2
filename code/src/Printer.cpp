#include "../headers/Printer.h"

Printer::Printer() = default;

Printer::Printer(const std::string& filePath,int id) {
    std::ifstream fileIn(filePath);
    switch (id) {
        case 1:
            Reader::readShippingStadiumToysGraph(fileIn, graph);
            break;
        case 2:
            Reader::readTourismToyGraph(fileIn,graph);
            break;
        default:
            break;

    }
}

Printer::Printer(const std::string& nodePath,const std::string& edgesPath) {
    std::ifstream nodePathIn(nodePath);
    std::ifstream edgesPathIn(edgesPath);
    Reader::readRealNodes(nodePathIn,graph);
    Reader::readRealEdges(edgesPathIn,graph);

}

void Printer::printContent() {
    int m = 0;
    for(auto v: graph.getVertexSet()){
        for(auto e: v->getAdj()){
            /* Dá print do Toy Graph Shipping e Stadium
             * std::cout << "SOURCE: " << e->getOrig()->getId() << " || DEST: " << e->getDest()->getId() << " || DISTANCE: " << e->getDistance() << std::endl;
            */

            /* Dá print do Toy Graph Tourism
             * std::cout << "SOURCE: " << e->getOrig()->getPlace()->getID() << " || DEST: " << e->getDest()->getPlace()->getID()
             *  << " || DISTANCE: " << e->getDistance() << " || SOURCE_NAME: " << e->getOrig()->getPlace()->getName() <<
             * " || DEST_NAME: " << e->getDest()->getPlace()->getName() << std::endl;
             */

            std::cout << "SOURCE: " << e->getOrig()->getNode()->getID() << " || DEST: " << e->getDest()->getNode()->getID()
             << " || DISTANCE: " << e->getDistance() << " || LONGITUDE: " << e->getOrig()->getNode()->getLongitude() <<
             " || LATITUDE: " << e->getDest()->getNode()->getLatitude() << std::endl;

            m++;
        }
    }
    std::cout << "Edges count: " << m << " || VERTICES: " << graph.getVertexSet().size()<<std::endl;
}

void Printer::printCostAndPath() {
    std::vector<Vertex*> path;
    double cost = graph.tspBT(path);

    std::cout << "Cost: " << cost << std::endl;
    std::cout << "Path:";
    for (auto v : path) {
        std::cout << " " << v->getId();
    }
    std::cout << std::endl;
}
