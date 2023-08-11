#include "../includes/utils.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <random>
#include "../includes/weather.h"

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

int get_int_input()
{
    while (true)
    {
        int option {};
        std::cin >> option;
        if (!std::cin)
        {
            clear_cin();
            continue ;
        }
        return option;
    }
}

bool validate_user_option(int option, int min, int max)
{
    if (option >= min && option <= max)
        return true;
    return false;
}

Ymd get_current_date_ymd()
{
    const std::chrono::time_point now{std::chrono::system_clock::now()};
    const std::chrono::year_month_day ymd{std::chrono::floor<std::chrono::days>(now)};
    Ymd date {
        static_cast<int>(ymd.year()),
        static_cast<int>(static_cast<unsigned>(ymd.month())),
        static_cast<int>(static_cast<unsigned>(ymd.day()))
    };
    return date;
}

bool date_is_older(Ymd date1, Ymd date2)
{
    if (date1.year < date2.year)
        return true;
    else if (date1.year > date2.year)
        return false;

    if (date1.month < date2.month)
        return true;
    else if (date1.month > date2.month)
        return false;

    if (date1.day < date2.day)
        return true;
    else if (date1.day > date2.day)
        return false;
    
    return false;
}

bool date_is_equal(Ymd date1, Ymd date2)
{
    return(
        date1.day == date2.day &&
        date1.month == date2.month &&
        date1.year == date2.year)
        ? true : false;
}
