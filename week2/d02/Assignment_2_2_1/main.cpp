#include "../includes/Food.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*
**  Prints options menu for user
*/
int menu()
{
    std::cout << "1) Add Food\n";
    std::cout << "2) Print Menu\n";
    std::cout << "3) Make an order\n";
    std::cout << "4) View order\n";
    std::cout << "5) Exit\n";
    int option {};
    std::cin >> option;
    if (!std::cin)
    {
        clear_cin();
        return 0;
    }
    else return option;
}

int main()
{
    Menu food_menu {};
    std::vector<Order> orders {};
    food_menu.foods.push_back({"Greece salad", 9.90, {"Iceberg lettuce", "Cherry tomatoes",
        "Cucumber", "Kalamata olives", "Feta cheese"}});

    while (true)
    {
        int option {menu()};
        if (option == 1)
        {
            add_food(food_menu);
        }
        else if (option == 2)
            print_menu(food_menu);
        else if (option == 3)
            orders.push_back(make_order(food_menu));
        else if (option == 4)
            view_order(orders);
        else if (option == 5)
            return 0;
        else
            std::cout << "\nInvalid option!\n\n";
    }

    return 0;
}
