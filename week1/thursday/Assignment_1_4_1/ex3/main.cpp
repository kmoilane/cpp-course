/*
**  Write a C++ program that calculates the sum of two integers. Implement a
**  function called sum() that takes two integers as input and returns their
**  sum. Use an assert statement to check that the sum is positive. If the
**  assertion fails, display an error message indicating that the sum is not
**  positive. Compile the program with the NDEBUG macro defined and observe
**  the behaviour when the assertion fails.
*/

#define NDEBUG
#include <cassert>
#include <iostream>

int sum(int a, int b)
{
    assert(a + b >= 0 && "The sum is not positive");
    return a + b;
}

int main()
{
    std::cout << "5 + 3 = " << sum(5, 3) << '\n';
    std::cout << "-3 + 3 = " << sum(-3, 3) << '\n';
    std::cout << "-5 + 3 = " << sum(-5, 3) << '\n';

    return 0;
}
