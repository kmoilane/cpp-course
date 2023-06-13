#ifndef UTILS_H
#define UTILS_H

#include <iostream>

void print_help();
void print_sum(int a, int b);
void print_substraction(int a, int b);
void print_multiplication(int a, int b);
void print_division(int a, int b);
void encrypt(std::string str, int key);
void decrypt(std::string str, int key);

#endif
