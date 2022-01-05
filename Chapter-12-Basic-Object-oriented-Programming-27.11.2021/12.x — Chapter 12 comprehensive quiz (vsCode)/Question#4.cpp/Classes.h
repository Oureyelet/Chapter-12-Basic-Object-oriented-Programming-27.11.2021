#ifndef CLASSES_H
#define CLASSES_H

class Card
{
public:
    enum class CardSuit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

    enum class CardRank
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
    CardRank m_rank{};
    CardSuit m_suit{};

public:
    Card(CardSuit suit = Card::CardSuit::club, CardRank rank = Card::CardRank::rank_2)
        : m_suit{ suit }, m_rank{ rank }
    {

    }
    
};

#endif // end CLASSES_H.