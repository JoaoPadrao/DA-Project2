#ifndef FEUP_DA_PROJ2_PRINTER_H
#define FEUP_DA_PROJ2_PRINTER_H

#include "Graph.h"
#include "Reader.h"

#include <fstream>

class Printer {
public:
    Printer();
    Printer(const std::string& edgesPath, bool connected);

    void printContent();
    void printCostAndPath();
    void printCostAndPathTAH(bool isShippingGraph);
    void printCostAndPathHeuristic();
    bool isConnected() const;

private:
    Graph graph;
    bool connected;
};

#endif //FEUP_DA_PROJ2_PRINTER_H
