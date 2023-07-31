#include <chrono>
#include <iostream>
#include <random>

int random_num(int a, int b)
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

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int listen_int_input()
{
    while (true)
    {
        int option {};
        std::cin >> option;
        if (!std::cin)
            clear_cin();
        else
            return option;
    }
}

int validate_int_input(int min, int max)
{
    int option { listen_int_input() };
    if (option >= min && option <= max)
        return option;
    return 0;
}
