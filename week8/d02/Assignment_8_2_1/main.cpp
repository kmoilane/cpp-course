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
    std::cout << "Exercise 1\n";
    print_valueness(x);
    print_valueness(std::move(x));
    
    std::cout << "\nExercise 2\n";
    Debug<true> bug1;
    Debug<true> bug2(bug1);
    Debug<true> bug4;
    Debug<true> bug3(std::move(bug2));
    {
        Debug<false> bug5;
    }
    std::cout << "Default constructor called: " << Debug<true>::constructor_count << '\n';
    std::cout << "Default destructor called: " << Debug<true>::destructor_count << '\n';
    std::cout << "Move constructor called: " << Debug<true>::move_count << '\n';
    std::cout << "Copy constructor called: " << Debug<true>::copy_count << '\n';

    return 0;
}
