#include "includes/generate_data.h"
#include "includes/utils.h"
#include "includes/weather.h"
#include <iostream>
#include <filesystem>
#include <fstream>

int main()
{
    Ymd                     start_date { 1997, 8, 10 };
    std::vector<Weather>    weather_data { generate_weather(30, start_date) };
    std::string             file_path {"../logs/weather_log"};
    fs::path                log_file(file_path);
    std::ofstream           file;
    bool                    file_exists = false;

    if (fs::exists(log_file))
        file_exists = true;

    file.open(file_path, std::fstream::out | std::fstream::app);
    if (!file)
    {
        std::cout << "Error opening the file\n";
        return 1;
    }
    if (!file_exists)
        file << "Date, Season, Temperature, Pressure, Humidity, Wind speed\n";

    for (auto data : weather_data)
    {
        file << data.date.day << '.' << data.date.month << '.' << data.date.year << ',';
        file << data.season << ',';
        file << data.temperature << ',';
        file << data.pressure << ',';
        file << data.humidity << ',';
        file << data.wind_speed << '\n';
    }
    file.close();

    return 0;
}
