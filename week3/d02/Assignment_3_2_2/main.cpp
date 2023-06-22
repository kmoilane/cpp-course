#include "includes/game.h"
#include <climits>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>

void fill_board(GameBoard &game_board)
{
    for (int i = 0; i < 3; i++)
    {
        std::vector<char> row;

        for (int j = 0; j < 3; j++)
        {
            row.push_back(EMPTY);
        }
        game_board.push_back(row);
    }
}

void print_board(const GameBoard &game_board)
{
    std::cout << "  A   B   C\n";
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << i << ' ';
        for (int j = 0; j < SIZE; ++j)
        {
            if (j == 0 || j == 1)
                std::cout << game_board[i][j] << " | ";
            else
                std::cout << game_board[i][j];
        }
        std::cout << '\n';
        if (i == 0 || i == 1)
            std::cout << "  ----------\n";
    }
}

int parse_string(std::pair<int, int> &position, std::string str)
{
    if ((str[1] == '0') || (str[1] == '1') || (str[1] == '2'))
        position.first = str[1] - '0';
    else
        return 1;

    if ((str[0] == 'A') || (str[0] == 'a'))
        position.second = 0;
    else if ((str[0] == 'B') || (str[0] == 'b'))
        position.second = 1;
    else if ((str[0] == 'C') || (str[0] == 'c'))
        position.second = 2;
    else
        return 1;

    return 0;
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

/*
**  check if game board is full
*/
bool is_board_full(const std::vector<std::vector<char>> &game_board)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (game_board[i][j] == EMPTY)
                return false;
        }
    }
    return true;
}

/*
**  Updates board with correct char based on who's turn it is
*/
void update_board(GameBoard &game_board, const std::pair<int, int> &position,
    const bool &player_1)
{
    if (player_1)
    {
        game_board[position.first][position.second] = PLAYER_1;
    }
    else
    {
        game_board[position.first][position.second] = PLAYER_2;
    }
}

/*
**  Changes the turn of the player by swapping player_1 to true or false
*/
void change_turn(bool &player_1) { player_1 = !player_1; }

/*
**  Checks if either of the players has won, or if game board is full and it's
**  a draw.
*/
int check_board(const GameBoard& game_board)
{
    // Check rows
    for (int i = 0; i < SIZE; ++i) {
        if (game_board[i][0] != EMPTY && game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2]) {
            if (game_board[i][0] == PLAYER_1)
                return 1;
            else if (game_board[i][0] == PLAYER_2)
                return -1;
        }
    }

    // Check columns
    for (int j = 0; j < SIZE; ++j) {
        if (game_board[0][j] != EMPTY && game_board[0][j] == game_board[1][j] && game_board[1][j] == game_board[2][j]) {
            if (game_board[0][j] == PLAYER_1)
                return 1;
            else if (game_board[0][j] == PLAYER_2)
                return -1;
        }
    }

    // Check diagonals
    if (game_board[0][0] != EMPTY && game_board[0][0] == game_board[1][1] && game_board[1][1] == game_board[2][2]) {
        if (game_board[0][0] == PLAYER_1)
            return 1;
        else if (game_board[0][0] == PLAYER_2)
            return -1;
    }

    if (game_board[0][2] != EMPTY && game_board[0][2] == game_board[1][1] && game_board[1][1] == game_board[2][0]) {
        if (game_board[0][2] == PLAYER_1)
            return 1;
        else if (game_board[0][2] == PLAYER_2)
            return -1;
    }

    // If no winner and no free cells, it's a draw
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (game_board[i][j] == EMPTY)
                return 0;
        }
    }

    // Game is still going
    return INT_MIN;
}

/*
**  Function checks all possible moves
*/
std::vector<std::pair<int, int>> possible_moves(const std::vector<std::vector<char>> &game_board)
{
    std::vector<std::pair<int, int>> moves{};
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (game_board.at(i).at(j) == EMPTY)
            {
                moves.push_back(std::make_pair(i, j));
            }
        }
    }
    return moves;
}


std::pair<int, int> find_best_move(const GameBoard& game_board)
{
    std::pair<int, int> best_move{};
    int best_eval = INT_MAX;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (game_board[i][j] == EMPTY)
            {
                GameBoard temp_board = game_board;
                temp_board[i][j] = PLAYER_2;
                int eval = minimax(temp_board, 0, true);
                
                if (eval < best_eval)
                {
                    best_eval = eval;
                    best_move = std::make_pair(i, j);
                }
            }
        }
    }
    return best_move;
}

int minimax(GameBoard game_board, int depth, bool player_1)
{
    int score = check_board(game_board);
    if (score == 1)
        return 10 - depth;
    else if (score == -1)
        return -10 + depth;
    else if (is_board_full(game_board))
        return 0;

    if (player_1)
    {
        int highest_score = INT_MIN;
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                if (game_board[i][j] == EMPTY)
                {
                    game_board[i][j] = PLAYER_1;
                    int current_score = minimax(game_board, depth + 1, false);
                    highest_score = std::max(highest_score, current_score);
                    game_board[i][j] = EMPTY;
                }
            }
        }
        return highest_score;
    }
    else
    {
        int highest_score = INT_MAX;
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                if (game_board[i][j] == EMPTY)
                {
                    game_board[i][j] = PLAYER_2;
                    int current_score = minimax(game_board, depth + 1, true);
                    highest_score = std::min(highest_score, current_score);
                    game_board[i][j] = EMPTY;
                }
            }
        }
        return highest_score;
    }
}

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
        std::cin.ignore() >> cmd;
        if (!std::cin)
        {
            std::cout << "Invalid input\n";
            clear_cin();
            continue;
        }
        return cmd;
    }
}

int game_over_loop()
{
    while (true)
    {
        std::cout << "1) Main menu\n2) Quit Game\n";
        int option { get_input() };
        if (option == 1)
        {
            system("clear");
            return 1;
        }
        else if (option == 2)
        {
            std::cout << "Bye bye!\n";
            return 0;
        }
    }

}

int game_loop(bool ai_minimax)
{
    GameBoard game_board{};
    std::pair<int, int> position{};
    bool player_1 = true;

    system("clear");

    fill_board(game_board);
    print_board(game_board);

    while (true)
    {
        if (ai_minimax && !player_1)
        {
            position = find_best_move(game_board);
        }
        else
        {
            position = get_position(game_board);
        }
        update_board(game_board, position, player_1);
        system("clear");
        print_board(game_board);
        int winner = check_board(game_board);
        if (winner && winner != INT_MIN)
        {
            if(winner == 1)
            {
                std::cout << "\nPlayer 1 won!\n\n";
            }
            else{
                std::cout << "\nPlayer 2 won!\n\n";
            }
            return game_over_loop();
        }
        if (is_board_full(game_board))
        {
            std::cout << "\nIt's a draw.\n\n";
            return game_over_loop();
        }
        change_turn(player_1);
    }
}

int main()
{
    bool ai_minimax{true};
    system("clear");
    while (true)
    {
        std::cout << "\nZic-Zac-Zoe\n\n";
        std::cout << "1) Multiplayer \n2) Play against Zoe\n3) Quit Game\n";
        int cmd{get_input()};

        if (cmd == 1)
        {
            ai_minimax = false;
        }
        else if (cmd == 2)
        {
            ai_minimax = true;
        }
        else if (cmd == 3)
        {
            return 0;
        }
        else
        {
            continue;
        }
        int option {game_loop(ai_minimax)};
        if (option == 1)
            continue ;
        else if (option == 0)
            return 0;
    }

    return 0;
}
