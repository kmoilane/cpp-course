#include "includes/utils.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <string>

int main(int argc, char* argv[])
{
    if (argc < 4 || argc > 4)
    {
        print_help();
        return 0;
    }
    std::string operation {static_cast<std::string>(argv[1])};
    if (operation == "--sum")
        print_sum(atoi(argv[2]), atoi(argv[3]));
    else if(operation == "--substract")
        print_substraction(atoi(argv[2]), atoi(argv[3]));
    else if(operation == "--multiply")
        print_multiplication(atoi(argv[2]), atoi(argv[3]));
    else if(operation == "--divide")
        print_division(atoi(argv[2]), atoi(argv[3]));
    else if(operation == "--encrypt")
        encrypt(static_cast<std::string>(argv[2]), atoi(argv[3]));
    else if(operation == "--decrypt")
        decrypt(static_cast<std::string>(argv[2]), atoi(argv[3]));

    return 0;
}
