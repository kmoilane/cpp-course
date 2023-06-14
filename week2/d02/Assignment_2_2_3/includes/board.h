#ifndef BOARD_H
#define BOARD_H

#include <chrono>
#include <random>
#include <vector>

struct Player;

struct Cell
{
    char    obstacle { 'O' };
    char    free { ' ' };
    char    player { 'A' };
    char    treasure { 'T' };
};

using Matrix = std::vector<std::vector<char>>;

void init_board(Matrix& map, Cell& cell);
void add_treasure(Matrix& map, Cell& cell);
void init_board(Matrix& map, Cell& cell);
void draw_map(Matrix& map, Player& player, Cell& cell);

#endif
