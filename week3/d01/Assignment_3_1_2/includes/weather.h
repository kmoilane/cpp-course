#ifndef WEATHER_H
#define WEATHER_H

#include <chrono>
#include <iostream>

constexpr int WINTER = 1;   // December - February
constexpr int SPRING = 2;   // March - May
constexpr int SUMMER = 3;   // June - August
constexpr int AUTUMN = 4;   // September - October

constexpr std::pair<double, double> WINTER_TEMP_RANGE { -60, 5 };
constexpr std::pair<double, double> SPRING_TEMP_RANGE { -20, 30 };
constexpr std::pair<double, double> SUMMER_TEMP_RANGE { 10, 40 };
constexpr std::pair<double, double> AUTUMN_TEMP_RANGE { -5, 35 };

constexpr std::pair<double, double> PRESSURE_RANGE { 930, 1070 };
constexpr std::pair<int, int>       HUMIDITY_RANGE { 0, 100 };
constexpr std::pair<int, int>       WIND_RANGE { 0, 222 };

struct Ymd
{
    int year {};
    int month {};
    int day {};
};

struct Weather
{
    double  temperature {}; // In celsius
    double  pressure {};    // Atmospheric pressure in hPa
    int     humidity {};    // 0%-100%
    int     wind_speed {};  // m/s
    int     season { 0 };   // 1-4
    Ymd     date {};        // Date in year mont day format
};

#endif
