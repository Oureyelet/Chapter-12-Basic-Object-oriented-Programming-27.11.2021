#include <iostream>
#include "random.hpp" // for Random::get(min, max)
#include "PrototypeDeclaration.cpp"
#include <random> // for std::mt19937
#include <algorithm> // for std::shuffle

int main()
{
    const Card cardQueenHearts{ Card::Rank::rank_queen, Card::Suit::heart };
    cardQueenHearts.printCard();
    std::cout << " has the value " << cardQueenHearts.value() << '\n';

    Deck deck{};
    
    deck.shuffleDeck();
    deck.printDeck();

    std::cout << "The first card has value: " << deck.dealCard().value()<< '\n';
    std::cout << "The second card has value: " << deck.dealCard().value() << '\n';

    return 0;
}