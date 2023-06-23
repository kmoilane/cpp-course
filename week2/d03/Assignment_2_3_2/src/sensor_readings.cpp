#include "../includes/sensor_data_struct.h"
#include "../includes/sensor_readings.h"
#include "../includes/utils.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>


/*
**  Finds and returns a vector of Sensor_data based on the given id.
*/
std::vector<Sensor_data> filter_by_id(std::vector<Sensor_data>& data, std::string id)
{
    std::vector<Sensor_data> filtered {};
    for (auto reading : data)
    {
        if (reading.id == id)
        {
            filtered.push_back(reading);
        }
    }
    return filtered;
}

/*
**  Compares two times, first is hours, second is minutes
*/
bool compare_by_time(const Sensor_data& a, const Sensor_data& b)
{
    if (a.time.first != b.time.first)
        return a.time.first < b.time.first;
    return a.time.second < b.time.second;
}


/*
**  Sorts given data by time in ascending order. 
*/
void sort_filtered_data_by_time(std::vector<Sensor_data>& data)
{
    std::sort(data.begin(), data.end(), compare_by_time);
}

/*
**  Returns value vector of Sensor_data that has all the detected outliers.
**  Outliers are those readings that has value higher than fixed outlier_val,
**  (which is as const in sensor_data_struct.h) - mean value of all the readings
*/
std::vector<Sensor_data> detect_outliers(std::vector<Sensor_data>& data, float val)
{
    std::vector<Sensor_data> outliers {};
    float mean {};
    for (auto reading : data)
    {
        mean += reading.value;
    }
    mean = mean / static_cast<float>(data.size());
    for (auto reading : data)
    {
        if (reading.value > mean + val || reading.value < mean - val)
            outliers.push_back(reading);
    }

    return outliers;
}

/*
**  Creates an unordered map with sensor_id's and counts for how many times
**  each sensor is in the data vector. Then it finds the max value from the
**  unordered map counter. Returns the sensor_id as a string.
*/
std::string most_frequent_sensor(std::vector<Sensor_data>& data)
{
    std::unordered_map<std::string, int> counter {{"", 0}};
    for (auto reading : data)
    {
        if (counter.find(reading.id) != counter.end())
        {
            counter.at(reading.id)++;
        }
        else
            counter[reading.id] = 1;
    }
    std::unordered_map<std::string, int>::iterator it =
        std::max_element(counter.begin(), counter.end(),
        [](const std::pair<std::string, int> &a,
        const std::pair<std::string, int> &b)
        {
            return a.second < b.second;
        });
    return it->first;
}
