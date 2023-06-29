#ifndef WEATHER_H
#define WEATHER_H

#include <chrono>
#include <iostream>
#include <climits>

constexpr int WINTER = 1;   // December - February
constexpr int SPRING = 2;   // March - May
constexpr int SUMMER = 3;   // June - August
constexpr int AUTUMN = 4;   // September - October

constexpr std::pair<int, int> WINTER_TEMP_RANGE { -60, 5 };
constexpr std::pair<int, int> SPRING_TEMP_RANGE { -20, 30 };
constexpr std::pair<int, int> SUMMER_TEMP_RANGE { 10, 40 };
constexpr std::pair<int, int> AUTUMN_TEMP_RANGE { -5, 35 };

constexpr std::pair<int, int> PRESSURE_RANGE { 930, 1070 };
constexpr std::pair<int, int> HUMIDITY_RANGE { 20, 60 };
constexpr std::pair<int, int> WIND_RANGE { 0, 222 };

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

#endif
