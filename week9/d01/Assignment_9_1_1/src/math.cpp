#include <algorithm>
#include <string>

int sum(int a, int b)
{
    return a + b;
}

int substract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b == 0)
        return 0;
    return a / b;
}

bool is_int(const std::string& str)
{
    return !str.empty() && std::find_if(str.begin(), str.end(), [](auto c){
        return !std::isdigit(c);
    }) == str.end();
}
