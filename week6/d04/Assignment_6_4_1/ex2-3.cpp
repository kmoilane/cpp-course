#include "includes/point_3d.hpp"
#include <iostream>

int main()
{
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min();
    myspace::Point_3D v1{5, 6, 7};
    myspace::Point_3D v2{1, 1, 1};
    myspace::Point_3D v3{3, 3, 3};
    myspace::Point_3D v4{max, max, max};
    myspace::Point_3D v5{min, min, min};
    std::cout << v1;
    std::cout << v1 + v2;
    std::cout << v2;
    v3 += v2;
    std::cout << v3;
    std::cout << (v3 -= v2);
    std::cout << v3 - v1;
    std::cout << v3;
    std::cout << v4;
    std::cout << v5;
    std::cout << (v4 + v2);
    std::cout << (v5 -= v5);
    std::cout << v5 - v4 - v4;
    return 0;
}
