#include "includes/animal.hpp"
#include <iostream>
#include <vector>
#include <memory>

void animal_info(const Animal& good_boy)
{
    std::cout << std::boolalpha;
    std::cout << "I'm " << good_boy.what() << '\n';
    std::cout << good_boy.what() << " says " << good_boy.make_sound() << '\n';
    std::cout << "Safe to pet? " << good_boy.safe_to_pet() << '\n';
    std::cout << "Has fur? " << good_boy.has_fur() << '\n';
    std::cout << "Has scales? " << good_boy.has_scales() << '\n';
    std::cout << "Animal class: " << good_boy.animal_class() << '\n';
    std::cout << "Latin name: " << good_boy.latin_name() << '\n';
}

int main()
{
    Lion lion;
    Dog dog;
    Alligator al;
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Lion>());
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Alligator>());
    
    for (const auto& animal : animals)
    {
        animal_info(*animal);
        std::cout << '\n';
    }

    return 0;
}
