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
            toBeImplemented();
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
                    return {"../code/data/toys/shipping.csv"};
                } else if(graphChosen == "2")  {
                    return {"../code/data/toys/stadiums.csv"};
                } else if(graphChosen == "3")  {
                    toBeImplemented();
                }
            }
        }
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
