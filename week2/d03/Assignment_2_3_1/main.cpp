#include "includes/exercises.h"
#include <algorithm>
#include <iostream>

void print_int_vect(std::vector<int>& vect)
{
    for (auto i : vect)
    {
        std::cout << i;
        if (i != vect.back())
            std::cout << ", ";
    }
    std::cout << '\n';
}

void print_double_vect(std::vector<double>& vect)
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
    ex2_main();
    ex3_main();
    ex4_main();
    ex5_main();
    ex7_main();
    ex8_main();

    return 0;
}
