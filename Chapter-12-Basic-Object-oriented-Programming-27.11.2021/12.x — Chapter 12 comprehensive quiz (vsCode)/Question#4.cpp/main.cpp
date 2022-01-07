#include <iostream>
#include "random.hpp" // for Random::get(min, max)
#include "PrototypeDeclaration.cpp"

int main()
{
    const Card cardQueenHearts{ Card::Rank::rank_queen, Card::Suit::heart };
    cardQueenHearts.printCard();
    std::cout << " has the value " << cardQueenHearts.value() << '\n';

    Deck deck{};
    deck.printCard();
    deck.shuffle();
    deck.printCard();

    return 0;
}