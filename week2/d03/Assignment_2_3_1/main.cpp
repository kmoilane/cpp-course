#include "includes/exercises.h"
#include <algorithm>
#include <iostream>

void print_vect(std::vector<int>& vect)
{
    for (auto i : vect)
    {
        std::cout << i;
        if (i != vect.back())
            std::cout << ", ";
    }
    std::cout << '\n';
}

int main()
{
    ex1_main();


    return 0;
}
