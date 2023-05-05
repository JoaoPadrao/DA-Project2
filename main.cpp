#include "code/headers/Menu.h"


int main() {
    Menu menu;
    menu.run();
}

/*
    //This code is to read the toys -> "shipping.csv"
    std::string shipping = "../code/data/toys/shipping.csv";

    std::ifstream shippingIn(shipping);
    Graph graph_shipping;
    Reader::readShippingStadiumToysGraph(shippingIn, graph_shipping);
    int i = 0;
    for(auto v: graph_shipping.getVertexSet()){
        for(auto e: v->getAdj()){
            std::cout << "SOURCE: " << e->getOrig()->getId() << " || DEST: " << e->getDest()->getId() << " || DISTANCE: " << e->getDistance() << std::endl;
            i++;
        }
    }
    std::cout << "Edges count: " << i;




    //This code is to read the toys -> "stadiums.csv"
    std::string stadiums = "../code/data/toys/stadiums.csv";

    std::ifstream stadiumsIn(stadiums);
    Graph graph_stadiums;
    Reader::readShippingStadiumToysGraph(stadiumsIn, graph_stadiums);
    int m = 0;
    for(auto v: graph_stadiums.getVertexSet()){
        for(auto e: v->getAdj()){
            std::cout << "SOURCE: " << e->getOrig()->getId() << " || DEST: " << e->getDest()->getId() << " || DISTANCE: " << e->getDistance() << std::endl;
            m++;
        }
    }
    std::cout << "Edges count: " << m;



    //This code is to read the toys -> "tourism.csv"
    std::string tourism = "../code/data/toys/tourism.csv";

    std::ifstream stadiumsIn(tourism);
    Graph graph_tourism;
    Reader::readTourismToyGraph(stadiumsIn, graph_tourism);
    int m = 0;
    for(auto v: graph_tourism.getVertexPlaceSet()){
        for(auto e: v->getAdj()){
            std::cout << "SOURCE: " << e->getOrig()->getPlace()->getID() << " || DEST: " << e->getDest()->getPlace()->getID()
            << " || DISTANCE: " << e->getDistance() << " || SOURCE_NAME: " << e->getOrig()->getPlace()->getName() << " || DEST_NAME: " <<
            e->getDest()->getPlace()->getName() << std::endl;
            m++;
        }
    }
    std::cout << "Edges count: " << m;
}
*/