#include "includes/entity.h"
#include <iostream>

/*
**  This program tests my tagged union class Entity which is declared in
**  entity.h file and defined/implemented in entity.cpp file.
*/
int main()
{
    Entity entity;

    entity.set_union('K');
    std::cout << "Union type: ";
    entity.print_union_type();
    if(entity.current_type() == Tag::human)
        std::cout << " - True!";
    std::cout << "\nUnion value: ";
    entity.print_union_value();
    std::cout << '\n';

    entity.set_union(999);
    std::cout << "Union type: ";
    entity.print_union_type();
    if(entity.current_type() == Tag::robot)
        std::cout << " - True!";
    std::cout << "\nUnion value: ";
    entity.print_union_value();
    std::cout << '\n';

    entity.set_union(660.545);
    std::cout << "Union type: ";
    entity.print_union_type();
    if(entity.current_type() == Tag::alien)
        std::cout << " - True!";
    std::cout << "\nUnion value: ";
    entity.print_union_value();
    std::cout << '\n';

    // Assert fails here!
    char ch = entity.get_letter();

    return 0;
}
