#include "../headers/Place.h"

Place::Place(int id, std::string name) : name_(name), id_(id) {}

std::string Place::getName() const {
    return name_;
}

int Place::getID() const {
    return id_;
}

bool Place::operator==(const Place& p) const {
    return name_ == p.name_;
}

bool Place::operator!=(const Place& p) const {
    return name_ != p.name_;
}