#ifndef BANK_H
#define BANK_H

#include "./structs.h"

Account new_account();
Client  add_client(std::string new_name, std::string addr, std::string phone);
bool banking_ui();
int authentication();

#endif
