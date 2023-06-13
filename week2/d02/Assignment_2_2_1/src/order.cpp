#include "../includes/Food.h"
#include <iostream>
#include <string>
#include <vector>



void view_order(std::vector<Order>& orders)
{
    double total { 0 };
    int i { 1 };
    std::cout << "\nYour current order:\n\n";
    for (auto order : orders)
    {
        total += order.price;
        std::cout << i << ") " << order.food << '\n';
        ++i;
    }
    std::cout << "\nTotal price is: " << total << "€\n\n";
}

void print_order_menu(Menu& food_menu)
{
    int i = 1;
    for (auto food : food_menu.foods)
    {
        std::cout << "Select the food to be added to your order:\n";
        std::cout << i << ") " << food.name << "\t- " << food.price << "€\n";
        ++i;
    }
}

Order make_order(Menu& food_menu)
{
    size_t options = food_menu.foods.size();
    Order new_order {};
    
    while (true)
    {
        print_order_menu(food_menu);
        size_t option {};
        std::cin >> option;
        if (!std::cin)
        {
            clear_cin();
            std::cout << "\nInvalid option!\n\n";
        }
        else if (option > 0 && option <= options)
        {
            new_order.food = food_menu.foods[option - 1].name;
            new_order.price = food_menu.foods[option - 1].price;
            std::cout << '\n' << new_order.food << " added to your order!\n\n";
            return new_order;
        }
        else
            std::cout << "\nInvalid option!\n\n";
    }
}
