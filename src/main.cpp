#include "Phone.h"
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include "lambdas.cpp"

union one4all
{
    int int_val;
    long long_val;
    double double_val;
};

enum week_day
{
    mon,
    tue,
    wed,
    thu,
    fri,
    sat,
    sun
};

struct Person
{
    std::string name;
    int age;
};

void swap(int &a, int &b);
double double_it(const double &a);
Person create_profile(std::string name, int age);
void show_profile(const Person &person);
Person &reduce_age(Person &person);

int main()
{

    auto flat_map =
        [data = std::vector<std::pair<int, int>>()](int input_key) mutable -> auto &
    {
        for (auto &[key, value] : data)
        {
            if (key == input_key)
            {
                return value;
            }
        }

        return data.emplace_back(input_key, 0).second;
    };

    flat_map(1) = 45;

    std::cout << flat_map(1) << std::endl;

    using namespace std;
    int x = 5;
    int y = x++;
    int &z = x;
    cout << z << " - " << y << endl;
    swap(x, y);

    cout << x << " - " << y << endl;
    cout << double_it(2.5) << endl;

    Person employee = create_profile("thierno", 35);
    show_profile(employee);

    Person young_empl = reduce_age(employee);
    show_profile(young_empl);
    cout << "===============================\n";

    Phone iphone{"15 pro", 1000.99};
    Phone samsung{"S24 ultra", 999.99};
    Phone nokia{"3X pro", 2015.9};
    Phone expensive_phone = iphone > samsung > nokia;
    expensive_phone.display_phone();
    return 0;
}

Person create_profile(std::string name, int age)
{
    Person empl;
    empl.name = name;
    empl.age = age;
    return empl;
}

Person &reduce_age(Person &person)
{
    person.age = 25;
    return person;
}

void show_profile(const Person &person)
{
    std::cout << person.name << std::endl;
    std::cout << person.age << std::endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

double double_it(const double &a)
{
    return 2 * a;
}