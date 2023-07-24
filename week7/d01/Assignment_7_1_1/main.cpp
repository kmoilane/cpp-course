#include "includes/typecheck.hpp"
#include <iostream>

int main()
{
    std::cout << std::boolalpha << ex1::is_same_type(1, 5) << '\n';     //true
    std::cout << std::boolalpha << ex1::is_same_type(1, 5.6f) << '\n';  //false
    std::cout << std::boolalpha << ex1::is_same_type('k', 5) << '\n';   //false
    std::cout << std::boolalpha << ex1::is_same_type('k', 'e') << '\n'; //true

    return 0;
}
