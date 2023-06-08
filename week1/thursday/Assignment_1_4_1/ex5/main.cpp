#define NDEBUG
#include <cassert>
#include <cmath>
#include <iostream>

double  square_root(double x)
{
    assert(x > 0 && "The square root is not defined for negative numbers");
    return std::sqrt(x);
}

int     main()
{
    std::cout << "Square root of 6\t= " << square_root(6) << '\n';
    std::cout << "Square root of 0.02\t= " << square_root(0.02) << '\n';
    std::cout << "Square root of 4.6\t= " << square_root(4.6) << '\n';
    std::cout << "Square root of 9\t= " << square_root(9) << '\n';
    std::cout << "Square root of -1\t= " << square_root(-1) << '\n';
    return 0;
}
