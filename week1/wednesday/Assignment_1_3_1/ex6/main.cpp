/*
**  Write a program that declares a variable inside a function, passes it as a
**  parameter to another function, and modifies its value. Print the value of
**  the variable before and after the function call. Discuss with the students
**  how the lifetime of the variable is affected by passing it as a parameter.
*/

#include <iostream>

void another_function([[maybe_unused]]int val) // This creates new local variable
{
    val = 444;
}

int main()
{
    int val {};

    val = 666;
    std::cout << val << std::endl;

    another_function(val); // Val won't be modified

    std::cout << val << std::endl;

    return 0;
}
