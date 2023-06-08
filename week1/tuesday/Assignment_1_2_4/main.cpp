/*
**  This program takes start time and end time in 24 hour format, hours and
**  minutes. It then calculates the difference betwwen start time and end time.
**  We assume that if end time is earlier than start time, it's next day.
**  Also we don't check validate time, so it's up to user.
*/

#include <iomanip>
#include <iostream>

struct Time
{
    int hours   {};
    int mins    {};
};

/*
**  Returns difference in hours. If end hour is earlier, we get the diff
**  by substracting start time from 24 hours and adding end time to it.
*/
int calc_time_difference_hours(int start_h, int end_h)
{
    if (start_h > end_h)
        return (24 - start_h + end_h);
    return end_h - start_h;
}

/*
**  Returns difference in mins. If end mins is earlier, we get the diff
**  by substracting start time from 60 mins and adding end time to it.
*/
int calc_time_difference_mins(int start_m, int end_m)
{
    if (start_m > end_m)
        return (60 - start_m + end_m);
    return end_m - start_m;
}

/*
**  Calculates time difference and returns it as a type struct Time to 
**  the caller.
*/
Time calc_time_diff(Time start, Time end)
{
    Time diff {};
    diff.hours = calc_time_difference_hours(start.hours, end.hours);
    diff.mins = calc_time_difference_mins(start.mins, end.mins);

    if (start.mins > end.mins)
    {
        if (start.hours == end.hours)
            diff.hours = 23;
        else
            diff.hours--;
    }
    return diff;
}

/*
**  Prints the time difference between start and end time.
**  Fills single digit ints with leading zero to format the time output.
*/
void print_time_diff(Time start, Time end, Time diff)
{
    std::cout << "Difference between "
        << std::setfill('0') << std::setw(2) << start.hours << ':'
        << std::setfill('0') << std::setw(2) << start.mins << " and "
        << std::setfill('0') << std::setw(2) << end.hours << ':'
        << std::setfill('0') << std::setw(2) << end.mins << " is: "
        << std::setfill('0') << std::setw(2) << diff. hours << " hours and "
        << std::setfill('0') << std::setw(2) << diff.mins << " minutes\n";
}

int main()
{

    /*
    **  These loops try some different inputs.
    **  They can be removed or replaced!
    */
    for (int i = 0; i < 60; i+=11)
    {
        Time start { 20, 45 };
        Time end { 19, i};
        print_time_diff(start, end, calc_time_diff(start, end));
    }
    for (int i = 0; i < 24; i+=6)
    {
        Time start { i, 45 };
        Time end { 0, 24};
        print_time_diff(start, end, calc_time_diff(start, end));
    }

    return 0;
}
