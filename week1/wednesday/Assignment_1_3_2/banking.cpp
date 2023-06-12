#include "./bank.h"
#include "./structs.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>

/*
**  Creates a new bank account and sets balance to 0
*/
Account create_account()
{
    Account new_account {};
    new_account.account_num = ++g_highest_acc;
    new_account.balance = 0;
    return new_account;
}

/*
**  This function is called when user opens a new account. It creates the acc
**  and pushes it to the clients account vector.
*/
void open_new_account()
{
    Account new_acc { create_account() };
    g_logged_user->accounts.push_back(new_acc);
    std::cout << "You have opened a new account with a number of:\n\n"
        << new_acc.account_num << "\n\n";
}

/*
**  Prints all the accounts of logged user and prints their balance
*/
void view_balance()
{
    std::cout << "\nAccount's balance\n\n";

    for (Account acc : g_logged_user->accounts)
    {
        std::cout
            << "You have " << acc.balance
            << "€ on account number: "
            << acc.account_num << "\n";
    }
    std::cout << '\n';
}

/*
**  Prompts user for the int amount. This is called from deposit()
**  and withdraw(). Returns -1 for non int input and 0 for below 1, otherwise
**  returns the given amount
*/
int ask_amount()
{
    std::cout << "Enter amount: ";
    int amount {};
    std::cin >> amount;
    if (!std::cin)
    {
        clear_cin();
        return -1;
    }
    else if (amount > 0)
    {
        return amount;
    }
    return 0;
}

/*
**  This function is called from deposit() and widthraw() functions to get users
**  input on which account he wants to use. Returns 0 for invalid inputs and
**  accout number when it's valid
*/
size_t select_account()
{
    std::cout << "Select which account you want to use:\n";

    for (size_t i = 0; i < g_logged_user->accounts.size(); ++i)
    {
        std::cout << "Account number: "
        << g_logged_user->accounts[i].account_num
        << "\t->\tPress " << i + 1 << '\n';
    }

    size_t option {};
    std::cin >> option;

    if (!std::cin)
    {
        clear_cin();
        return 0;
    }
    if (option > 0 && option <= g_logged_user->accounts.size())
        return option;
    else 
        return 0;
}

/*
**  Gets account and amount from user, and withdraws that from the account if
**  account has enough funds.
*/
void withdraw()
{
    std::cout << "\nWithdraw from your bank account\n\n";

    size_t option { select_account() };

    if (option == 0)
        print_invalid_option();
    else
    {
        int amount { ask_amount() };
        if (amount == -1)
            print_invalid_option();
        else if (amount == 0)
            print_invalid_amount();
        else
        {
            if ((g_logged_user->accounts[option -1].balance - amount) < 0)
                std::cout << "\nNot enough funds on the selected account!\n\n";
            else
            {
                g_logged_user->accounts[option - 1].balance -= amount;
                std::cout << "\nYou have withdrawn " << amount << "€\n\n";
            }
        }
    }
}

/*
**  Gets account and amount from user and makes deposit if values are valid
*/
void deposit()
{
    std::cout << "\nDeposit to your bank account\n\n";
    size_t option { select_account() };

    if (option == 0)
        print_invalid_option();
    else
    {
        int amount { ask_amount() };
        if (amount == -1)
            print_invalid_option();
        else if (amount == 0)
            std::cout << "\nYou need to enter positive value over 0\n";
        else if (g_logged_user->accounts[option - 1].balance + amount
            < 0)
        {
            std::cout << "\nThis account can't hold that much money!\n\n";
        }
        else
        {
            g_logged_user->accounts[option - 1].balance += amount;
            std::cout << "\nYou have deposited " << amount << "€\n\n";
        }
    } 
}
