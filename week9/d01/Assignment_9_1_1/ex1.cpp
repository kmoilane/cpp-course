#include <iostream>
#include <vector>
#include <functional>

int sum(int a, int b)
{
    return a + b;
}

int substract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b == 0)
        return 0;
    return a / b;
}

int main(int argc, char* argv[])
{
    std::vector<std::function<int(int, int)>> functions {sum, substract, multiply, divide};

    if (argc != 2)
    {
        std::cout << "This program takes 1 argument.\n";
        return 0;
    }
    std::string arg = argv[1];
    if(arg == "sum")
    {
        std::cout << "21 + 21 = " << functions[0](21, 21) << '\n';
    }
    else if (arg == "substract")
    {
        std::cout << "21 - 21 = " << functions[1](21, 21) << '\n';
    }
    else if (arg == "multiply")
    {
        std::cout << "21 * 21 = " << functions[2](21, 21) << '\n';
    }
    else if (arg == "divide")
    {
        std::cout << "21 / 21 = " << functions[3](21, 21) << '\n';
    }
    else
    {
        std::cout << "Invalid argument! Options are:\n";
        std::cout << "sum\nsubstract\nmultiply\ndivide\n";
    }

    return 0;
}
