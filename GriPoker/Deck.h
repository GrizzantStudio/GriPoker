#ifndef DECK_H
#define DECK_H

#include <Card.h>
#include <vector>
#include <memory>

class Deck
{
private :

    std::vector <std::shared_ptr <Card>> m_cards;

public:
    Deck();
    ~Deck();

private :

    unsigned int Deck::addCardFamily(Card::Symbol a_symbol, unsigned int a_startCardId);
};

#endif // DECK_H
