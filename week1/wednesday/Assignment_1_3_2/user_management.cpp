#include "bank.h"
#include "structs.h"
#include <iostream>
#include <vector>

/*
**  Sets g_logged_user to point to nullptr
*/
void logout()
{
    std::cout << "\nYou have logged out!\n\n";
    g_logged_user = nullptr;
}

/*
**  Finds user based on customer_num from global g_bank if found
**  returns the pointer to User in g_bank, otherwise nullptr
*/
User* find_user(int num)
{
    for (User& client : g_bank)
    {
        if (client.customer_num == num)
        {
            return &client;
        }
    }
    return nullptr;
}

/*
**  Prompts the user in the login interface for a user number.
*/
int get_login_info()
{
    std::cout << "Enter your user number: ";
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
**  Gets the user number and checks if it's registered. If registered
**  g_logged_user points now to the matching User, otherwise to nullptr
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
**  Creates a new User with given information and returns it
*/
User create_user(std::string new_name,std::string addr, std::string phone)
{
    User new_user {};
    new_user.name           =   new_name;
    new_user.address        =   addr;
    new_user.phone_num      =   phone;
    new_user.customer_num   =   ++g_highest_user;
    
    Account account { create_account() };
    new_user.accounts.push_back(account);
    return new_user;
}


/*
**  Prompts user for an input based on msg and checks that the
**  input has no commas. Returns user input when proper string given.
*/
std::string get_valid_string(std::string msg)
{
    while (true)
    {
        std::string return_str {};
        std::size_t found {};
        std::cout << msg;
        std::getline(std::cin >> std::ws, return_str);
        found = return_str.find(',');
        if (found == std::string::npos)
        {
            return return_str;
        }
        else
            std::cout << "\nInput can't contain any commas (,)!\n";
    }
}

/*
**  Gets user input and creates new User which is pushed
**  to the global g_bank vector. Returns the new users customer_num to caller.
*/
int ask_sign_up_info()
{
    std::string name { get_valid_string("Enter your name: ") };
    std::string address { get_valid_string("Enter your address: ") };
    std::string phone_num { get_valid_string("Enter your phone number: ") };

    User new_user { create_user(name, address, phone_num) };

    g_bank.push_back(new_user);
    
    return new_user.customer_num;
}

/*
**  Calls add_user to create a new client and prints information
*/
bool sign_up()
{
    int customer_number { ask_sign_up_info() };
    if (customer_number > 0)
    {
        print_sign_up_success(customer_number);
        return true;
    }
    std::cout << "Something went wrong, try again!\n";
    return false;
        
}
