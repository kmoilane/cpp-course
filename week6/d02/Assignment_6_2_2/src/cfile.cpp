#include "../includes/cfile.hpp"
#include <cstdio>
#include <cstdlib>
#include <string>

CFile::CFile(std::string filename)
{
    file_name = filename;
    file_handle = fopen(filename.c_str(), "r");
    int symbol;
    while ((symbol = fgetc(file_handle)) != EOF)
    {
        file_size += 1;
    }
    rewind(file_handle);
}

CFile::~CFile()
{
    fclose(file_handle);
}

std::string CFile::name()
{
    return file_name;
}

std::string CFile::next_line()
{
    int symbol;
    std::string line;
    while ((symbol = std::fgetc(file_handle)) != EOF)
    {
        char c = static_cast<char>(symbol);
        if (c == '\n')
            break;
        line.push_back(c);
    }
    return line;
}

size_t CFile::size()
{
    return file_size;
}
