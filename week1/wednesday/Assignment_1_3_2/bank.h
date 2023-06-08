#ifndef BANK_H
#define BANK_H

#include "./structs.h"

Account new_account();
Client  add_client(std::string new_name, std::string addr, std::string phone);
bool    banking_ui();
int     authentication();
Client* find_user(int num);
void    clear_cin();
void    view_balance();
void    withdraw();
void    deposit();
void    print_ui_options();
void    print_invalid_option();
void    logout();
void    open_new_account();
bool    banking_ui();
void    print_auth_options();
int     get_login_info();
bool    login();
bool    sign_up();
int     authentication();
int     add_user();
void    sign_up_success_prints(int customer_number);

#endif
