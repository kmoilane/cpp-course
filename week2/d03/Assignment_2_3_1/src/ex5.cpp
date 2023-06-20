#include "../includes/exercises.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void sort_pair_vector_second(std::vector<std::pair<std::string, int>>& vect)
{
    std::stable_sort(vect.begin(), vect.end(), [](auto &left, auto& right){
        return left.second < right.second;
    });
}

void print_pair_vect(std::vector<std::pair<std::string, int>>& vect)
{
    for (auto str : vect)
    {
        std::cout << str.first << ' ' << str.second << 'v';
        if (str != vect.back())
            std::cout << ", ";
    }
    std::cout << '\n';
}

void ex5_main()
{
    using namespace std;
    std::cout << "\nExercise 5:\n";
    vector<pair<string,int>> vect { {"Aatu", 24}, {"Satu", 22},
        {"Patu", 13}, {"Kapu", 29}, {"Rapu", 0}, {"Saku", 9}};
    std::cout << "Vector before sorting:\n";
    print_pair_vect(vect);
    std::cout << "Vector after sorting:\n";
    sort_pair_vector_second(vect);
    print_pair_vect(vect);
}
