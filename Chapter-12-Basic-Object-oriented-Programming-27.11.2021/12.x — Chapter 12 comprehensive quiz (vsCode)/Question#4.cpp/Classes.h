#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <cassert>
#include <array>

using deck_type = std::array<int, 52>;
using index_type = deck_type::size_type;

class Card
{
public:
    enum class Suit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

    enum class Rank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_ranks
    };

private:
    Rank m_rank{};
    Suit m_suit{};

public:
    Card(Rank rank, Suit suit);
    Card();

    void print() const;
    int value() const;
    
};



class Deck
{
private:
    deck_type m_deck;

public:
    //Constructor:
    Deck()
    {
        //m_deck
    }

    friend class Card;

    deck_type createDeck();



    
};


#endif // end CLASSES_H.