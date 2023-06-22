#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>

struct User
{
    int         user_id { 0 };
    std::string name {};
    double      balance {};
};

struct Transaction
{
    int     user_id {};
    double  amount {};
};

#endif
