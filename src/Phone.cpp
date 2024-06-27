#include "Phone.h"
#include <iostream>


inline Phone::Phone(std::string name, double price) : name{name}, price{price} {}

inline Phone::Phone(const Phone &source) : Phone::Phone(source.name, source.price) {
    std::cout << "called copy ctur!" << std::endl;
}

void Phone::set_name(std::string n_name) {
    name = n_name;
}

 void Phone::display_phone()
{
    std::cout << name << std::endl;
    std::cout << price << std::endl;
}

Phone Phone::operator>(const Phone& phone) const {
    return (this-> price  < phone.price) ? phone : *this;
}