#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

#define SIZE 3
#define EMPTY ' '
#define PLAYER_1 'X'
#define PLAYER_2 'O'

using GameBoard = std::vector<std::vector<char>>;

int minimax(GameBoard game_board, int depth, bool player_1);
void fill_board(GameBoard &game_board);
void print_board(const GameBoard &game_board);
int parse_string(std::pair<int, int> &position, std::string str);
std::pair<int, int> get_position(const GameBoard &game_board);
bool is_board_full(const std::vector<std::vector<char>> &game_board);
void update_board(GameBoard &game_board, const std::pair<int, int> &position,
                    const bool &player_1);
void change_turn(bool &player_1);
int check_board(const GameBoard& game_board);
std::vector<std::pair<int, int>> possible_moves(
                    const std::vector<std::vector<char>> &game_board);
std::pair<int, int> find_best_move(const GameBoard& game_board);
int minimax(GameBoard game_board, int depth, bool player_1);
void clear_cin();
int get_input();
int game_over_loop();
int game_loop(bool ai_minimax);

#endif
