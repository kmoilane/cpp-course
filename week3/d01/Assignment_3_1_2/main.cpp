#include "includes/generate_data.h"
#include "includes/utils.h"
#include "includes/weather.h"
#include <iostream>
#include <fstream>

int main()
{
    Ymd start_date { 1997, 7, 1 };
    std::vector<Weather> weather_data { generate_weather(10, start_date) };
    for (auto data : weather_data)
    {
        std::cout << "Date: " << data.date.day << '.' << data.date.month
            << '.' << data.date.year << '\n';
        std::cout << "Season: " << data.season << '\n';
        std::cout << "Temperature: " << data.temperature << "C\n\n";
    }
    return 0;
}
