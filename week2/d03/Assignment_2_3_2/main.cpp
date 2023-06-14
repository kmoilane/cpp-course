#include "includes/ingestion.h"
#include "includes/sensor_data_struct.h"
#include "includes/utils.h"
#include <iostream>
#include <vector>

void print_all_data(const std::vector<Sensor_data>& data)
{
    for (auto reading : data)
    {
        std::cout << '[' << reading.id << ',' << reading.time.first
            << ':' << reading.time.second << ',' << reading.value << ']';
    }
    std::cout << '\n';
}

int main()
{
    std::vector<Sensor_data> data {};

    get_sensor_data(data);

    print_all_data(data);

    return 0;
}
