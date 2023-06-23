#include <fstream>
#include <iostream>
#include <string>

int print_file_word_count(const std::string& file_name)
{
    std::ifstream file(file_name);

    if (!file.is_open())
        return 1;
    std::string line {};
    int count { 0 };
    while (file >> line)
        ++count;

    file.close();
    std::cout << "File \"" << file_name << "\" has " << count << " words.\n";
    return 0;
}
