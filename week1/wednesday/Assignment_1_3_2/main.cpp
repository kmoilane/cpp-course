#include "includes/bank.h"
#include "includes/structs.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

/*
**  Prints UI option for logged in users and manages input in that menu
*/
bool banking_ui()
{
    std::cout << "\nWelcome to Seers Bank " << g_logged_user->name
        << "!\nHow can we serve you today?\n\n";

    while (true)
    {
        print_ui_options();
        int option {};
        std::cin >> option;
        if (!std::cin)
        {
            clear_cin();
            print_invalid_option();
            continue ;
        }
        else if (option == 1)
            deposit();
        else if (option == 2)
            withdraw();
        else if (option == 3)
            view_balance();
        else if (option == 4)
            open_new_account();
        else if (option == 5)
        {
            logout();
            return 1;
        }
        else if (option == 6)
            return 0;
        else
            print_invalid_option();        
    }
}

/*
**  This function handles auhtentication UI and user input in it.
**  Ooptions are login, sign up and quit
*/
int authentication_ui()
{
    std::cout << "Welcome to Seers Bank!\n\n";
    while (true)
    {
        print_auth_options();
        int option {};
        std::cin >> option;
        if (!std::cin)
            clear_cin();
        else if (option == 1 && login())
            return 1;
        else if (option == 2 && sign_up())
            continue ;
        else if (option == 3)
            return 0;
    }
    return 0;
}

/*
**  This function creates a file from the g_bank global variable in csv format.
**  It is only called at the end of the program and overwrites
**  itself on each run
*/
void create_file()
{
    std::string file_path{ "db/bank_db" };
    std::ofstream file(file_path);

    if(!file)
        return ;
    
    for (User client : g_bank)
    {
        file
            << client.customer_num << ','
            << client.name << ','
            << client.address << ','
            << client.phone_num << '\n';
            for (Account acc : client.accounts)
            {
                file
                    << acc.account_num << ','
                    << acc.balance << '\n';
            }
            file << '\n';
    }

    file.close();
}

/*
**  This function opens the bank_db file and loops through it line by line.
**  Based on the formatting and order of data in the file, we can take every
**  part and place it to our User struct in the correct member. After each
**  User, we push it to our global g_bank vector that holds all Users. We also
**  update the g_highest_user and g_highest_acc to keep them up to date.
*/
void load_file()
{
    std::string file_path{ "db/bank_db" };
    std::ifstream file(file_path);

    if (!file)
        return ;

    std::string line {};
    User client;
    bool reading_accounts = false;

    while (std::getline(file, line))
    {
        if (line.empty()) {
            reading_accounts = false;
            g_bank.push_back(client);
            client = User();
        }
        else if (!reading_accounts)
        {
            std::istringstream iss(line);
            std::string customer_num_str {};
            std::getline(iss, customer_num_str, ',');
            std::getline(iss, client.name, ',');
            std::getline(iss, client.address, ',');
            std::getline(iss, client.phone_num);
            client.customer_num = std::stoi(customer_num_str);

            if (client.customer_num > g_highest_user)
                g_highest_user = client.customer_num;

            reading_accounts = true;
        }
        else
        {
            std::istringstream iss(line);
            Account acc {};
            std::string acc__num_str {};
            std::string balance_str {};
            std::getline(iss, acc__num_str, ',');
            std::getline(iss, balance_str);
            acc.account_num = std::stoi(acc__num_str);
            acc.balance = std::stoi(balance_str);
            client.accounts.push_back(acc);

            if (acc.account_num > g_highest_acc)
                g_highest_acc = acc.account_num;
        }

    }
    file.close();
}

/*
**  Clears and ignores invalid input to std::cin
*/
void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    load_file();
    while (true)
    {
        int auth = authentication_ui();
        if (auth == 1)
        {
            if(banking_ui())
                continue ;
            else
            {
                create_file();
                return 0;
            }
        }
        else if (auth == 0)
        {
            create_file();
            return 0;
        }
    }
}
