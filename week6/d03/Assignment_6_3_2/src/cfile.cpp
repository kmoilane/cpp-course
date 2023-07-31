#include "../includes/cfile.hpp"
#include <cstdio>
#include <cstdlib>
#include <string>
#include <stdexcept>

CFile::CFile(std::string filename)
{
    file_name = filename;
    file_handle = fopen(filename.c_str(), open_mode.c_str());
    int symbol;
    while ((symbol = fgetc(file_handle)) != EOF)
    {
        file_size++;
    }
    rewind(file_handle);
}

bool CFile::is_valid_mode(std::string mode)
{
    if (mode == "r" || mode == "w" || mode == "a"
        || mode == "r+" || mode == "w+" || mode == "a+")
        return true;
    return false;
}

CFile::CFile(std::string filename, std::string mode)
{
    file_name = filename;
    if (!is_valid_mode(mode))
        throw std::invalid_argument("Invalid mode for opening the file");
    file_handle = fopen(filename.c_str(), mode.c_str());
    if (!file_handle)
        throw std::runtime_error("Failed to open a file");
    int symbol;
    while ((symbol = fgetc(file_handle)) != EOF)
    {
        file_size++;
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
    while ((symbol = std::fgetc(file_handle)) != EOF && symbol != '\n')
    {
        line.push_back(static_cast<char>(symbol));
    }
    return line;
}

size_t CFile::size()
{
    return file_size;
}
