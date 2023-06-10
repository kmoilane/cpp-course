#ifndef BANK_H
#define BANK_H

#include "./structs.h"
#include <iostream>

//  File management functions
void    load_file();
void    create_file();

//  UI functions
int     authentication_ui();
bool    banking_ui();

//  Login functions
User*   find_user(int num);
int     get_login_info();
bool    login();

//  Signup and User creation functions
Account new_account();
User    add_client(std::string new_name, std::string addr, std::string phone);
bool    sign_up();
int     add_user();

//  User action functions
void    deposit();
void    withdraw();
void    view_balance();
void    open_new_account();
void    logout();
int     ask_amount();
size_t  select_account();

//  Print functions
void    print_sign_up_success(int customer_number);
void    print_invalid_amount();
void    print_auth_options();
void    print_ui_options();
void    print_invalid_option();

//  Utility functions
void    clear_cin();

#endif
