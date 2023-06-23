#ifndef SENSOR_DATA_STRUCT_H
#define SENSOR_DATA_STRUCT_H

#include <string>

struct  Sensor_data
{
    std::string         id {};
    std::pair<int,int>  time {};
    float               value{};
};
constexpr static float outlier_val = 1.25;

#endif
