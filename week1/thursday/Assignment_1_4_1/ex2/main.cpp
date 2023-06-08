/*
**  Write a C++ program that calculates the factorial of a given number.
**  Implement a function called factorial() that takes an integer as input and
**  returns its factorial. Use an assert statement to check that the input
**  number is non-negative. If the assertion fails, display an error message
**  indicating that the factorial is not defined for negative numbers. Test your
**  program with various input values, including both positive and nega numbers
*/

#include <cassert>
#include <cctype>
#include <iostream>


int factorial(int n)
{
    assert(n >= 0 && "Factorial is not defined for negative numbers");
    if (n == 0)
        return 1;
    
    int result { n };
    while ((n - 1) > 0)
    {
        result *= n - 1;
        --n;
    }
    return result;
}

int main()
{
    std::cout << "Factorial of 0 = " << factorial(0) << '\n';
    std::cout << "Factorial of 4 = " << factorial(4) << '\n';
    std::cout << "Factorial of 5 = " << factorial(5) << '\n';
    std::cout << "Factorial of 2 = " << factorial(2) << '\n';
    std::cout << "Factorial of -3 = " << factorial(-3) << '\n';
    return 0;
}
