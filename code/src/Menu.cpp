#include <fstream>
#include "../headers/Menu.h"

Menu::Menu() {
    printer = readSelectedFile();
}

Printer Menu::readSelectedFile() {
    std::cout << "[1] Read real graph" << std::endl;
    std::cout << "[2] Read toy graph" << std::endl;
    std::cout << "[3] Read medium graph" << std::endl;
    std::string option, graphChosen;

    while(true) {
        std::cout << "Press one of the options: ";
        std::getline(std::cin,option);
        std::cout << std::endl;

        if(option == "1"){
            std::cout << "[1] Real graph 1" << std::endl;
            std::cout << "[2] Real graph 2" << std::endl;
            std::cout << "[3] Real graph 3" << std::endl;

            while(true) {
                std::cout << "Press one of the options: ";
                std::getline(std::cin,graphChosen);
                std::cout << std::endl;

                if(graphChosen == "1")  {
                    return {"../code/data/real_graphs/graph1/edges.csv", true};
                } else if(graphChosen == "2")  {
                    return {"../code/data/real_graphs/graph2/edges.csv", false};
                } else if(graphChosen == "3")  {
                    return {"../code/data/real_graphs/graph3/edges.csv", false};
                }
                std::cout << std::endl;
            }
        }
        else if(option == "2"){
            std::cout << "[1] Shipping graph" << std::endl;
            std::cout << "[2] Stadiums graph" << std::endl;
            std::cout << "[3] Tourism graph" << std::endl;

            while(true) {
                std::cout << "Press one of the options: ";
                std::getline(std::cin,graphChosen);
                std::cout << std::endl;

                if(graphChosen == "1")  {
                    this->isShippingGraph = true;
                    return {"../code/data/toys_graph/shipping.csv", false};
                } else if(graphChosen == "2")  {
                    return {"../code/data/toys_graph/stadiums.csv", true};
                } else if(graphChosen == "3")  {
                    return {"../code/data/toys_graph/tourism.csv", true};
                }
                std::cout << std::endl;
            }
        }
        else if(option == "3"){
            std::cout << "[1] Graph with 25 nodes" << std::endl;
            std::cout << "[2] Graph with 50 nodes" << std::endl;
            std::cout << "[3] Graph with 75 nodes" << std::endl;
            std::cout << "[4] Graph with 100 nodes" << std::endl;
            std::cout << "[5] Graph with 200 nodes" << std::endl;
            std::cout << "[6] Graph with 300 nodes" << std::endl;
            std::cout << "[7] Graph with 400 nodes" << std::endl;
            std::cout << "[8] Graph with 500 nodes" << std::endl;
            std::cout << "[9] Graph with 600 nodes" << std::endl;
            std::cout << "[10] Graph with 700 nodes" << std::endl;
            std::cout << "[11] Graph with 800 nodes" << std::endl;
            std::cout << "[12] Graph with 900 nodes" << std::endl;

            while(true) {
                std::cout << "Press one of the options: ";
                std::getline(std::cin,graphChosen);
                std::cout << std::endl;

                if (graphChosen == "1") {
                    return {"../code/data/medium_graphs/edges_25.csv", true};
                } else if (graphChosen == "2") {
                    return {"../code/data/medium_graphs/edges_50.csv", true};
                } else if (graphChosen == "3") {
                    return {"../code/data/medium_graphs/edges_75.csv", true};
                } else if (graphChosen == "4") {
                    return {"../code/data/medium_graphs/edges_100.csv", true};
                } else if (graphChosen == "5") {
                    return {"../code/data/medium_graphs/edges_200.csv", true};
                } else if (graphChosen == "6") {
                    return {"../code/data/medium_graphs/edges_300.csv", true};
                } else if (graphChosen == "7") {
                    return {"../code/data/medium_graphs/edges_400.csv", true};
                } else if (graphChosen == "8") {
                    return {"../code/data/medium_graphs/edges_500.csv", true};
                } else if (graphChosen == "9") {
                    return {"../code/data/medium_graphs/edges_600.csv", true};
                } else if (graphChosen == "10") {
                    return {"../code/data/medium_graphs/edges_700.csv", true};
                } else if (graphChosen == "11") {
                    return {"../code/data/medium_graphs/edges_800.csv", true};
                } else if (graphChosen == "12") {
                    return {"../code/data/medium_graphs/edges_900.csv", true};
                }
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

void Menu::run() {
    while(true){
        std::string option;
        std::cout << "MAIN MENU" << std::endl;
        std::cout << "[1] Print graph contents" << std::endl;
        std::cout << "[2] Cost with the Backtracking Algorithm" << std::endl;
        std::cout << "[3] Cost with the Triangular Approximation Heuristic" << std::endl;
        std::cout << "[4] Cost with Other Heuristics" << std::endl;
        std::cout << "[5] Choose a different graph" << std::endl;
        std::cout << "[6] Exit" << std::endl;
        std::cout << "Press one of the options: ";
        std::getline(std::cin,option);
        std::cout << std::endl;

        if(option == "1") {
            printer.printContent();
        }else if (option == "2") {
            printer.printCostAndPath();
        }else if (option == "3") {
            if(this->isShippingGraph) printer.printCostAndPathTAH(isShippingGraph);
            else printer.printCostAndPathTAH(isShippingGraph);
        }else if (option == "4") {
            if (printer.isConnected()) printer.printCostAndPathHeuristic();
            else std::cout << "Our algorithm doesn't work with graphs not fully connected.\n";
        }else if (option == "5") {
            this->isShippingGraph = false;
            printer = readSelectedFile();
        }else if (option == "6") {
            break;
        }else{
            std::cout << "FATAL ERROR (core dumped)" << std::endl;
        }

        std::cout << std::endl;
    }
}
