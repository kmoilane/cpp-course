#include "../includes/sensor_data_struct.h"
#include "../includes/ingestion.h"
#include "../includes/utils.h"
#include <chrono>
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
