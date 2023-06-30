#ifndef WEATHER_H
#define WEATHER_H

#include <chrono>
#include <iostream>
#include <climits>

constexpr static int BELOW_POSSIBLE_ERROR = 1;
constexpr static int ABOVE_POSSIBLE_ERROR = 2;
constexpr static int WORLD_RECORD = 3;

constexpr int WINTER = 1;   // December - February
constexpr int SPRING = 2;   // March - May
constexpr int SUMMER = 3;   // June - August
constexpr int AUTUMN = 4;   // September - October

constexpr std::pair<int, int> WINTER_TEMP_RANGE { -50, 5 };
constexpr std::pair<int, int> SPRING_TEMP_RANGE { -25, 25 };
constexpr std::pair<int, int> SUMMER_TEMP_RANGE { 10, 40 };
constexpr std::pair<int, int> AUTUMN_TEMP_RANGE { -25, 20 };

constexpr std::pair<int, int> PRESSURE_RANGE { 995, 1015 };
constexpr std::pair<int, int> HUMIDITY_RANGE { 10, 80 };
constexpr std::pair<int, int> WIND_RANGE { 0, 20 };

constexpr static int ABSOLUTE_ZERO = -273;
constexpr static int HIGHEST_MEASURED_TEMP = 57;
constexpr static int HIGHEST_MEASURED_PRESSURE = 1094;
constexpr static int LOWEST_MEASURED_PRESSURE = 870;

struct Ymd
{
    int year {};
    int month {};
    int day {};
};

struct Weather
{
    constexpr static int init_value = INT_MIN;

    int     temperature {init_value};   // In celsius
    int     pressure {init_value};      // Atmospheric pressure in hPa
    int     humidity {init_value};      // 0%-100%
    int     wind_speed {init_value};    // m/s
    int     season {init_value};        // 1-4
    Ymd     date {};                    // Date in year mont day format
};

int check_wind(int wind);
int check_humidity(int humidity);
int check_temperature(int temperature);
int check_pressure(int pressure);
bool check_seasonal_temp(int temp, int season);

#endif
