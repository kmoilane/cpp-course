#ifndef SENSOR_READINGS_H
#define SENSOR_READINGS_H

#include <vector>

std::vector<Sensor_data> filter_by_id(std::vector<Sensor_data>& data, std::string id);
void sort_filtered_data_by_time(std::vector<Sensor_data>& data);
bool compare_by_time(const Sensor_data& a, const Sensor_data& b);
std::vector<Sensor_data> detect_outliers(std::vector<Sensor_data>& data, float val);
std::string most_frequent_sensor(std::vector<Sensor_data>& data);

#endif
