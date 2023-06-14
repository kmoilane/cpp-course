#ifndef EXERCISES_H
#define EXERCISES_H

#include <vector>
#include <string>

void sort_int_vector_asc(std::vector<int>& vect);
void sort_int_vector_desc(std::vector<int>& vect);
void sort_double_vector_asc(std::vector<double>& vect);
void sort_string_vector_lexi(std::vector<std::string>& vect);
void sort_pair_vector_second(std::vector<std::pair<std::string, int>>& vect);
void sort_pair_vector_first(std::vector<std::pair<std::string, int>>& vect);
void partial_sort_int_vector_desc(std::vector<int>& vect);
void ex1_main();
void ex2_main();
void ex3_main();
void ex4_main();
void ex5_main();
void ex7_main();
void ex8_main();
void print_int_vect(std::vector<int>& vect);
void print_double_vect(std::vector<double>& vect);
void print_string_vect(std::vector<std::string>& vect);
void print_pair_vect(std::vector<std::pair<std::string, int>>& vect);

#endif
