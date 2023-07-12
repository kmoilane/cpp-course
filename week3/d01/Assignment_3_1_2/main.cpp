#include "includes/generate_data.h"
#include "includes/utils.h"
#include "includes/weather.h"
#include <chrono>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

/*
**  Creates and returns a weather reading from given log_file line
*/
Weather log_line_to_reading(std::string& line)
{
    Weather reading {};
    std::istringstream  iss(line);
    std::string         day {};
    std::string         month {};
    std::string         year {};
    std::string         season {};
    std::string         temp {};
    std::string         press {};
    std::string         hum {};
    std::string         wind {};

    getline(iss, day, '.');
    reading.date.day = std::stoi(day);
    getline(iss, month, '.');
    reading.date.month = std::stoi(month);
    getline(iss, year, ',');
    reading.date.year = std::stoi(year);
    getline(iss, season, ',');
    reading.season = std::stoi(season);
    getline(iss, temp, ',');
    reading.temperature = std::stoi(temp);
    getline(iss, press, ',');
    reading.pressure = std::stoi(press);
    getline(iss, hum, ',');
    reading.humidity = std::stoi(hum);
    getline(iss, wind);
    reading.wind_speed = std::stoi(wind);

    return reading;
}

/*
**  Gets the latest weather reading from the logs file, assigns the values to
**  Weather object and returns it.
*/
Weather get_prev_reading()
{
    std::ifstream   file(FILE_PATH);
    fs::path        log_file(FILE_PATH);
    Weather         prev_reading {};

    if (!fs::exists(log_file))
        return prev_reading;
    
    if (!file.is_open())
        return prev_reading;

    std::string         prev_line { get_last_line(file) };  
    prev_reading = log_line_to_reading(prev_line);

    return prev_reading;
}

/*
**  Goes through log file and tries to find a matching date. If found, returns
**  the reading of that day, else returns empty weather reading.
*/
Weather find_reading(Ymd& date)
{
    Weather reading {};
    std::ifstream   file(FILE_PATH);
    fs::path        log_file(FILE_PATH);

    if (!fs::exists(log_file))
        return reading;
    
    if (!file.is_open())
        return reading;

    std::string line {};
    int count = 0;
    while (file >> std::ws && std::getline(file, line))
    {
        if (count == 0)
        {
            count++;
            continue ;
        }
        std::string day {};
        std::string month {};
        std::string year {};
        std::istringstream iss(line);
        std::getline(iss, day, '.');
        std::getline(iss, month, '.');
        std::getline(iss, year, '.');

        if (date.day == std::stoi(day)
        && date.month == std::stoi(month)
        && date.year == std::stoi(year))
        {
            reading = log_line_to_reading(line);
            return reading;
        }
    }
    return reading;
}

/*
**  Prints the given weather reading
*/
void print_weather(Weather& weather)
{
    std::cout << "Date: " << weather.date.day << '.' << weather.date.month
        << '.' << weather.date.year << '\n';
    std::cout << "Temperature: " << weather.temperature << '\n';
    std::cout << "Atmospheric pressure: " << weather.pressure << '\n';
    std::cout << "Air humidity: " << weather.humidity << '\n';
    std::cout << "Wind speed: " << weather.wind_speed << "\n\n";
}

/*
**  Get's the current date and generates random, season specific weather for
**  today. Then calls a function to print it.
*/
void current_weather()
{
    Ymd date = get_current_date_ymd();
    Weather curr_weather { find_reading(date) };
    if (curr_weather.pressure != INT_MIN)
    {
        print_weather(curr_weather);
        return ;
    }

    curr_weather.date = date;
    std::vector<Weather> data { generate_weather(1, curr_weather) };
    if (log_weather_readings(data) == 1)
        std::cout << "Error logging the current weather reading\n";
    print_weather(data[0]);
    return ;
}

void print_ui_menu()
{
    std::cout << "\nWeather Station\n\n";
    std::cout << "1) Show current weather\n";
    std::cout << "2) Show weather logs\n";
    std::cout << "3) Exit\n\n";
}

/*
**  Reads the weather data from the log file and prints it to the console.
*/
void print_logs()
{
    std::ifstream file(FILE_PATH);

    if (!file)
    {
        std::cout << "Error opening a log file\n";
        return ;
    }
    
    std::string line {};
    int count = 0;
    while (std::getline(file, line))
    {
        if (count == 0){
            count++;
            continue ;
        }
        std::istringstream iss (line);
        std::string day {};
        std::getline(iss, day, '.');
        std::string month {};
        std::getline(iss, month, '.');
        std::string year {};
        std::getline(iss, year, ',');
        std::string season {};
        std::getline(iss, season, ',');
        std::string temp {};
        std::getline(iss, temp, ',');
        std::string press {};
        std::getline(iss, press, ',');
        std::string hum {};
        std::getline(iss, hum, ',');
        std::string wind {};
        std::getline(iss, wind);

        Weather weather
        {
            weather.temperature = std::stoi(temp),
            weather.pressure = std::stoi(press),
            weather.humidity = std::stoi(hum),
            weather.wind_speed = std::stoi(wind),
            weather.season = std::stoi(season),
            {
                weather.date.year = std::stoi(year),
                weather.date.month = std::stoi(month),
                weather.date.day =std::stoi(day)
            }
        };
        print_weather(weather);
    }
}

int ui_loop()
{
    while (true)
    {
        print_ui_menu();
        int option { get_int_input() };
        if (validate_user_option(option, 1, 3))
        {
            switch(option)
            {
                case 1:
                {
                    current_weather();
                    continue ;
                }
                case 2:
                {
                    print_logs();
                    continue ;
                }
                case 3:
                {
                    return 0;
                }
            }
        }
    }
}

/*
**  Writes the weather_data to weather_log file in the logs/ directory.
**  If the file exists, appends to the end of the file.
*/
int log_weather_readings(std::vector<Weather>& weather_data)
{
    fs::path                log_file(FILE_PATH);
    std::ofstream           file;
    bool                    file_exists = false;
    if (fs::exists(log_file))
        file_exists = true;

    file.open(FILE_PATH, std::fstream::app);
    if (!file)
        return ERROR_CODE;
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

/*
**  Generates some data to the file, unless log_file has a reading for current
**  date.
*/
int main()
{
    Weather prev_reading { get_prev_reading() };

    if (prev_reading.date.day == INT_MIN)
        prev_reading.date = { 2020,1,1 };

    std::vector<Weather> weather_data { generate_weather(30, prev_reading) };

    // This prevents duplicates for the current day when program is rerun
    if (weather_data.empty() || weather_data.size() == 1)
        ;
    else if (log_weather_readings(weather_data))
        std::cout << "Error opening the file, log not created\n";

    while (true)
    {
        if (ui_loop() == 0)
            break ;
    }

    return 0;
}
