#include "../includes/string_utility.h"
#include <algorithm>
#include <string>

std::string reverse_string(std::string str)
{
    reverse(str.begin(), str.end());
    return str;
}

std::string string_to_upper(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

std::string string_to_lower(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

/*
**  Creates a copy of the string, reverses it and checks if it's ewual with
**  original string
*/
bool string_is_palindrome(std::string str)
{
    std::string str_rev = reverse_string(str);
    if (str_rev == str)
        return true;
    return false;
}
