#include "includes/status.h"
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

Status generate_random_status()
{
    return static_cast<Status>(random_num(0, STATUS_COUNT - 1));
}

int main()
{
    Status current_status = generate_random_status();

    switch(current_status) {
        case Status::success : {
            std::cout << "Status: success\n";
            break ;
        }
        case Status::error1 : {
            std::cout << "Status: error - not found\n";
            break ;
        }
        case Status::error2 : {
            std::cout << "Status: error - too many requests\n";
            break ;
        }
    }
    return 0;
}
