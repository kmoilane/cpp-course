#ifndef DECK_HPP
#define DECK_HPP

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

struct Card
{
    int value;
    std::string suite;
};

inline std::ostream& operator<<(std::ostream& os, const Card& card)
{
    os << card.value << " of " << card.suite;
    return os;
}

enum class Fullness
{
    full,
    empty,
};

class Deck
{
    public:
        using value_type        = Card;
        using reference         = Card&;
        using const_reference   = const Card&;
        using storage_type      = std::vector<value_type>;
        using iterator          = storage_type::iterator;
        using const_iterator    = storage_type::const_iterator;
        using difference_type   = storage_type::difference_type;
        using size_type         = storage_type::size_type;

        Deck(Fullness fullnes);
        void            shuffle();
        value_type      draw();
        void            add(Card card);
        reference       top()       { return cards.back(); }
        reference       bottom()    { return cards.front(); }
        iterator        end()       { return cards.end(); }
        const_iterator  cend()      { return cards.cend(); }
        iterator        begin()     { return cards.begin(); }
        const_iterator  cbegin()    { return cards.cbegin(); }
        size_type       size()      { return cards.size(); }
        int             total();
        const int       total() const;

    private:
        storage_type cards {};
        int             total_min();
        int             total_max();
        const int       total_min() const;
        const int       total_max() const;

};

Deck::Deck(Fullness fullness)
{
    if (fullness == Fullness::empty)
        return;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 2; j < 15; j++)
        {
            if (i == 0)
                cards.push_back({j, "Clubs"});
            else if (i == 1)
                cards.push_back({j, "Diamonds"});
            else if (i == 2 )
                cards.push_back({j, "Hearts"});
            else
                cards.push_back({j, "Spades"});
        }
    }
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
 
    std::shuffle(cards.begin(), cards.end(), g);
 
}

Card Deck::draw()
{
    Card card { cards.back() };
    cards.pop_back();
    return card;
}

void Deck::add(Card card)
{
    cards.push_back(card);
}

int Deck::total_max()
{
    int total {0};
    for (const value_type& card : cards)
    {
        total += card.value;
    }
    return total;
}

int Deck::total_min()
{
    int total {0};
    for (const value_type& card : cards)
    {
        if (card.value == 14)
            total++;
        else
            total += card.value;
    }
    return total;
}

int Deck::total()
{
    if (total_max() <= 21)
        return total_max();
    return total_min();
}

const int Deck::total_max() const
{
    int total {0};
    for (const value_type& card : cards)
    {
        total += card.value;
    }
    return total;
}

const int Deck::total_min() const
{
    int total {0};
    for (const value_type& card : cards)
    {
        if (card.value == 14)
            total++;
        else
            total += card.value;
    }
    return total;
}

const int Deck::total() const
{
    if (total_max() <= 21)
        return total_max();
    return total_min();
}

#endif
