#include "../includes/utils.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <random>

int random_int(int a, int b)
{
    std::random_device rd{};
    std::seed_seq ss{
        static_cast<std::seed_seq::result_type>
        (std::chrono::steady_clock::now().time_since_epoch().count()),
        rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937 mt {ss};
    std::uniform_int_distribution distr{a, b};
    return distr(mt);
}

double random_float(double a, double b)
{
    std::random_device rd{};
    std::seed_seq ss{
        static_cast<std::seed_seq::result_type>
        (std::chrono::steady_clock::now().time_since_epoch().count()),
        rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937 mt {ss};
    std::uniform_real_distribution distr{a, b};
    return distr(mt);
}

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string get_last_line(std::ifstream& file_input)
{
    std::string line;
    while (file_input >> std::ws && std::getline(file_input, line))
        ;
    return line;
}
