#include <fstream>
#include <iostream>
#include <string>

int print_file_line_count(const std::string& file_name)
{
    std::ifstream file(file_name);

    if (!file.is_open())
        return 1;
    std::string line {};
    int count { 0 };
    while (getline(file, line))
        ++count;

    file.close();
    std::cout << "File \"" << file_name << "\" has " << count << " lines.\n";
    return 0;
}
