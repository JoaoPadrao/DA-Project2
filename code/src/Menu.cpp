#include <fstream>
#include "../headers/Menu.h"
#include "../headers/Reader.h"

Menu::Menu() {
    printer = readSelectedFile();
}

void toBeImplemented() {
    std::cout << "This functionality is yet to be implemented." << std::endl;
}

Printer Menu::readSelectedFile() {
    std::cout << "[1] Read real graph" << std::endl;
    std::cout << "[2] Read toy graph" << std::endl;
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
                    return {"../code/data/real_graphs/graph1/edges.csv"};
                } else if(graphChosen == "2")  {
                    return {"../code/data/real_graphs/graph2/edges.csv"};
                } else if(graphChosen == "3")  {
                    return {"../code/data/real_graphs/graph3/edges.csv"};
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
                    return {"../code/data/toys_graph/shipping.csv"};
                } else if(graphChosen == "2")  {
                    return {"../code/data/toys_graph/stadiums.csv"};
                } else if(graphChosen == "3")  {
                    return {"../code/data/toys_graph/tourism.csv"};
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
        std::cout << "[2] Exit" << std::endl;
        std::cout << "Press one of the options: ";
        std::getline(std::cin,option);
        std::cout << std::endl;

        if(option == "1") {
            printer.printContent();
        }else if (option == "2") {
            break;
        }else{
            std::cout << "FATAL ERROR (core dumped)" << std::endl;
        }

        std::cout << std::endl;
    }
}
