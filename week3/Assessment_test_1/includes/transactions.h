#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "structs.h"
#include <vector>

int make_transaction(std::vector<User>& users,
std::vector<Transaction>& transactions, int user_id);
int withdraw(User& user, std::vector<Transaction>& transactions);
int deposit(User& user, std::vector<Transaction>& transactions);
bool validate_deposit(double amount, double balance);
bool validate_withdraw(double amount, double balance);
void view_transactions(std::vector<Transaction> transactions, int user_id);
void calculate_expenses(std::vector<Transaction> transactions, int user_id);

#endif
