#ifndef FEUP_DA_PROJ2_PRINTER_H
#define FEUP_DA_PROJ2_PRINTER_H

#include "Graph.h"
#include "Reader.h"

#include <fstream>

class Printer {
public:
    Printer();
    Printer(const std::string& edgesPath);

    void printContent();
    void printCostAndPath();
    void printCostAndPathTAH();
private:
    Graph graph;
};

#endif //FEUP_DA_PROJ2_PRINTER_H
