#include "includes/deck.hpp"
#include "includes/player.hpp"
#include <iostream>
#include <string>

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void print_scores(const Players& players)
{
    std::cout << "Scores after the round:\n";
    for (const auto& player : players)
    {
        std::cout << player.name << ": " << player.cards.total() << '\n';
    }
}

void print_draw(Player& player)
{
    std::cout << player.name << " draws: " << player.cards.top() << " with now total of: ";
    std::cout << player.cards.total() << '\n';
}

void print_winner(const Player& player)
{
    if (player.dealer)
        std::cout << "\nHouse wins with " << player.cards.total() << '\n';
    else
        std::cout << "\n" << player.name << " wins with " << player.cards.total() << '\n';
}

void print_hold(const Player& player)
{
    std::cout << player.name << " holds at " << player.cards.total() << '\n';
}

void print_out(const Player& player)
{
    std::cout << player.name << " is out and skipped!\n";
}

void print_tie()
{
    std::cout << "\nIt's a tie! House wins... :)\n";
}

int prompt_int_input()
{
    while (true)
    {
        int input {};
        std::cin >> input;
        if (!std::cin)
        {
            clear_cin();
            std::cout << "\nInvalid input!\n";
            continue ;
        }
        return input;
    }
}

int ask_action()
{
    std::cout << "Select action:\n";
    std::cout << "1) Draw\n";
    std::cout << "2) Hold\n";
    int action{};
    while (true)
    {
        action = prompt_int_input();
        if (action == 1 || action == 2)
            break;
        std::cout << "\nInvalid option\n";
    }

    return action;
}

int game_loop(int player_count)
{
    Deck deck(Fullness::full);
    deck.shuffle();
    Players players;
    for (int i = 0; i < player_count; i++)
    {
        players.push_back(
            {std::string("Player") + std::to_string(i), Deck(Fullness::empty)});
    }
    players.push_back({"Dealer", Deck(Fullness::empty), true});

    int out_count = 0;
    while (out_count < players.size())
    {
        for (auto& player : players)
        {
            if(player.state == State::out)
            {
                print_out(player);
                continue;
            }
            if (player.state == State::hold)
            {
                print_hold(player);
            }
            int action = ask_action();
            if (action == 1)
            {
                player.state = State::draw;
                player.cards.add(deck.draw());
                print_draw(player);
                if (player.cards.total() == 21)
                {
                    print_winner(player);
                    return 0;
                }
                if (player.cards.total() > 21)
                {
                    player.state = State::out;
                    out_count++;
                }
            }

            else if(action == 2)
            {
                player.state = State::hold;
                std::cout << player.name << " holds at " << player.cards.total() << '\n';
                continue;
            }

            std::cout << '\n';
        }
        if (out_count == players.size())
        {
            std::cout << "Everyone went over 21!\n";
            return 0;
        }
        
    }
    return 0;
}

int main()
{
    std::cout << "Twenty-One\n";
    std::cout << "Enter the amount of players (1-5):\n";
    int amount {};
    while (true)
    {
        amount = prompt_int_input();
        if (amount > 0 && amount <= 5)
            break;
        std::cout << "Invalid amount!\n";
    }

    return game_loop(amount);
}
