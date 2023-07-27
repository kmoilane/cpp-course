#include "includes/ex1.hpp"
#include <iostream>

int main()
{
    Lion lion;
    Dog dog;
    std::cout << "Lion says: " << lion.make_sound() << '\n';
    std::cout << "Dog says: " << dog.make_sound() << '\n';

    return 0;
}
