#include "includes/animal.hpp"
#include "includes/cfile.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>

int main()
{
    CFile file("animals");
    std::string line = file.next_line();

    while (!line.empty())
    {
        std::istringstream iss(line);
        std::string specie {};
        std::string name {};
        std::getline(iss, specie, ',');
        std::getline(iss, name, '\n');
        if (specie == "Dog")
        {
            Animal::add_animal(Dog{name});
        }
        else if (specie == "Lion")
        {
            Animal::add_animal(Lion{name});
        }
        else if (specie == "Alligator")
        {
            Animal::add_animal(Alligator{name});
        }
        else
        {
            Animal::add_animal(Animal{name});
        }
        line = file.next_line();
    }

    Animal::print_animals();
    return 0;
}
