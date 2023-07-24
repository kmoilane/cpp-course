#include "includes/typecheck.hpp"
#include <iostream>
#include <type_traits>

int main()
{
    /*
    **  Exercise 1
    */
    std::cout << std::boolalpha;
    std::cout << ex1::is_same_type(1, 5) << '\n';     //true
    std::cout << ex1::is_same_type(1, 5.6f) << '\n';  //false
    std::cout << ex1::is_same_type('k', 5) << '\n';   //false
    std::cout << ex1::is_same_type('k', 'e') << '\n'; //true

    /*
    **  Exercise 2
    */
    int arr[3] = {1, 2, 3};
    int *arr_ptr = arr;
    std::cout << ex2::can_decay<int>() << '\n';    // false
    std::cout << ex2::can_decay<char*>() << '\n';   // true
    std::cout << ex2::can_decay<char&>() << '\n';   // true
    std::cout << ex2::can_decay<int[2][3]>() << '\n';   // true

    return 0;
}
