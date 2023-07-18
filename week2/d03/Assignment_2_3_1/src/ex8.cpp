#include "../includes/exercises.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void sort_pair_vector_first(std::vector<std::pair<std::string, int>>& vect)
{
    std::stable_sort(vect.begin(), vect.end(), [](auto &left, auto& right){
        return left.first < right.first;
    });
}

void ex8_main()
{
    using namespace std;
    std::cout << "\nExercise 8:\n";
    vector<pair<string,int>> vect { {"Aatu", 24}, {"Aatu", 22},
        {"Aatu", 13}, {"Kapu", 29}, {"Aatu", 0}, {"Aatu", 9}};
    std::cout << "Vector before sorting:\n";
    print_pair_vect(vect);
    std::cout << "Vector after sorting:\n";
    sort_pair_vector_first(vect);
    print_pair_vect(vect);
}
