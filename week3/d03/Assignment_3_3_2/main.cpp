#include "includes/math_functions.h"
#include "includes/string_utility.h"
#include <iostream>

int main()
{
    std::cout << "5 + 5 = " << addition(5, 5) << '\n';
    std::cout << "5 - 5 = " << substraction(5, 5) << '\n';
    std::cout << "5 * 5 = " << multiplication(5, 5) << '\n';
    std::cout << "5 / 5 = " << division(5, 5) << '\n';
    std::cout << "hello there! => " << reverse_string("hello there!") << '\n';
    std::cout << "hello there! => " << string_to_upper("hello there!") << '\n';
    std::cout << "HELlo tHERe! => " << string_to_lower("HELlo tHERe!") << '\n';
    std::cout << "saippuakivikauppias is palindrome? " << std::boolalpha
        << string_is_palindrome("saippuakivikauppias") << '\n';

    return 0;
}
