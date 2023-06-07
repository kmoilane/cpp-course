/*
**  Write a program that declares a variable inside a loop and
**  prints its value. Ask the students what will happen if they try
**  to access the variable outside the loop.
*/

#include <iostream>

int main()
{
    while (true)
    {
        int i = 99;
        std::cout << i << std::endl;
        break ;
    }
    // i no longer accessible, it had local scope within the loop, not outside
    // std::cout << i << std::endl; this would not compile here
}

