#include "../includes/math_functions.h"

int addition(int a, int b)
{
    return a + b;
}

int substraction(int a, int b)
{
    return a - b;
}

int multiplication(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    if (b == 0)
        throw("Division by 0 is not allowed!");
    return a / b;
}
