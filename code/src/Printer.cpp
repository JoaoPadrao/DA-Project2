#include "../headers/Printer.h"

Printer::Printer() = default;

Printer::Printer(const std::string& filePath) {
    std::ifstream fileIn(filePath);
    Reader::readEdges(fileIn, graph);
}

void Printer::printContent() {
    int m = 0;
    for(auto v: graph.getVertexSet()){
        for(auto e: v->getAdj()) {
            std::cout << "SOURCE: " << e->getOrig()->getId() << " || DEST: " << e->getDest()->getId() << " || DISTANCE: " << e->getDistance() << std::endl;
            m++;
        }
    }
    std::cout << "Edges count: " << m << " || VERTICES: " << graph.getVertexSet().size()<<std::endl;
}
