#include "../includes/structs.h"
#include "../includes/utils.h"
#include "../includes/transactions.h"
#include <iostream>
#include <limits>
#include <vector>

User& get_user(std::vector<User>& users, int user_id)
{
    for (User& user : users)
    {
        if (user.user_id == user_id)
            return user;
    }
    return users[0];
}

void print_transaction_options()
{
    std::cout << "\nSelect transaction\n\n";
    std::cout << "1) Deposit\n";
    std::cout << "2) Withdraw\n";
    std::cout << "3) Back\n";
    std::cout << "4) Quit\n";
}

bool validate_withdraw(double amount, double balance)
{
    if ((amount <= 0) || (balance - amount < 0))
        return false;
    return true;
}

int withdraw(User& user, std::vector<Transaction>& transactions)
{
    std::cout << "Withdrawing money\nEnter amount: ";
    double amount { prompt_double_input() };
    if (validate_withdraw(amount, user.balance))
    {
        Transaction new_transaction { user.user_id, -amount };
        transactions.push_back(new_transaction);
        user.balance -= amount;
        return 0;
    }
    else
        return INVALID_TRANSACTION;
}

bool validate_deposit(double amount, double balance)
{
    if ((amount <= 0) || (amount + balance >= std::numeric_limits<double>::max())
    || (amount + balance < 0))
        return false;
    return true;
}

int deposit(User& user, std::vector<Transaction>& transactions)
{
    std::cout << "Depositing money\nEnter amount: ";
    double amount { prompt_double_input() };
    if (validate_deposit(amount, user.balance))
    {
        Transaction new_transaction { user.user_id, amount };
        transactions.push_back(new_transaction);
        user.balance += amount;
        return 0;
    }
    else
        return INVALID_TRANSACTION;
}

int make_transaction(std::vector<User>& users,
std::vector<Transaction>& transactions, int user_id)
{
    User& current_user = get_user(users, user_id);
    if (current_user.user_id == 0)
        return USER_NOT_FOUND;

    system("clear");
    while (true)
    {
        print_transaction_options();
        int option  { prompt_int_input() };
        int min     { 1 };
        int max     { 4 };
        if (!validate_int_option(option, min, max))
        {
            std::cout << "\nInvalid option!\n";
            continue ;
        }
        else if (option == 1)
        {
            if (deposit(current_user, transactions) == 0)
                return 0;
            std::cout << "\nInvalid transaction, try again!\n";
            continue;
        }
        else if (option == 2)
        {
            if (withdraw(current_user, transactions) == 0)
                return 0;
            std::cout << "\nInvalid transaction, try again!\n";
            continue;
        }
        else if (option == 3)
        {
            return 1;
        }
        else
            std::exit(0);

    }
}


void view_transactions(std::vector<Transaction> transactions, int user_id)
{
    system("clear");
    std::cout << "Transactions for user " << user_id << ":\n\n";
    int count = 0;
    for (Transaction transaction : transactions)
    {
        if (transaction.user_id == user_id)
        {
            if (transaction.amount < 0)
                std::cout << "Withdraw: " << -transaction.amount << '\n';
            else
                std::cout << "Deposit: " << transaction.amount << '\n';
            count++;
        }
    }
    if (count == 0)
        std::cout << "No transactions for this user!\n";
    while(true)
    {
        std::cout << "\n1) Back\n";
        int option { prompt_int_input() };
        if (option == 1)
            return ;
    }
}

void calculate_expenses(std::vector<Transaction> transactions, int user_id)
{
    system("clear");
    double expenses = 0;
    for (Transaction transaction : transactions)
    {
        if (transaction.user_id == user_id)
        {
            if (transaction.amount < 0)
                expenses += -transaction.amount;
        }
    }
    
    std::cout << "Total expenses for user " << user_id << ": "
    << expenses << "\n\n";
    while(true)
    {
        std::cout << "\n1) Back\n";
        int option { prompt_int_input() };
        if (option == 1)
            return ;
    }
}
