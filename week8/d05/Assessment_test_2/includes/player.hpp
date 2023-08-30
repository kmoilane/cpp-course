#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "deck.hpp"
#include <string>
#include <vector>

enum class State
{
    draw,
    hold,
    out,
};

class Player
{
    public:
        std::string name {};
        Deck cards;
        bool dealer {false};
        State state {State::draw};
};

using Players = std::vector<Player>;

#endif
