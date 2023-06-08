/*
**  divide() takes two ints, asserts that divider (second int) is not 0.
**  Returns the quotient as a double.
*/

#define NDEBUG
#include <cassert>
#include <iomanip>
#include <iostream>

double divide(int a, int b)
{
    assert(b != 0 && "Division by zero is not allowed");
    return a / static_cast<double>(b);
}

int main()
{
    std::cout.precision(3);
    std::cout << "5 / 7 = " << divide(5, 7) << '\n';
    std::cout << "7 / 5 = " << divide(7, 5) << '\n';
    std::cout << "54 / 4 = " << divide(54, 4) << '\n';
    std::cout << "99 / 9 = " << divide(99, 9) << '\n';
    std::cout << "-5 / 9 = " << divide(-5, 9) << '\n';
    std::cout << "99 / -9 = " << divide(99, -9) << '\n';
    std::cout << "0 / 2 = " << divide(0, 2) << '\n';
    std::cout << "9 / 0 = " << divide(9, 0) << '\n';

    return 0;
}
