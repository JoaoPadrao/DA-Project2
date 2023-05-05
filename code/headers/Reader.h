#ifndef FEUP_DA_PROJ2_READER_H
#define FEUP_DA_PROJ2_READER_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_set>
#include "Graph.h"

class Reader {
public:
    static void readShippingStadiumToysGraph(std::ifstream &in, Graph& graph);
    static void readTourismToyGraph(std::ifstream &in, Graph& graph);
};

#endif //FEUP_DA_PROJ2_READER_H
