#include "includes/entity.hpp"
#include <iostream>

/*
**  This program tests my tagged union class Entity which is declared in
**  entity.h file and defined/implemented in entity.cpp file.
*/
int main()
{
    Entity entity = Entity::create("55");

    entity.set_union('K');
    std::cout << entity;

    entity.set_union(999);
    std::cout << entity;

    entity.set_union(660.545);
    std::cout << entity;

    std::cout << entity;
    std::cout << Entity::create("69");
    std::cout << Entity::create("69.420");
    std::cout << Entity::create("HiThere420");

    // Assert fails here!
    char ch = entity.get_letter();

    return 0;
}
