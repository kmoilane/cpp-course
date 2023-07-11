#include "includes/generate_data.h"
#include "includes/utils.h"
#include "includes/weather.h"
#include <chrono>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

Weather get_prev_reading(std::string file_path)
{
    std::ifstream   file(file_path);
    fs::path        log_file(file_path);
    Weather         prev_reading {};

    if (!fs::exists(log_file))
        return prev_reading;
    
    if (!file.is_open())
        return prev_reading;

    std::string         prev_line { get_last_line(file) };
    std::istringstream  iss(prev_line);
    std::string day {};
    std::string month {};
    std::string year {};
    std::string season {};
    std::string temp {};
    std::string press {};
    std::string hum {};
    std::string wind {};
    getline(iss, day, '.');
    prev_reading.date.day = std::stoi(day);
    getline(iss, month, '.');
    prev_reading.date.month = std::stoi(month);
    getline(iss, year, ',');
    prev_reading.date.year = std::stoi(year);
    getline(iss, season, ',');
    prev_reading.season = std::stoi(season);
    getline(iss, temp, ',');
    prev_reading.temperature = std::stoi(temp);
    getline(iss, press, ',');
    prev_reading.pressure = std::stoi(press);
    getline(iss, hum, ',');
    prev_reading.humidity = std::stoi(hum);
    getline(iss, wind);
    prev_reading.wind_speed = std::stoi(wind);

    return prev_reading;
}

void print_current_weather()
{
    const std::chrono::time_point now{std::chrono::system_clock::now()};
    const std::chrono::year_month_day ymd{std::chrono::floor<std::chrono::days>(now)};
    Ymd date {
        static_cast<int>(ymd.year()), static_cast<unsigned>(ymd.month()), static_cast<unsigned>(ymd.day())};
    Weather curr_weather {};
    curr_weather.date = date;
    curr_weather.date.day;
    std::vector<Weather> data { generate_weather(1, curr_weather)};
    
    for (auto weather : data)
    {
        std::cout << "Date: " << weather.date.day << '.' << weather.date.month << '.' << weather.date.year << '\n';
        std::cout << "Temperature: " << weather.temperature << '\n';
        std::cout << "Pressure: " << weather.pressure << '\n';
        std::cout << "Humidity: " << weather.humidity << '\n';
        std::cout << "Wind speed: " << weather.wind_speed << '\n';
    }
}

int main()
{
    std::string             file_path { "../logs/weather_log" };
    Weather                 prev_reading { get_prev_reading(file_path) };
    if (prev_reading.date.day == INT_MIN)
        prev_reading.date = {1997,7,1};
    std::vector<Weather>    weather_data { generate_weather(365, prev_reading) };

    fs::path                log_file(file_path);
    std::ofstream           file;
    bool                    file_exists = false;

    print_current_weather();
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
