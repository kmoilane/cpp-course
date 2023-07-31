#include "includes/cfile.hpp"
#include <iostream>

int main()
{
    CFile file {"test_file", "r"};
    std::string line = file.next_line();
    while (!line.empty())
    {
        std::cout << line << '\n';
        line = file.next_line();
    }
    std::cout << file.name() << " is " << file.size() << " bytes\n";
    return 0;
}
