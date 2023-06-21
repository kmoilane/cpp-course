/*
**  This file includes some simple prints that are either used multiple times,
**  or are here to clarify the functions they are called from.
*/

#include "../includes/structs.h"
#include "../includes/bank.h"
#include <iostream>
#include <vector>

void print_auth_options()
{
    std::cout << "Login\t\t->\tPress 1\n";
    std::cout << "Register\t->\tPress 2\n";
    std::cout << "Quit\t\t->\tPress 3\n";
}

void print_sign_up_success(int customer_number)
{
    std::cout << "\nCongratualtions, you have registered to Seers Bank!\n";
    std::cout << "Your user number is: " << customer_number << '\n';
    std::cout << "You can use it to login to your account!\n\n";
}

void print_ui_options()
{
    std::cout << "Deposit\t\t->\tPress 1\n";
    std::cout << "Withdraw\t->\tPress 2\n";
    std::cout << "Balance\t\t->\tPress 3\n";
    std::cout << "Open Account\t->\tPress 4\n";
    std::cout << "Logout\t\t->\tPress 5\n";
    std::cout << "Quit\t\t->\tPress 6\n";
}

void print_invalid_option()
{
    std::cout << "\nThat's not an option, try again!\n\n";
}

void print_invalid_amount()
{
    std::cout << "\nYou need to enter positive value over 0\n\n";
}
