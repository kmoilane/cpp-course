#include "../includes/ingestion.h"
#include "../includes/sensor_data_struct.h"
#include "../includes/utils.h"
#include <iostream>
#include <string>
#include <vector>

void get_sensor_data(std::vector<Sensor_data>& data)
{
    for (int i = 0; i < 100; ++i)
    {
        for (int j = random_num(1, 9); j < 10; ++j)
        {
            Sensor_data reading {};
            reading.id = std::to_string(i);
            reading.time.first = random_num(0, 23);
            reading.time.second= random_num(0, 59);
            reading.value = static_cast<float>(random_num(-2, 2))
            / static_cast<float>(random_num(1, 20));
            data.push_back(reading);
        }
    }
}
