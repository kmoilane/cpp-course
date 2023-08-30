#include "includes/math.hpp"
#include <iostream>
#include <unordered_map>
#include <functional>
#include <type_traits>
#include <limits>

int main(int argc, char* argv[])
{
    std::unordered_map<char, std::function<int(int,int)>> functions{
        {'+', sum}, {'-', substract}, {'*', multiply}, {'/', divide}};
    
    if (argc != 4)
    {
        std::cout << "This program takes 3 arguments!\n";
        std::cout << "For example:\n";
        std::cout << "./calculator 5 \\* 5\n";
        return 1;
    }
    std::string arg1 = argv[1];
    std::string arg3 = argv[3];
    if (!is_int(arg1) || !is_int(arg3))
    {
        std::cout << "First and third parameters have to be integers!\n";
        return 1;
    }
    const char* arg2 = argv[2];
    if (*arg2 == '+' || *arg2 == '-' || *arg2 == '*' || *arg2 == '/')
    {
        std::cout << arg1 << ' ' << arg2 << ' ' << arg3 << " = " <<
         functions[*arg2](std::stoi(arg1), std::stoi(arg3)) << '\n';
    }
    else
    {
        std::cout << "Invalid operation!\nFollowing operations are allowed:\n";
        std::cout << "+, -, \\*, /\n";
    }
    return 0;
}
