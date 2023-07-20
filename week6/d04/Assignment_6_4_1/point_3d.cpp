#include "includes/point_3d.hpp"
#include <iostream>

int main()
{
    myspace::Point_3D v1{5, 6, 7};
    myspace::Point_3D v2{1, 1, 1};
    myspace::Point_3D v3{3, 3, 3};
    std::cout << v1;
    std::cout << v1 + v2;
    std::cout << v2;
    v3 += v2;
    std::cout << v3;
    std::cout << (v3 -= v2);
    std::cout << v3 - v1;
    std::cout << v3;
    return 0;
}
