#ifndef UTILS_H
#define UTILS_H

#include <filesystem>

namespace fs = std::filesystem;

int random_int(int a, int b);
void clear_cin();
std::string get_last_line(std::ifstream& file_input);

#endif
