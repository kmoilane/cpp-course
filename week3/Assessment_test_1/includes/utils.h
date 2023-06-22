#ifndef UTILS_H
#define UTILS_H

#define USER_NOT_FOUND -1
#define INVALID_TRANSACTION -2

double  addition(double a, double b);
double  substraction(double a, double b);
void    clear_cin();
int     prompt_int_input();
double  prompt_double_input();
bool    validate_int_option(int option, int min, int max);

#endif


