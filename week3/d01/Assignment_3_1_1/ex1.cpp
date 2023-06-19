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

/*
**  Asks user for a number. Keeps asking if user inputs something that will fail
**  std::cin, like characters or max double/min double etc.
*/
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

/*
**  main() calls functiont to ask user for numbers, the tries to divice it.
**  If divider is 0, prints the error message to cout and continues to ask for
**  new numbers. If given proper values, breaks the while loop and prints the
**  result.
*/
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
