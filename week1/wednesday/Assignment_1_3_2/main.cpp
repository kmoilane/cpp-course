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
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

/*
**  Global variables to easily access data around the program.
**  highest_acc tracks the highest account number, and is incremented when
**  new accoun is created to keep them unique. g_highest_user does the same
**  with customer number.
*/
std::vector<Client> g_bank{};
Client*             g_logged_user { nullptr };
int                 g_highest_acc { 0 };
int                 g_highest_user { 0 };


/*
**  Creates a new Client with given information and returns it
*/
Client add_client(std::string new_name,std::string addr, std::string phone)
{
    Client new_user {};
    new_user.name           =   new_name;
    new_user.address        =   addr;
    new_user.phone_num      =   phone;
    new_user.customer_num   =   ++g_highest_user;
    
    Account account { new_account() };
    new_user.accounts.push_back(account);
    return new_user;
}

/*
**  Creates a new bank account and sets balance to 0
*/
Account new_account()
{
    Account new_account {};
    new_account.account_num = ++g_highest_acc;
    new_account.balance = 0;
    return new_account;
}

/*
**  Prompts user for user information and creates new Client which is pushed
**  to the global g_bank vector. Returns new users customer_num to caller.
*/
int add_user()
{
    std::string name {};
    std::string address {};
    std::string phone_num {};
    
    std::cout << "Enter your name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter your address: ";
    std::getline(std::cin >> std::ws, address);

    std::cout << "Enter your phone number: ";
    std::getline(std::cin >> std::ws, phone_num);

    Client new_user { add_client(name, address, phone_num) };

    g_bank.push_back(new_user);
    
    return new_user.customer_num;
}

/*
**  Finds user(Client) based on customer_num from global g_bank if found
**  returns the pointer to Client in g_bank, otherwise nullptr
*/
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

/*
**  Clears and ignores invalid input to std::cin
*/
void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    {
        print_invalid_option();
    }
    else
    {
        int amount { ask_amount() };
        if (amount == -1)
            print_invalid_option();
        else if (amount == 0)
        {
            std::cout << "\nYou need to enter positive value over 0\n";
        }
        else
        {
            g_logged_user->accounts[option - 1].balance += amount;
            std::cout << "\nYou have deposited " << amount << "€\n\n";
        }
    } 
}

/*
**  Sets g_logged_user to point to nullptr
*/
void logout()
{
    std::cout << "\nYou have logged out!\n\n";
    g_logged_user = nullptr;
}

/*
**  This function is called when user opens a new account. It creates the acc
**  and pushes it to the clients account vector.
*/
void open_new_account()
{
    Account new_acc { new_account() };
    g_logged_user->accounts.push_back(new_acc);
    std::cout << "You have opened a new account with a number of:\n\n"
        << new_acc.account_num << "\n\n";
}

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
**  Prompts the user in the login interface for a customer number.
*/
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

/*
**  Gets the customer number and checks if it's registered. If registered
**  g_logged_user points now to the matching Client, otherwise to nullptr
*/
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

/*
**  Calls add_user to create a new client and prints information
*/
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

/*
**  This function handles auhtentication UI and user input in it.
*/
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

/*
**  This function creates a file from the g_bank global variable in csv format.
**  It is only called at the end of the program and overwrites
**  itself on each run
*/
void create_file()
{
    std::string file_path{ "bank_db" };
    std::ofstream file_object(file_path);
    
    for (Client client : g_bank)
    {
        file_object
            << client.customer_num << ','
            << client.name << ','
            << client.address << ','
            << client.phone_num << '\n';
            for (Account acc : client.accounts)
            {
                file_object
                    << acc.account_num << ','
                    << acc.balance << '\n';
            }
            file_object << '\n';
    }
}

void load_file()
{
    std::ifstream file("bank_db");
    if (!file)
        return ;

    std::string line {};
    Client client;
    bool reading_accounts = false;

    while (std::getline(file, line))
    {
        if (line.empty()) {
            reading_accounts = false;
            g_bank.push_back(client);
            client = Client();
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

int main()
{
    load_file();
    while (true)
    {
        int auth = authentication();
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
