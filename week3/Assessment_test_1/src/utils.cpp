#include <iostream>
#include <limits>

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double addition(double a, double b)
{
    return a + b;
}

double substraction(double a, double b)
{
    return a - b;
}

int prompt_int_input()
{
    while (true)
    {
        int input {};
        std::cin >> input;
        if (!std::cin)
        {
            clear_cin();
            std::cout << "\nInvalid input!\n";
            continue ;
        }
        return input;
    }
}

double prompt_double_input()
{
    while (true)
    {
        double input {};
        std::cin >> input;
        if (!std::cin)
        {
            clear_cin();
            std::cout << "\nInvalid input!\n";
            continue ;
        }
        return input;
    }
}

bool validate_int_option(int option, int min, int max)
{
    return (option >= min && option <= max);
}
