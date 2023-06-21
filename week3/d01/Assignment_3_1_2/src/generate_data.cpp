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

void update_date(Ymd& date)
{
    if (date.month == 12 && date.day == 31)
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
        date.day++;
    }
    else if ((date.month == 3 || date.month == 6 || date.month == 9
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
            date.month += 1;
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

void generate_temperature(Weather& new_reading, double temp /*= INT_MIN*/)
{
    if (new_reading.season == WINTER)
    {
        if (temp == INT_MIN)
        {
            new_reading.temperature =
                random_num(WINTER_TEMP_RANGE.first, WINTER_TEMP_RANGE.second);
        }
        else
        {
            new_reading.temperature =
                random_num(temp - 5, temp + 5);
        }
    }
    else if (new_reading.season == SPRING)
    {
        if (temp == INT_MIN)
        {
            new_reading.temperature =
                random_num(SPRING_TEMP_RANGE.first, SPRING_TEMP_RANGE.second);
        }
        else
        {
            new_reading.temperature =
                random_num(temp - 5, temp + 5);
        }
    }
    else if (new_reading.season == SUMMER)
    {
        if (temp == INT_MIN)
        {
            new_reading.temperature =
                random_num(SUMMER_TEMP_RANGE.first, SUMMER_TEMP_RANGE.second);
        }
        else
        {
            new_reading.temperature =
                random_num(temp - 5, temp + 5);
        }
    }
    else if (new_reading.season == AUTUMN)
    {
        if (temp == INT_MIN)
        {
            new_reading.temperature =
                random_num(AUTUMN_TEMP_RANGE.first, AUTUMN_TEMP_RANGE.second);
        }
        else
        {
            new_reading.temperature =
                random_num(temp - 5, temp + 5);
        }
    }
}

/*
**  Generates weather data for x amount of days, starting from the given date
*/
std::vector<Weather> generate_weather(int days, Ymd date)
{
    Ymd current_date { date };
    std::vector<Weather> weather_data {};
    double prev_temp = INT_MIN;
    for (int i = 0; i < days; ++i)
    {
        Weather new_reading {};
        new_reading.date = current_date;
        select_season(new_reading);
        if (i == 0)
            generate_temperature(new_reading);
        else
            generate_temperature(new_reading, prev_temp);
        update_date(current_date);
        prev_temp = new_reading.temperature;
        weather_data.push_back(new_reading);
    }
    return weather_data;
}
