#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
    int row { 0 };
    int col { 0 };
    int points { 0 };
};

void    move_player(char dir, Matrix& map, Player& player, Cell& cell);
bool    check_east(Matrix& map, Player& player, Cell& cell);
bool    check_south(Matrix& map, Player& player, Cell& cell);
bool    check_west(Matrix& map, Player &player, Cell& cell);
bool    check_north(Matrix& map, Player& player, Cell& cell);

#endif
