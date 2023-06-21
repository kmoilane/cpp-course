#include <iostream>
#include <string>

/*
**  Exercise 1, recursively reverses string and returns it. Swaps first and last
**  indexes and increases first, decreases last after each iteration
*/
std::string string_reverse(std::string& str, int start, int end)
{
    if (start == end || start > end)
        return str;
    else
    {
        std::swap(str[start], str[end]);
        string_reverse(str, start + 1, end - 1);
    }
    return str;
}

/*
**  Exercise 2, get the greatest divider of 2 integers using Euclidean algorithm
*/
int greatest_divisor(int a, int b)
{
    return (a % b != 0) ? greatest_divisor(b, a % b) : b;
}

/*
**  Exercise 3, x to the power of n recursively
*/
int power_to_n(int x, int n)
{
    return (n == 0) ? 1 : x * power_to_n(x, n - 1);
}

int main()
{
    std::string str {"Hasta la vista"};
    std::cout << str << '\n';
    str = string_reverse(str, 0, str.size() - 1);
    std::cout << str << '\n';

    int a = 210;
    int b = 45;
    std::cout << "Greatest divisor between 210 and -45: " << greatest_divisor(a, b) << '\n';
    std::cout << "3 to the power of 3: " << power_to_n(3, 3) << '\n';

    return 0;
}
