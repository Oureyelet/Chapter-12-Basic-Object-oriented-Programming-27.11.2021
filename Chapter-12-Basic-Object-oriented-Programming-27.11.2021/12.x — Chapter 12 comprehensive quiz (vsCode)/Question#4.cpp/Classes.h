#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <cassert>
#include <array>

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

    void printCard() const;
    int value() const;
    
};



class Deck
{
private:
    std::array<Card, 52> m_deck;

public:
    //Constructor:
    Deck();

    friend class Card;

    friend void Card::printCard()const;

    void printDeck(const Deck& deck);
    
};


#endif // end CLASSES_H.