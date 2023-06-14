#include "../includes/Food.h"
#include <iostream>
#include <vector>

/*
**  Prints the food name, price and all the ingredients
*/

void print_food(Food& order)
{
    std::cout << "Food: " << order.name << '\n';
    std::cout << "Price: " << order.price << "€\n";
    std::cout << "Ingredients: ";
    for (auto ingredient : order.ingredients)
    {
        std::cout << ingredient;
        if (ingredient != order.ingredients.back())
            std::cout << ", ";
    }
    std::cout << '\n';
}

/*
**  Allows user to add new foods to the menu
*/
void add_food(Menu& food_menu)
{
    std::cout << "Enter the name of the food: ";
    Food new_food {};
    std::getline(std::cin >> std::ws, new_food.name);
    std::cout << "Enter the price: ";
    std::cin >> new_food.price;
    std::cout << "Enter ingredient: ";
    std::string ingredient {};
    std::getline(std::cin >> std::ws, ingredient);
    new_food.ingredients.push_back(ingredient);
    while (true)
    {
        std::cout << "\n1) Add new ingredient\n";
        std::cout << "2) Done\n";
        bool exit_loop { false };
        while (true)
        {
            int option {};
            std::cin >> option;
            if (option == 1)
            {
                std::cout << "Enter ingredient: ";
                std::getline(std::cin >> std::ws, ingredient);
                new_food.ingredients.push_back(ingredient);
                break ;
            }
            if (option == 2)
            {
                exit_loop = true;
                break ;
            }
            else
                std::cout << "\nInvalid option!\n";
        }
        if (exit_loop)
            break ;
    }
    food_menu.foods.push_back(new_food);
    std::cout << "\nFood added!\n";
}

/*
**  Loops through menu and sends every food to be printed
*/
void print_menu(Menu& food_menu)
{
    for (auto food : food_menu.foods)
    {
        print_food(food);
        std::cout << '\n';
    }
}
