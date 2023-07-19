#include "includes/posint.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
    Posint a;
    Posint b {5};
    Posint c;
    Posint e {INT_MAX};
    try
    {
        Posint d {-1};
        c = d;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << a.get_value() << '\n' << b.get_value() << '\n' << c.get_value() << '\n';
    a = b;
    std::cout << "a is now: " << a.get_value() << '\n';
    c = a + b;
    std::cout << "c is now: " << c.get_value() << '\n';
    a = a - c;
    std::cout << "a is now: " << a.get_value() << '\n';
    c = c - b;
    std::cout << "c is now: " << c.get_value() << '\n';
    std::cout << "e is now: " << e.get_value() << '\n';
    e = e - 10;
    std::cout << "e is now: " << e.get_value() << '\n';
    e = e + 20;
    std::cout << "e is now: " << e.get_value() << '\n';

    try
    {
        a = -20;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Posint f {100};
    f = add(f, b);
    std::cout << "f is now: " << f.get_value() << '\n';

    b = add(b, b);
    f = substract(f, b);
    std::cout << "f is now: " << f.get_value() << '\n';
    return 0;
}
