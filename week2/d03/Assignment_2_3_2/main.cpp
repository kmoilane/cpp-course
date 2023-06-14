#include "includes/ingestion.h"
#include "includes/sensor_data_struct.h"
#include "includes/sensor_readings.h"
#include "includes/utils.h"
#include <iostream>
#include <iomanip>
#include <vector>

/*
**  Loops thorugh given data set and prints everything int the format of:
**  [sensor_id, hh:mm, value], where hh:mm time in hours and minutes, and value
**  sensor reading value
*/
void print_all_data(const std::vector<Sensor_data>& data)
{
    int i { 1 };
    for (auto reading : data)
    {
        std::cout.precision(2);
        std::cout << '[' << reading.id << ", "
            << std::setfill('0') << std::setw(2) << reading.time.first
            << ':'
            << std::setfill('0') << std::setw(2) << reading.time.second
            << ", " << std::setfill(' ') << std::setw(5) << reading.value << "] ";
        if (i % 5 == 0)
            std::cout << '\n';
        ++i;
    }
    std::cout << '\n';
}

int main()
{
    std::vector<Sensor_data> data {};

    generate_readings(data);

    std::cout << "Random generated  readings:\n";
    print_all_data(data);

    std::string id { "sensor_3" };

    std::vector<Sensor_data> filtered_data { filter_by_id(data, id)};

    std::cout << "\nFiltered data with " << id << ":\n";
    print_all_data(filtered_data);

    sort_filtered_data_by_time(filtered_data);
    std::cout << "\nTime sorted data from " << id << ":\n";
    print_all_data(filtered_data);

    std::cout << "\nDetected outliers from " << id << ":\n";
    std::vector<Sensor_data> outliers { detect_outliers(filtered_data, outlier_val)};
    print_all_data(outliers);

    std::string most_freq = most_frequent_sensor(data);
    std::cout << "\nMost frequent sensor readings come from: " << most_freq << '\n';
    return 0;
}
