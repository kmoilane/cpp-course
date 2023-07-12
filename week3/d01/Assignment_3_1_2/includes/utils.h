#ifndef UTILS_H
#define UTILS_H

#include <filesystem>
#include <string>
#include "weather.h"

namespace fs = std::filesystem;
#define FILE_PATH "../logs/weather_log"

int random_int(int a, int b);
void clear_cin();
std::string get_last_line(std::ifstream& file_input);
bool validate_user_option(int option, int min, int max);
int get_int_input();
bool date_is_older(Ymd date1, Ymd date2);
bool date_is_equal(Ymd date1, Ymd date2);

#endif
