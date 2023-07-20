#include "includes/cfile.hpp"
#include "includes/entity.hpp"
#include <iostream>
#include <vector>

int main()
{
    print_entities(read_entities("entity_file"));
    return 0;
}
