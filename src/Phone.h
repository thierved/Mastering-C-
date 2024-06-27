#ifndef _PHONE_H
#define _PHONE_H
#include <string>

class Phone
{
private:
    std::string name{};
    double price {};
public:
    Phone(std::string name, double price);  
    Phone(const Phone &source);  
    void set_name(std::string n_name);
    void display_phone();
    Phone operator>(const Phone& phone) const;
};


#endif