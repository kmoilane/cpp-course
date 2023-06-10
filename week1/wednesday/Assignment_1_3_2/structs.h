#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <vector>

struct Account
{
    int     account_num {};
    int     balance {};
};

struct User
{
    int                     customer_num {};
    std::string             name {};
    std::string             address {};
    std::string             phone_num {};
    std::vector<Account>    accounts {};
};

#endif
