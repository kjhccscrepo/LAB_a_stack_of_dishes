#pragma once
#include <string>
class Dish {
private:
    std::string my_description;
public:
    Dish(std::string description) {
        this->my_description = description;
    }
    Dish() {
        this->my_description = "a null dish";
    }
    std::string get_description() {
        return this->my_description;
    }
};
