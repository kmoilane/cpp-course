#include "includes/ex2.hpp"
#include <string>
#include <iostream>

int main()
{
    flawed_array<int, 5> int_array;
    for (std::size_t i = 0; i < int_array.size(); ++i)
    {
        int_array[i] = i;
    }
    for (auto &elem : int_array)
    {
        std::cout << elem << "\n";
    }
    auto int_array_copy = int_array;
    for (auto &elem : int_array_copy)
    {
        std::cout << elem << "\n";
    }
    // Works like a charm so far. Where's the error?
}
