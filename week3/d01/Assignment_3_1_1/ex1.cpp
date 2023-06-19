#include <iostream>
#include <exception>
#include <limits>

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


double divide(double a, double b)
{
    if (b == 0)
        throw std::runtime_error("Division by 0 is not defined!");
    else
        return a / b;
}

double ask_number()
{
    while (true)
    {
        std::cout << "Enter the number: ";
        double a {};
        std::cin >> a;
        if (!std::cin)
            clear_cin();
        else return a;
    }
}

int main()
{
    double result {};
    while (true)
    {
        double a { ask_number() };
        double b { ask_number() };
        try {
            result = divide(a, b);
        }
        catch (std::runtime_error& e) {
            std::cout << "Error: " << e.what() << '\n';
            continue ;
        }
        break ;
    }
    std::cout << "Division result is: " << result << '\n';
    return 0;
}
