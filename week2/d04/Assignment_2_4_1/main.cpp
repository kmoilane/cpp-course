#include "includes/dir_size.h"
#include "includes/print_file.h"
#include "includes/char_count.h"
#include "includes/line_count.h"
#include "includes/word_count.h"
#include "externals/cxxopts/include/cxxopts.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    cxxopts::Options options("fileguy", "I read files.");
    cxxopts::value<std::string>()->default_value("help");
    cxxopts::value<std::string>()->implicit_value("help");
    options.add_options()
        ("f,file", "Print content of a file", cxxopts::value<std::string>())
        ("l,lines", "Print line count of a file", cxxopts::value<std::string>())
        ("w,words", "Print word count of a file", cxxopts::value<std::string>())
        ("c,chars", "Print character count of a file", cxxopts::value<std::string>())
        ("s,size", "Print size of the text files in the given directory",
            cxxopts::value<std::string>())
        ("a,add", "Add two numbers together", cxxopts::value<std::vector<double>>())
        ("h,help", "Print usage")
    ;

    auto result = options.parse(argc, argv);
    if (result.count("help"))
    {
        std::cout << options.help() << '\n';
        return 0;
    }
    else if (result.count("file"))
    {
        if (print_file(result["file"].as<std::string>()) == 1)
            std::cout << "File doesn't exist or can't be opened!\n";
    }
    else if (result.count("lines"))
    {
        if (print_file_line_count(result["lines"].as<std::string>()) == 1)
            std::cout << "File doesn't exist or can't be opened!\n";
    }
    else if (result.count("words"))
    {
        if (print_file_word_count(result["words"].as<std::string>()) == 1)
            std::cout << "File doesn't exist or can't be opened!\n";
    }
    else if (result.count("chars"))
    {
        if (print_file_char_count(result["chars"].as<std::string>()) == 1)
            std::cout << "File doesn't exist or can't be opened!\n";
    }
    else if (result.count("size"))
    {
        if (print_dir_byte_size(result["size"].as<std::string>()) == 1)
            std::cout << "Directory doesn't exist or can't be opened!\n";
    }
    else
        std::cout << options.help() << '\n';

    return 0;
}
