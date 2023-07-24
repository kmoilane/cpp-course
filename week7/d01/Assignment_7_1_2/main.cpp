#include "includes/grid_2d.hpp"
#include <iostream>
#include <vector>

int main()
{
    Grid::Grid_2D<char> grid{3, 3, {'S', 'T', 'U', 'R', 'D', 'I', 'E', 'S', 'T'}};
    std::cout << "U = " << grid.at(2) << '\n';
    std::cout << "S = " << grid.at(0) << '\n';
    std::cout << "T = " << grid.at(8) << '\n';
    std::cout << "T = " << grid[8] << '\n';
    std::cout << "T = " << grid.at(2, 2) << '\n';
    auto it = grid.begin();
    auto it2 = grid.end();
    auto it3 = grid.back();
    grid.print_grid();
    grid[8] = 'L';
    grid.at(0) = 'Y';
    std::cout << "Iter begin S = " << &*it << '\n';
    std::cout << "Iter end = " << &*it2 << '\n';
    std::cout << "Iter back T = " << it3 << '\n';
    grid.print_grid();
    Grid::Size_2D size = grid.size_2D();
    std::cout << "width: " << size.width << '\n';
    std::cout << "height: " << size.height << '\n';
    std::cout << "1D size: " << grid.size_1D() << '\n';
    return 0;
}
