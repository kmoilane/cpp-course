#ifndef BANK_H
#define BANK_H

#include "./structs.h"
#include <iostream>

/*
**  Evil Global variables to easily access data around the program.
**  g_highest_acc tracks the highest account number, and is incremented when
**  new accoun is created to keep them unique. g_highest_user does the same
**  with user number.
*/
inline std::vector<User>   g_bank{};
inline User*               g_logged_user { nullptr };
inline int                 g_highest_acc { 0 };
inline int                 g_highest_user { 0 };

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
Account create_account();
User    create_user(std::string new_name, std::string addr, std::string phone);
bool    sign_up();
int     ask_sign_up_info();

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
