#include "includes/board.h"
#include "includes/player.h"
#include "includes/utils.h"
#include <iostream>

bool victory(Player& player)
{
    if (player.col == 9 && player.points >= 5)
        return true;
    return false;
}

/*
**  Main game loop
*/
int main()
{
    Matrix map {};
    Player player {};
    Cell cell {};

    init_board(map, cell);
    add_treasure(map, cell);
    
    while (true)
    {
        draw_map(map, player, cell);
        if (victory(player))
        {
            std::cout << "\n\nYOU WON!\n\n";
            return 0;
        }
        print_options();
        char option {};
        std::cin >> option;
        clear_cin();
        if (option == 'q')
        {
            return 0;
        }
        else if (option == 'w' || option == 'a'
            || option == 's' || option == 'd')
        {
            move_player(option, map, player, cell);
        }
        else
        {
            std::cout << "Invalid option!\n";
            continue ;
        }
        
    }
    
}
