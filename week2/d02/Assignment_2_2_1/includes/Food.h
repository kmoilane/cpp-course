#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include <vector>

struct Food
{
    std::string name {};
    double  price {};
    std::vector<std::string> ingredients {};
};

struct Menu
{
    std::vector<Food> foods {};
};

struct Order
{
    std::string food {};
    double  price {};
};

void    print_food(Food& order);
void    add_food(Menu& food_menu);
void    print_menu(Menu& food_menu);
void    clear_cin();
Order   make_order(Menu& food_menu);
void    print_order_menu(Menu& food_menu);
void    view_order(std::vector<Order>& orders);

#endif
