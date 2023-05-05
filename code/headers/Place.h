#ifndef FEUP_DA_PROJ2_PLACE_H
#define FEUP_DA_PROJ2_PLACE_H

#include <string>

class Place {
public:
    Place(int id, std::string name);

    std::string getName() const;
    int getID() const;
    bool operator==(const Place& p) const;
    bool operator!=(const Place& p) const;
private:
    std::string name_;
    int id_;
};


#endif //FEUP_DA_PROJ2_PLACE_H
