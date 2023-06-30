#include <iostream>

int factorial(int num)
{
    return (num > 1) ? num * factorial(num - 1) : 1;
}

void pascals_triangle(int num)
{
    for (int i = 0; i < num; ++i)
    {
        for (int space = 1; space <= (num - i); ++space)
            std::cout << ' ';
        for(int j = 0; j <= i; ++j)
        {
            std::cout << factorial(i) / (factorial(i - j) * factorial(j)) << ' ';
        }
        std::cout << '\n';
    }
}
