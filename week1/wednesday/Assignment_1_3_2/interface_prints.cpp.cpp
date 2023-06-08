#include "structs.h"
#include "bank.h"
#include <iostream>
#include <vector>

void print_auth_options()
{
    std::cout << "Welcome to Brights Bank!\n\n";
    std::cout << "Login\t\t->\tPress 1\n";
    std::cout << "Register\t->\tPress 2\n";
    std::cout << "Quit\t\t->\tPress 3\n";
}

void sign_up_success_prints(int customer_number)
{
    std::cout << "\nCongratualtions, you have registered to Brights Bank!\n";
    std::cout << "Your customer number is: " << customer_number << '\n';
    std::cout << "You can use it to login to your account!\n";
}
