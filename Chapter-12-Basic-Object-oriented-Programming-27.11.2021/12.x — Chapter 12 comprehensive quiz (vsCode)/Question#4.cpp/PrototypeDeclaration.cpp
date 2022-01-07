#include "Classes.h"

Card::Card(Rank rank, Suit suit)
    : m_suit{ suit }, m_rank{ rank }
{
}

Card::Card()
{
    m_rank = Rank::rank_2;
    m_suit = Suit::club;
}

void Card::printCard() const
{
    switch (m_rank)
    {
        case Rank::rank_2:      std::cout << '2';   break;
        case Rank::rank_3:      std::cout << '3';   break;
        case Rank::rank_4:      std::cout << '4';   break;
        case Rank::rank_5:      std::cout << '5';   break;
        case Rank::rank_6:      std::cout << '6';   break;
        case Rank::rank_7:      std::cout << '7';   break;
        case Rank::rank_8:      std::cout << '8';   break;
        case Rank::rank_9:      std::cout << '9';   break;
        case Rank::rank_10:     std::cout << 'T';   break;
        case Rank::rank_jack:   std::cout << 'J';   break;
        case Rank::rank_queen:  std::cout << 'Q';   break;
        case Rank::rank_king:   std::cout << 'K';   break;
        case Rank::rank_ace:    std::cout << 'A';   break;
        default:
            std::cout << '?';
            break;
    }

    switch (m_suit)
    {
        case Suit::club:       std::cout << 'C';   break;
        case Suit::diamond:    std::cout << 'D';   break;
        case Suit::heart:      std::cout << 'H';   break;
        case Suit::spade:      std::cout << 'S';   break;
        default:
            std::cout << '?';
            break;
    }
}

int Card::value() const
{
    switch (m_rank)
    {
        case Rank::rank_2:        return 2;
        case Rank::rank_3:        return 3;
        case Rank::rank_4:        return 4;
        case Rank::rank_5:        return 5;
        case Rank::rank_6:        return 6;
        case Rank::rank_7:        return 7;
        case Rank::rank_8:        return 8;
        case Rank::rank_9:        return 9;
        case Rank::rank_10:       return 10;
        case Rank::rank_jack:     return 10;
        case Rank::rank_queen:    return 10;
        case Rank::rank_king:     return 10;
        case Rank::rank_ace:      return 11;
        default:
            assert(false && "should never happen");
            return 0;
    }
}

Deck::Deck()
{
    std::array<Card, 52>::size_type index{ 0 };

    for (int suit{ 0 }; suit < static_cast<int>(Card::Suit::max_suits); ++suit)
    {
        for (int rank{ 0 }; rank < static_cast<int>(Card::Rank::max_ranks); ++rank)
        {
            Deck::m_deck[index] = { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) };
            ++index;
        }
    }
}

void Deck::printDeck(const Deck& deck)
{
    for (const auto& card : deck)
    {
        //Card::printCard().deck;
        std::cout << ' ';
    }

    std::cout << '\n';
}