#include "../includes/posint.hpp"
#include <stdexcept>
#include <cstdint>
#include <limits>

Posint::Posint(int val)
{
    if(val >= 0)
        value = val;
    else
        throw std::invalid_argument("Can't assign negative value to positive integer");
}

const int& Posint::get_value() const noexcept
{
    return value;
}

Posint Posint::operator+(const Posint& rhs) {
    int64_t result;
    result = value + rhs.value;
    if (result < 0)
        return Posint { 0 };
    else if (result <= std::numeric_limits<int>::max())
        return Posint { static_cast<int>(result) };
    return Posint { std::numeric_limits<int>::max() };
}

Posint Posint::operator-(const Posint& rhs)
{
    Posint a;
    a.value = value - rhs.value;
    if (a.value < 0 || (rhs.value > value))
        a.value = 0;
    return a;
}

Posint add(const Posint& num1, const Posint& num2)
{
    int64_t result =
        static_cast<int64_t>(num1.value) + static_cast<int64_t>(num2.value);
    if (result < 0)
        return Posint { 0 };
    else if (result <= std::numeric_limits<int>::max())
        return Posint{static_cast<int>(result)};
    else
        return Posint{std::numeric_limits<int>::max()};

}

Posint substract(const Posint& num1, const Posint& num2)
{
    int result = num1.value - num2.value;
    if (result <= 0)
        return Posint(0);
    return Posint(result);
}
