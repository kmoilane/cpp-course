#include "includes/utils.h"
#include <iostream>
#include <cassert>
#include <string>

/*
**  Checks if the str is double, returns false if catches exeption
*/
bool is_double(std::string& str)
{
    bool result { true };
    try
    {
        double d = std::stod(str);
    }
    catch(const std::exception& e)
    {
        result = false;
    }
    return result;  
}

/*
**  Checks the string if it is numeric
*/
bool is_int(std::string& val)
{
    std::string::const_iterator it = val.begin();
    while (it != val.end() && std::isdigit(*it))
    {
        ++it;
    }
    return (!val.empty() && it == val.end());
}

/*
**  Goes through options and based on them calls on correct function for
**  asked calculations
*/
void parse_options(char* argv[])
{
    std::string operation {static_cast<std::string>(argv[1])};
    std::string val1 {static_cast<std::string>(argv[2])};
    std::string val2 {static_cast<std::string>(argv[3])};

    if (operation == "--sum")
    {
        assert(is_double(val1) && is_double(val2) && "Invalid arguments!");
        print_sum(std::stod(argv[2]), std::stod(argv[3]));
    }
    else if(operation == "--substract")
    {
        assert(is_double(val1) && is_double(val2) && "Invalid arguments!");
        print_substraction(std::stod(argv[2]), std::stod(argv[3]));
    }
    else if(operation == "--multiply")
    {
        assert(is_double(val1) && is_double(val2) && "Invalid arguments!");
        print_multiplication(std::stod(argv[2]), std::stod(argv[3]));
    }
    else if(operation == "--divide")
    {
        assert(is_double(val1) && is_double(val2) && "Invalid arguments!");
        print_division(std::stod(argv[2]), std::stod(argv[3]));
    }
    else if(operation == "--encrypt")
    {
        assert(is_int(val2) && "Key has to be integer");
        assert(atoi(argv[3]) < 26 && atoi(argv[3]) > 0
            && "Key has to be between 1 and 25 (inclusive)");
        encrypt(static_cast<std::string>(argv[2]), atoi(argv[3]));
    }
    else if(operation == "--decrypt")
    {
        assert(is_int(val2) && "Key has to be integer");
        assert(atoi(argv[3]) < 26 && atoi(argv[3]) > 0
            && "Key has to be between 1 and 25 (inclusive)");
        decrypt(static_cast<std::string>(argv[2]), atoi(argv[3]));
    }
    else
        print_help();
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        print_help();
        return 0;
    }
    parse_options(argv);
    return 0;
}
