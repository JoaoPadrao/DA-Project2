#ifndef FEUP_DA_PROJ2_PRINTER_H
#define FEUP_DA_PROJ2_PRINTER_H

#include "Graph.h"
#include "Reader.h"

#include <fstream>

class Printer {
public:
    Printer();
    Printer(const std::string& filePath);

    void printContent();
    void printCostAndPath();
private:
    Graph graph;
};

#endif //FEUP_DA_PROJ2_PRINTER_H
