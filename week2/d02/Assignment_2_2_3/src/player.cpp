#include "../includes/board.h"
#include "../includes/player.h"
#include <iostream>


/*
**  Checks the cell above if it is in the grid and if it is obstacle or 
**  treasure.
*/
bool check_north(Matrix& map, Player& player, Cell& cell)
{
    if (player.row != 0)
    {
        if (map[player.row - 1][player.col] != cell.obstacle)
        {
            if (map[player.row - 1][player.col] == cell.treasure)
                player.points++;
            return true;
        }
    }
    return false;
}

/*
**  Checks the cell on the left if it is in the grid and if it is obstacle or 
**  treasure.
*/
bool check_west(Matrix& map, Player &player, Cell& cell)
{
    if (player.col != 0)
    {
        if (map[player.row][player.col - 1] != cell.obstacle)
        {
            if (map[player.row][player.col - 1] == cell.treasure)
                player.points++;
            return true;
        }
    }
    return false;
}

/*
**  Checks the cell below if it is in the grid and if it is obstacle or 
**  treasure.
*/
bool check_south(Matrix& map, Player& player, Cell& cell)
{
    if (player.row != 9)
    {
        if (map[player.row + 1][player.col] != cell.obstacle)
        {
            if (map[player.row + 1][player.col] == cell.treasure)
                player.points++;
            return true;
        }
    }
    return false;
}

/*
**  Checks the cell on the right if it is in the grid and if it is obstacle or 
**  treasure.
*/
bool check_east(Matrix& map, Player& player, Cell& cell)
{
    if (player.col != 9)
    {
        if (map[player.row][player.col + 1] != cell.obstacle)
        {
            if (map[player.row][player.col + 1] == cell.treasure)
                player.points++;
            return true;
        }
    }
    return false;
}

/*
**  Handles player movement based on 4 directions
*/
void move_player(char dir, Matrix& map, Player& player, Cell& cell)
{
    if (dir == 'w')
    {
        if (check_north(map, player, cell))
        {
            std::cout << "\nPlayer moves north!\n";
            map[player.row][player.col] = cell.free;
            player.row -= 1;
        }
        else
            std::cout << "\nPlayer can't move north!\n";
    }
    else if (dir == 'a')
    {
        if (check_west(map, player, cell))
        {
            std::cout << "\nPlayer moves west!\n";
            map[player.row][player.col] = cell.free;
            player.col -= 1;
        }
        else
            std::cout << "\nPlayer can't move west!\n";
    }
    else if (dir == 's')
    {
        if (check_south(map, player, cell))
        {
            std::cout << "\nPlayer moves south!\n";
            map[player.row][player.col] = cell.free;
            player.row += 1;
        }
        else
            std::cout << "\nPlayer can't move south!\n";
    }
    else if (dir == 'd')
    {
        if (check_east(map, player, cell))
        {
            std::cout << "\nPlayer moves east!\n";
            map[player.row][player.col] = cell.free;
            player.col += 1;
        }
        else
            std::cout << "\nPlayer can't move east!\n";
    }
}
