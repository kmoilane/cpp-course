#include "../includes/exercises.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void sort_string_vector_lexi(std::vector<std::string>& vect)
{
    std::sort(vect.begin(), vect.end());
}

void print_string_vect(std::vector<std::string>& vect)
{
    for (auto str : vect)
    {
        std::cout << str;
        if (str != vect.back())
            std::cout << ", ";
    }
    std::cout << '\n';
}

void ex4_main()
{
    std::cout << "\nExercise 4:\n";
    std::vector<std::string> vect { "Aatu", "Kaatu", "Saatu", "Kaat", "Maatu",
    "Taattu", "Laatu", "Aate", "Saate" };
    std::cout << "Vector before sorting:\n";
    print_string_vect(vect);
    std::cout << "Vector after sorting:\n";
    sort_string_vector_lexi(vect);
    print_string_vect(vect);
}
