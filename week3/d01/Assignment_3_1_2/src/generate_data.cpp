#include "../includes/generate_data.h"
#include "../includes/weather.h"
#include "../includes/utils.h"
#include <chrono>
#include <vector>

bool is_leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}

/*
** Updates the date (year, month day). Takes leap year into account as well.
*/
void update_date(Ymd& date)
{
    if (date.month >= 12 && date.day >= 31)
    {
        date.year++;
        date.month = 1;
        date.day = 1;
    }
    else if ((date.month == 1 || date.month == 3 || date.month == 5
    || date.month == 7 || date.month == 8 || date.month == 10)
    && date.day == 31)
    {
        date.month++;
        date.day = 1;
    }
    else if ((date.month == 3 || date.month == 4 || date.month == 6 || date.month == 9
    || date.month == 11) && date.day == 30)
    {
        date.month++;
        date.day = 1;
    }
    else if (date.month == 2 && date.day == 28)
    {
        if (is_leap_year(date.year))
            date.day++;
        else
        {
            date.day = 1;
            date.month++;
        }
    }
    else if (date.month == 2 && date.day == 29)
    {
        date.month++;
        date.day = 1;
    }
    else
        date.day++;
}

/*
**  Selects season based on the month
*/
void select_season(Weather& reading)
{
    if (reading.date.month == 12 || reading.date.month == 1 || reading.date.month == 2)
        reading.season = WINTER;
    else if (reading.date.month == 3 || reading.date.month == 4 || reading.date.month == 5)
        reading.season = SPRING;
    else if (reading.date.month == 6 || reading.date.month == 7 || reading.date.month == 8)
        reading.season = SUMMER;
    else if (reading.date.month == 9 || reading.date.month == 10 || reading.date.month == 11)
        reading.season = AUTUMN;
}

/*
**  Generates some semi random pressure from the pressure range
**  and previous pressure
*/
void generate_pressure(Weather& new_reading, int prev_pressure)
{
    if (prev_pressure == new_reading.init_value)
    {
        new_reading.pressure =
            random_int(PRESSURE_RANGE.first, PRESSURE_RANGE.second);
        return ;
    }
    int avg_pressue { (PRESSURE_RANGE.first + PRESSURE_RANGE.second) / 2};
    int diff { 10 };
    int min_change { 0 };
    int max_change { 5 };
    if (prev_pressure <= avg_pressue - diff)
        new_reading.pressure = prev_pressure + random_int(min_change, max_change);
    else if (prev_pressure >= avg_pressue + diff)
        new_reading.pressure = prev_pressure - random_int(min_change, max_change);
    else
        new_reading.pressure = prev_pressure + random_int(-max_change, max_change);
}

/*
**  Generates semi random wind from the wind range and previous wind
*/
void generate_wind(Weather& new_reading, int prev_wind)
{
    if (prev_wind == new_reading.init_value)
    {
        new_reading.wind_speed =
            random_int(WIND_RANGE.first, WIND_RANGE.second);
        return ;
    }
 
    int change = 5;
    while (true)
    {
        int wind = random_int(-change, change);
        int check_wind_result = check_wind(prev_wind + wind);
        if (check_wind_result == 0 && prev_wind + wind <= WIND_RANGE.second)
        {
            new_reading.wind_speed = prev_wind + wind;
            return ;
        }
    }
}

/*
**  This function generates weather data by first checking if prev temp is
**  INT_MIN, which means it's first reading. It will then generate temperature
**  randomly, but within the limits of the current seasons TEMP_RANGE.
*/
void generate_temperature(Weather& new_reading, int prev_temp)
{
    if (prev_temp == INT_MIN)
    {
        if (new_reading.season == WINTER)
        {
            new_reading.temperature =
                random_int(WINTER_TEMP_RANGE.first, WINTER_TEMP_RANGE.second);
            return ;
        }
        if (new_reading.season == SPRING)
        {
            new_reading.temperature =
                random_int(SPRING_TEMP_RANGE.first, SPRING_TEMP_RANGE.second);
            return ;
        }
        if (new_reading.season == SUMMER)
        {
            new_reading.temperature =
                random_int(SUMMER_TEMP_RANGE.first, SUMMER_TEMP_RANGE.second);
            return ;
        }
        if (new_reading.season == AUTUMN)
        {
            new_reading.temperature =
                random_int(AUTUMN_TEMP_RANGE.first, AUTUMN_TEMP_RANGE.second);
            return ;
        }
    }

    while (true)
    {
        int change = 10;
        int temp = random_int(-change, change);
        int result = check_temperature(prev_temp + temp);
        if (result == 0 && check_seasonal_temp(prev_temp + temp, new_reading.season))
        {
            new_reading.temperature = prev_temp + temp;
            return ;
        }
        else if (result == 0)
        {
            if (temp < 0)
                temp *= -1;
            if (new_reading.season == WINTER)
                new_reading.temperature = (prev_temp - temp < WINTER_TEMP_RANGE.first) ? (prev_temp + temp) : (prev_temp - temp);
            else if (new_reading.season == SPRING)
                new_reading.temperature = (prev_temp - temp < SPRING_TEMP_RANGE.first) ? (prev_temp + temp) : (prev_temp - temp);
            else if (new_reading.season == SUMMER)
                new_reading.temperature = (prev_temp - temp < SUMMER_TEMP_RANGE.first) ? (prev_temp + temp) : (prev_temp - temp);
            else if (new_reading.season == AUTUMN)
                new_reading.temperature = (prev_temp - temp < AUTUMN_TEMP_RANGE.first) ? (prev_temp + temp) : (prev_temp - temp);
            return ;
        }
    }
}

/*
**  Generates semi random humitidty from the
**  humidity range and previous humidity
*/
void generate_humidity(Weather& new_reading, int prev_humidity)
{
    if (prev_humidity == new_reading.init_value)
    {
        new_reading.humidity =
            random_int(HUMIDITY_RANGE.first, HUMIDITY_RANGE.second);
        return ;
    }
 
    while (true)
    {
        int humidity = random_int(-HUMIDITY_RANGE.second, HUMIDITY_RANGE.second);
        int result = check_humidity(prev_humidity + humidity);
        if (result == 0)
        {
            new_reading.humidity = prev_humidity + humidity;
            return ;
        }
    }
}

/*
**  Generates weather data for x amount of days, starting from the given date
*/
std::vector<Weather> generate_weather(int days, Weather& reading)
{
    Weather prev_reading = reading;
    Ymd current_date = get_current_date_ymd();
    Ymd date = prev_reading.date;
    std::vector<Weather> weather_data;
    for (int i = 0; i < days; ++i)
    {
        if (date_is_older(date, current_date) || date_is_equal(date, current_date))
        {
            Weather new_reading {};
            new_reading.date = date;
            update_date(date);
            select_season(new_reading);
            generate_pressure(new_reading, prev_reading.pressure);
            generate_temperature(new_reading, prev_reading.temperature);
            generate_wind(new_reading, prev_reading.wind_speed);
            generate_humidity(new_reading, prev_reading.humidity);
            prev_reading = new_reading;
            weather_data.push_back(new_reading);
        }
        else break ;
    }
    return weather_data;
}
