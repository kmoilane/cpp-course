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
    print_valueness(x);
    print_valueness(std::move(x));
    return 0;
}
