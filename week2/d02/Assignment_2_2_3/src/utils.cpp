#include "../includes/board.h"
#include "../includes/player.h"
#include <iostream>
#include <random>
#include <chrono>

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char random_num(int a, int b)
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

void print_options()
{
    std::cout << "\nw) Move up\n";
    std::cout << "a) Move left\n";
    std::cout << "s) Move down\n";
    std::cout << "d) Move right\n";
    std::cout << "q) Quit\n";
}
