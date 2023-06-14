#include "../includes/exercises.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

void partial_sort_int_vector_desc(std::vector<int>& vect)
{
    std::partial_sort(vect.begin(), vect.begin() + 5,
        vect.end(), std::greater<int>());
}

void ex7_main()
{
    std::cout << "\nExercise 7:\n";
    std::vector<int> vect { 2, 4, 63, 24, 87, 24, 7, 78, -24,
    -234, 55, 21, 78, 343, 63, 2, 233, 97, 939, 38, 57, 92, 999 };
    std::cout << "Vector before sorting:\n";
    print_int_vect(vect);
    std::cout << "Vector after sorting:\n";
    partial_sort_int_vector_desc(vect);
    print_int_vect(vect);
}
