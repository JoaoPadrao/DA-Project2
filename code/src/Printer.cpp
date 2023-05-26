#include "../headers/Printer.h"
#include <chrono>

Printer::Printer() = default;

Printer::Printer(const std::string& edgesPath) {
    std::ifstream edgesIn(edgesPath);
    Reader::readEdges(edgesIn, graph);
    if(edgesPath.find("real_graphs") != std::string::npos) {
        std::string nodesPath = edgesPath;
        size_t pos = nodesPath.find("edges");
        if (pos != std::string::npos) {
            nodesPath.replace(pos, 5, "nodes");
            std::ifstream nodesIn(nodesPath);
            Reader::readNodes(nodesIn, graph);
        }
    }
}

void Printer::printContent() {
    int m = 0;
    for(auto v: graph.getVertexSet()){
        if(v->getCoords() != nullptr)
            std::cout <<
                      "NODE: " << v->getId() <<
                      " || LATITUDE: " << v->getCoords()->latitude <<
                      " || LONGITUDE: " << v->getCoords()->longitude <<
                      std::endl;
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

void Printer::printCostAndPathTAH() {
    std::vector<Vertex*> path;

    auto start = std::chrono::high_resolution_clock::now();

    auto mst = graph.mst();

    double total_cost = graph.tsp_TRIANG_approx(mst);

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Minimum Spanning Tree (Prim Algorithm):" << std::endl;
    for (auto v : mst) {
        if (v->getPath() != nullptr) {
            Edge *edge = v->getPath();
            std::cout << edge->getOrig()->getId() << " - " << edge->getDest()->getId() << std::endl;
        }
    }
    std:: cout << "Pre-order: ";
    for (auto v : mst){
        std::cout << v->getId() << " -> ";
    }
    std::cout << "0" << std::endl;
    std::cout << "Cost: " << total_cost << std::endl;

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Execution time: " << duration << " milliseconds" << std::endl;
}