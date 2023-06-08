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

#include "./bank.h"
#include "./structs.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>

std::vector<Client>     g_bank{};
Client*                 g_logged_user { nullptr };
int                     g_highest_acc { 0 };
int                     g_highest_user { 0 };

Client add_client(std::string new_name,
std::string addr, std::string phone)
{
    Client new_user {};
    new_user.name = new_name;
    new_user.address = addr;
    new_user.phone_num = phone;
    new_user.customer_num = ++g_highest_user;
    
    Account account { new_account() };
    new_user.accounts.push_back(account);
    return new_user;
}

Account new_account()
{
    Account new_account {};
    new_account.account_num = ++g_highest_acc;
    new_account.balance = 0;
    return new_account;
}

int add_user()
{
    std::cout << "Enter your name: ";
    std::string name {};
    std::getline(std::cin >> std::ws, name);
    std::cout << "Enter your address: ";
    std::string address {};
    std::getline(std::cin >> std::ws, address);
    std::cout << "Enter your phone number: ";
    std::string phone_num {};
    std::getline(std::cin >> std::ws, phone_num);

    Client new_user { add_client(name, address, phone_num) };

    g_bank.push_back(new_user);
    
    return new_user.customer_num;
}

Client* find_user(int num)
{
    for (Client& client : g_bank)
    {
        if (client.customer_num == num)
        {
            return &client;
        }
    }
    return nullptr;
}

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void view_balance()
{
    std::cout << "\nAccount's balance\n\n";
    for (Account acc : g_logged_user->accounts)
    {
        std::cout << "You have "
            << acc.balance
            << "€ on account number: "
            << acc.account_num << "\n";
    }
    std::cout << '\n';

}

void withdraw()
{
    std::cout << "\nWithdraw from your bank account\n\n";
}

void deposit()
{
    std::cout << "\nDeposit to your bank account\n\n";
    std::cout << "Select which account you want to deposit to:\n";
    for (size_t i = 0; i < g_logged_user->accounts.size(); ++i)
    {
        std::cout << "Account number: "
        << g_logged_user->accounts[i].account_num
        << "\t->\tPress " << i + 1 << '\n';
    }

    size_t option {};
    std::cin >> option;
    if (option > 0 && option <= g_logged_user->accounts.size())
    {
        std::cout << "Enter amount: ";
        int i {};
        std::cin >> i;
        if (!std::cin)
            clear_cin();
        else if (i > 0)
        {
            g_logged_user->accounts[option - 1].balance += i;
            std::cout << "\nYou have deposited " << i << "€\n\n";
        }
    }
    else
        std::cout << "\nInvalid option!\n\n";
    
}



void print_invalid_option()
{
    std::cout << "\nThat's not an option, try again!\n\n";
}

void logout()
{
    std::cout << "\nYou have logged out!\n\n";
    g_logged_user = nullptr;
}

void open_new_account()
{
    Account new_acc { new_account() };
    g_logged_user->accounts.push_back(new_acc);
    std::cout << "You have opened a new account with a number of:\n\n\t"
        << new_acc.account_num << "\n\n";
}

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

int get_login_info()
{
    std::cout << "Enter your customer number: ";
    while (true)
    {
        int num {};
        std::cin >> num;

        if (!std::cin)
            clear_cin();
        else
            return num;
    }
}

bool login()
{
    std::cout << "User login\n\n";
    int customer_num { get_login_info() };
    std::cout << "Customer number: " << customer_num << '\n';
    g_logged_user = find_user(customer_num);
    if (g_logged_user == nullptr)
    {
        std::cout << "\nCustomer number not registered!\n\n";
        return false;
    }
    else
        return true;
}

bool sign_up()
{
    int customer_number { add_user() };
    if (customer_number > 0)
    {
        print_sign_up_success(customer_number);
        return true;
    }
    std::cout << "Something went wrong, try again!\n";
    return false;
        
}

int authentication()
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

int main()
{
    while (true)
    {
        int auth = authentication();
        if (auth == 1)
        {
            if(banking_ui())
                continue ;
            else
                return 0;
        }
        else if (auth == 0)
            return 0;
    }
}

