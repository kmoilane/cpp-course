/*
**  Write a program that declares a variable inside a namespace and another
**  variable with the same name inside a function. Print the value of each
**  of each variable and discuss with the students how scope resolution
**  works in namespaces.
*/

#include <iostream>

namespace   My_namespace
{
    int val { 10 };
}

int main()
{
    int val { 20 };
    std::cout << "This is 20: " << val << '\n';
    std::cout << "This is 10: " << My_namespace::val << '\n';

    return 0;
}

/*
**  First function looks for the variable inside local scope and takes that
**  with scope resolution operator we can access val inside our namespace
*/
