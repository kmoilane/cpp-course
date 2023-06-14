#define NDEBUG
#include <cassert>
#include <iomanip>
#include <iostream>

bool    play_game(double num)
{
    int min { 1 };
    int max { 100 };
    assert((num >= min && num <= max) && "Number is out of range!");
    
    return (num >= min && num <= max) ? true : false;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << "1 is in range? " << play_game(1) << '\n';
    std::cout << "10 is in range? " << play_game(10) << '\n';
    std::cout << "100 is in range? " << play_game(100) << '\n';
    std::cout << "0 is in range? " << play_game(0) << '\n';
    std::cout << "101 is in range? " << play_game(101) << '\n';
    return 0;
}
