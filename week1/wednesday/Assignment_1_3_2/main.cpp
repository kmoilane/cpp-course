// Banking application

// Exercise 1
// Write a banking program that will manage the information of a single users
// bank account.

// The bank stores the following information. name, address,
// telephone number and customer number.

// The program will have a text based user interface for each action.
// The user can add or withdraw money, see their account balance,
// or quit the program.

// Exercise 2
// Update your program so that the user can add more accounts.
// The account number needs to be unique.

// Exercise 3
// Update the program to handle more than one customer.
// The customer number for each created customer must be unique

// Exercise 4
// The program will store account data in a file.

#include <iostream>
#include <limits>

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

struct Bank_user
{

};

struct Bank_account
{

};

void balance()
{
    std::cout << "Account's balance\n";
}

void withdraw()
{
    std::cout << "Withdraw from your bank account\n";
}

void deposit()
{
    std::cout << "Deposit to your bank account\n";
}

void print_ui_options()
{
    std::cout << "Deposit\t\t->\tPress 1\n";
    std::cout << "Withdraw\t->\tPress 2\n";
    std::cout << "Balance\t\t->\tPress 3\n";
    std::cout << "Quit\t\t->\tPress 4\n";
}

void print_invalid_option()
{
    std::cout << "\nThat's not an option, try again!\n\n";
}

void banking_ui()
{
    std::cout << "Welcome to Brights Bank!\nHow can we serve you today?\n\n3";

    while (true)
    {
        print_ui_options();
        int option {};
        std::cin >> option;
        if (!std::cin)
        {
            clear_cin();
            continue ;
        }
        switch (option)
        {
            case 1:
                deposit();
                break ;
            case 2:
                withdraw();
                break ;
            case 3:
                balance();
                break ;
            case 4:
                return ;
            default :
                print_invalid_option();
        }
    }
}

int main()
{
    banking_ui();
    return 0;
}

