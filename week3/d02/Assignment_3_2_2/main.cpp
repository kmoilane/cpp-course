#include "includes/game.h"
#include <climits>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>

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
