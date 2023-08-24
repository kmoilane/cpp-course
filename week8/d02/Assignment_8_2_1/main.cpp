#include "includes/counter.hpp"
#include "includes/debug.hpp"
#include <iostream>
#include <type_traits>

template <typename T>
void print_valueness(T&& val)
{
    if (std::is_rvalue_reference_v<T&&>)
        std::cout << "Given value is rvalue refernece\n";
    else if (std::is_lvalue_reference_v<T&&>)
        std::cout << "Given value is lvalue reference\n";
}

int main()
{
    int x = 42;
    std::cout << "\033[1;34mEXERCISE 1\033[0m\n";
    print_valueness(x);
    print_valueness(std::move(x));
    
    std::cout << "\033[1;34mEXERCISE 2\033[0m\n";
    {
        Debug<true> bug1;
        Debug<true> bug2(bug1);
        Debug<true> bug4;
        Debug<true> bug3(std::move(bug2));
        Debug<false> bug5;
    }
    std::cout << "Default constructor called: " << Debug<true>::constructor_count << '\n';
    std::cout << "Default destructor called: " << Debug<true>::destructor_count << '\n';
    std::cout << "Move constructor called: " << Debug<true>::move_count << '\n';
    std::cout << "Copy constructor called: " << Debug<true>::copy_count << '\n';

    std::cout << "\033[1;34mEXERCISE 3\033[0m\n";
    Counter c1;
    std::cout << "instances: 1 = " << Counter::get_count() << '\n';
    {
        Counter c3;
        std::cout << "instances: 2 = " << Counter::get_count() << '\n';
        {
            Counter c4(std::move(c3));
            std::cout << "instances: 2 = " << Counter::get_count() << '\n';
            Counter c5(std::move(c4));
            std::cout << "instances: 2 = " << Counter::get_count() << '\n';
        }
        std::cout << "instances: 1 = " << Counter::get_count() << '\n';
    }
    std::cout << "instances: 1 = " << Counter::get_count() << '\n';
    {
        Counter c2 = std::move(c1);
        std::cout << "instances: 1 = " << Counter::get_count() << '\n';
    }
    std::cout << "instances: 0 = " << Counter::get_count() << '\n';

    return 0;
}
