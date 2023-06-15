#include <fstream>
#include <filesystem>
#include <iostream>
#include <iomanip>
#include <string>

namespace fs = std::filesystem;

int print_dir_byte_size(const std::string& dir_path)
{
    fs::path dir { dir_path };
    if (dir == "./")
        dir = fs::current_path();
    if (!fs::exists(dir))
        return 1;
    
    int bytes { 0 };
    for (const auto& entry : fs::directory_iterator(dir))
    {
        fs::path entry_path = entry.path();
        if (entry_path.extension() == ".txt")
            bytes += entry.file_size();
    }

    std::cout << "Text files in the directory: " << dir << " are "
    << bytes << " bytes in size.\n";
    return 0;
}
