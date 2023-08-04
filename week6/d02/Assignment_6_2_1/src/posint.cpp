#include "../includes/posint.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

Posint::Posint(int val)
{
    if(val >= 0)
        value = val;
    else
        throw std::invalid_argument("Can't assign negative value to positive integer");
}

void Posint::print_value()
{
    std::cout << value;
}

const int& Posint::get_value() const noexcept
{
    return value;
}

Posint Posint::operator+(const Posint& rhs) {
    Posint a;
    a.value = value + rhs.value;
    if (a.value < 0)
        a.value = INT_MAX;
    return a;
}

Posint Posint::operator-(const Posint& rhs)
{
    Posint a;
    a.value = value - rhs.value;
    if (a.value < 0)
        a.value = 0;
    return a;
}
