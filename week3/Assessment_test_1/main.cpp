#include "includes/structs.h"
#include "includes/utils.h"
#include "includes/transactions.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>

bool update_transaction_file(std::vector<Transaction>& transactions)
{
    std::ofstream file("transaction_log");
    if(!file)
        return false;
    file << "User_id, transaction\n";
    for (auto transaction : transactions)
    {
        file << transaction.user_id << ',' << transaction.amount << '\n';
    }
    file.close();
    return true;
}

void print_wallet_ui()
{
    std::cout << "Welcome to bank_wallet!\n\n";
    std::cout << "1) Make a transaction\n";
    std::cout << "2) View transactions\n";
    std::cout << "3) Calculate total Expenses\n";
    std::cout << "4) Quit\n";
}

int get_user_id(std::vector<User>& users, int user_id_tracker)
{
    std::cout << "\nEnter user_id\n";
    int user_id { prompt_int_input() };
    if (!validate_int_option(user_id, user_id_tracker - users.size(), user_id_tracker))
    {
        std::cout << "\nUser not found!\n";
        return USER_NOT_FOUND;
    }
    return user_id;
}

int wallet_ui(std::vector<User>& users, std::vector<Transaction>& transactions,
    int user_id_tracker)
{
    int lowest_option { 1 };
    int highest_option { 4 };
    system("clear");
    while (true)
    {
        print_wallet_ui();
        int option = prompt_int_input();
        if (validate_int_option(option, lowest_option, highest_option))
        {
            switch (option)
            {
                case 1:
                {
                    int user_id { get_user_id(users, user_id_tracker) };
                    if (user_id == -1)
                        continue ;
                    int result = make_transaction(users, transactions, user_id);
                    if (result == 0)
                    {
                        std::cout << "\nTransaction completed\n";
                        if (!update_transaction_file(transactions))
                            std::cout << "Error saving transaction log\n";
                        continue ;
                    }
                    else if (result == -1)
                    {
                        std::cout << "Couldn't find your user\n";
                        continue ;
                    }
                    continue ;
                }
                case 2:
                {
                    int user_id { get_user_id(users, user_id_tracker) };
                    if (user_id == -1)
                        continue ;
                    view_transactions(transactions, user_id);
                    continue ;
                }
                case 3:
                {
                    int user_id { get_user_id(users, user_id_tracker) };
                    if (user_id == -1)
                        continue ;
                    calculate_expenses(transactions, user_id);
                    continue ;
                }
                case 4:
                    return 0;
            }
        }
    }
}

int main()
{
    std::vector<User>           users{};
    std::vector<Transaction>    transactions{};
    int user_id_tracker { 1000 };
    User empty_user { 0, "", 0 };
    User dummy_user1 { user_id_tracker++, "Aku Ankka", 1300.57 };
    User dummy_user2 { user_id_tracker++, "Roope Ankka", 130000000.5 };
    users.push_back(empty_user);
    users.push_back(dummy_user1);
    users.push_back(dummy_user2);
    while (true)
    {
        if (wallet_ui(users, transactions, user_id_tracker) == 0)
            return 0;
    }
}
