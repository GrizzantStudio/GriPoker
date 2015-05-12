#ifndef DECK_H
#define DECK_H

#include <Card.h>
#include <vector>
#include <memory>

class Deck
{
private :

    std::vector <std::pair <std::shared_ptr <Card>, bool>> m_cards;

public:
    Deck();
    ~Deck();

public :

    std::vector <unsigned int> getAvailableCards();
    void setCardEnabled(unsigned int a_cardId, bool a_enabled);

private :

    unsigned int Deck::addCardFamily(Card::Symbol a_symbol, unsigned int a_startCardId);
};

#endif // DECK_H
