#include <fstream>
#include <iostream>
#include <string>

int print_file(const std::string& file_name)
{
    std::ifstream file(file_name);

    if (!file.is_open())
        return 1;
    std::string line {};
    while (getline(file, line))
    {
        std::cout << line << '\n';
    }

    file.close();
    return 0;
}
