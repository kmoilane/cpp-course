#include "includes/ex2.hpp"
#include <iostream>

int main()
{
    {
        Parrot parrot;
        parrot.whoami();
        parrot.wings.whoami();
        parrot.Bird::whoami();
        parrot.Bird::Animal::whoami();
        Dog dog;
        dog.whoami();
    }
    std::cout << '\n';
    {
        Animal animal;
        animal.whoami();
    }
    std::cout << '\n';
    {
        Bird bird;
        bird.whoami();
    }
    std::cout << '\n';
    {
        Eyes eyes;
        eyes.whoami();
    }
    std::cout << '\n';
    {
        Wings wings;
        wings.whoami();
    }

    return 0;
}
