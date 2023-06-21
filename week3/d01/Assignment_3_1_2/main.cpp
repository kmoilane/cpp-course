#include "includes/generate_data.h"
#include "includes/utils.h"
#include "includes/weather.h"
#include <iostream>

int main()
{
    std::vector<Weather> weather_data { generate_weather(10, { 1997, 7, 1 }) };
    for (auto data : weather_data)
    {
        std::cout << "Date: " << data.date.day << '.' << data.date.month
            << '.' << data.date.year << '\n';
        std::cout << "Season: " << data.season << '\n';
        std::cout << "Temperature: " << data.temperature << "C\n\n";
    }
    return 0;
}
