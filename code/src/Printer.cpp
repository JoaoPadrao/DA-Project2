#include "../headers/Printer.h"
#include <chrono>

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

void Printer::printCostAndPath() {
    std::vector<Vertex*> path;

    auto start = std::chrono::high_resolution_clock::now();

    double cost = graph.tspBT(path);

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Cost: " << cost << std::endl;
    std::cout << "Path:";
    for (auto v : path) {
        std::cout << " " << v->getId();
    }
    std::cout << std::endl;
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Execution time: " << duration << " milliseconds" << std::endl;
}
