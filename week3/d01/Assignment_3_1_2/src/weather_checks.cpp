#include "../includes/weather.h"

/*
**  Check that wind is in "somewhat realistic" range :D
*/
int check_wind(int wind)
{
    if (wind < 0)
        return ERROR_CODE;
    else if (wind > 113)
        return ERROR_CODE;
    return 0;
}

/*
**  Check that the humidity is in realistic range
*/
int check_humidity(int humidity)
{
    if (humidity > HUMIDITY_RANGE.second)
        return ERROR_CODE;
    else if (humidity < HUMIDITY_RANGE.first)
        return ERROR_CODE;
    return 0;
}

/*
**  Check that temperature is in realistic range
*/
int check_temperature(int temperature)
{
    if (temperature < ABSOLUTE_ZERO)
        return ERROR_CODE;
    else if (temperature > HIGHEST_MEASURED_TEMP)
        return ERROR_CODE;
    return 0;
}

/*
** Check that atmospheric pressure is between world record range
*/
int check_pressure(int pressure)
{
    if (pressure < LOWEST_MEASURED_PRESSURE || pressure > HIGHEST_MEASURED_PRESSURE)
        return ERROR_CODE;
    return 0;
}

/*
**  Check that the weather is in the range of the current season
*/
bool check_seasonal_temp(int temp, int season)
{
    if (season == WINTER)
    {
        if (temp >= WINTER_TEMP_RANGE.first && temp <= WINTER_TEMP_RANGE.second)
            return true;
        return false;
    }
    else if (season == SPRING)
    {
        if (temp >= SPRING_TEMP_RANGE.first && temp <= SPRING_TEMP_RANGE.second)
            return true;
        return false;
    }
    else if (season == SUMMER)
    {
        if (temp >= SUMMER_TEMP_RANGE.first && temp <= SUMMER_TEMP_RANGE.second)
            return true;
        return false;
    }
    else if (season == AUTUMN)
    {
        if (temp >= AUTUMN_TEMP_RANGE.first && temp <= AUTUMN_TEMP_RANGE.second)
            return true;
        return false;
    }
    return false;
}

