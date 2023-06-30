#include "../includes/game.h"
#include <iostream>
#include <limits>
#include <vector>


void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int get_input()
{
    while (true)
    {
        int cmd{};
        std::cin >> cmd;
        if (!std::cin || std::cin.eof() == 1)
        {
            std::cout << "Invalid input\n";
            clear_cin();
            continue;
        }
        return cmd;
    }
}


/*
**  Function checks that the position is right formated and empty
*/
std::pair<int, int> get_position(const GameBoard &game_board)
{
    std::pair<int, int> position;
    while (true)
    {
        std::cout << "Give position row and column: ";
        std::string line{};
        std::getline(std::cin >> std::ws, line);
        int valid_input = parse_string(position, line);
        if (valid_input == 1)
        {
            std::cout << "Invalid input.\n";
            continue;
        }
        else if (game_board[position.first][position.second] != EMPTY)
        {
            std::cout << "Position is not free.\n";
            continue;
        }
        break;
    }
    return position;
}
