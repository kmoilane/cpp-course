#ifndef GENERATE_DATA_H
#define GENERATE_DATA_H

#include "utils.h"
#include "weather.h"
#include <chrono>
#include <vector>
#include <climits>

void generate_temperature(Weather& new_reading, int prev_temp);
void generate_pressure(Weather& new_reading, int prev_pressure);
void generate_humidity(Weather& new_reading, int prev_humidity);
std::vector<Weather> generate_weather(int days, Ymd& date);
void select_season(Weather& reading);
void update_date(Ymd& date);
bool is_leap_year(int year);

#endif
