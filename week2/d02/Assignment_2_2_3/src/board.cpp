#include "../includes/board.h"
#include "../includes/player.h"
#include "../includes/utils.h"
#include <iostream>

/*
**  Creates board and fills it with player at 0,0 position and others randomly
**  with either obstacles or free cells
*/
void init_board(Matrix& map, Cell& cell)
{
    for (int i = 0; i < 10; ++i)
    {
        std::vector<char> row {};
        for (int j = 0; j < 10; ++j)
        {
            if (i == 0 && j == 0)
            {
                row.push_back(cell.player);
                continue ;
            }
            if (random_num(1, 5) == 1)
            {
                row.push_back(cell.obstacle);
            }
            else
                row.push_back(cell.free);
        }
        map.push_back(row);
    }
}

/*
**  Prints map to console
*/
void draw_map(Matrix& map, Player& player, Cell& cell)
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (i == player.row && j == player.col)
                std::cout << cell.player;
            else
                std::cout << map[i][j];
        }
        std::cout << '\n';
    }
    std::cout << "Treasures found: " << player.points << '\n';
}

/*
**  Adds 7 treasures to map, checks that cell is not player cell or doesn't
**  already have a treasure
*/
void add_treasure(Matrix& map, Cell& cell)
{
    for(int i = 0; i < 7; i++)
    {
        int row {random_num(0, 9)};
        int col {random_num(0, 9)};
        if((row == 0 && col == 0) || (map[row][col] == cell.treasure))
        {
            --i;
            continue;
        }
        else
        {
            map[row][col] = cell.treasure;
        }
    }    
}
