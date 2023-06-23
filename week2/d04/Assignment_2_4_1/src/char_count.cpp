#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

int print_file_char_count(const std::string& file_name)
{
    std::ifstream file(file_name);

    if (!file.is_open())
        return 1;
    char c {};
    int count { 0 };
    file >> std::noskipws;
    while (file >> c)
    {
        ++count;
    }

    file.close();
    std::cout << "File \"" << file_name << "\" has " << count << " chars.\n";
    return 0;
}
