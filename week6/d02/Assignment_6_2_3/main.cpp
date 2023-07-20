#include "includes/entity.hpp"
#include <iostream>

/*
**  This program tests my first imporved version of tagged union class Entity,
**  which is declared in entity.hpp file and defined/implemented
**  in entity.cpp file.
*/
int main()
{
    Entity entity1 {"Karri"};
    std::cout << "Union type: ";
    entity1.print_union_type();
    if(entity1.current_type() == Tag::human)
        std::cout << " - True!";
    std::cout << "\nUnion value: ";
    entity1.print_union_value();
    std::cout << '\n';

    Entity entity2 {999};
    std::cout << "Union type: ";
    entity2.print_union_type();
    if(entity2.current_type() == Tag::robot)
        std::cout << " - True!";
    std::cout << "\nUnion value: ";
    entity2.print_union_value();
    std::cout << '\n';

    Entity entity3 {660.545};
    std::cout << "Union type: ";
    entity3.print_union_type();
    if(entity3.current_type() == Tag::alien)
        std::cout << " - True!";
    std::cout << "\nUnion value: ";
    entity3.print_union_value();
    std::cout << '\n';

    Entity entity4 {'L'};
    std::cout << "Union type: ";
    entity4.print_union_type();
    if(entity4.current_type() == Tag::human)
        std::cout << " - True!";
    std::cout << "\nUnion value: ";
    entity4.print_union_value();
    std::cout << '\n';

    // Assert fails here!
    char ch = entity3.get_letter();

    return 0;
}
