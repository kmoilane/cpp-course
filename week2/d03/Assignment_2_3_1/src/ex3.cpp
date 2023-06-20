#include "../includes/exercises.h"
#include <algorithm>
#include <iostream>
#include <vector>

void sort_double_vector_asc(std::vector<double>& vect)
{
    std::sort(vect.begin(), vect.end());
}

void ex3_main()
{
    std::cout << "\nExercise 3:\n";
    std::vector<double> vect { 4.4, 7.032, 21.01, 7.43, 0.01, -4.43, 92.43, 21.001, 64.43 };
    std::cout << "Vector before sorting:\n";
    print_double_vect(vect);
    std::cout << "Vector after sorting:\n";
    sort_double_vector_asc(vect);
    print_double_vect(vect);
}
