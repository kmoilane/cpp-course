#include "../includes/ingestion.h"
#include "../includes/sensor_data_struct.h"
#include "../includes/utils.h"
#include <iostream>
#include <string>
#include <vector>


/*
**  Generates ~300 somewhat random readings with id's between sensor_1
**  and sensor_9. It attempts to make some values a bit higher for outliers
*/
void generate_readings(std::vector<Sensor_data>& data)
{
    for (int i = 1; i <= 100; ++i)
    {
        for (int j = random_num(1, 9), max = j; j < max + 3; ++j)
        {
            Sensor_data reading {};
            reading.id = "sensor_" + std::to_string(max);
            reading.time.first = random_num(0, 23);
            reading.time.second= random_num(0, 59);
            if (i % 30 == 0)
                reading.value = static_cast<float>(random_num(-3, 3))
                / 1.275;
            else
                reading.value = static_cast<float>(random_num(-2, 2)) 
                / static_cast<float>(random_num(1, 10));
            data.push_back(reading);
        }
    }
}
