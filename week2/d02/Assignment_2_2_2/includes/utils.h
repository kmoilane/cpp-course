#ifndef UTILS_H
#define UTILS_H

#include <iostream>

void print_help();
void print_sum(double a, double b);
void print_substraction(double a, double b);
void print_multiplication(double a, double b);
void print_division(double a, double b);
void encrypt(std::string str, int key);
void decrypt(std::string str, int key);

#endif
