#include "../includes/exercises.h"
#include <algorithm>
#include <iostream>
#include <vector>

void sort_int_vector_asc(std::vector<int>& vect)
{
    std::sort(vect.begin(), vect.end());
}

void ex1_main()
{
    std::cout << "\nExercise 1:\n";
    std::vector<int> vect { 4, 7, 21, 7, 0, -4, 92, 21, 64 };
    std::cout << "Vector before sorting:\n";
    print_int_vect(vect);
    std::cout << "Vector after sorting:\n";
    sort_int_vector_asc(vect);
    print_int_vect(vect);
}
