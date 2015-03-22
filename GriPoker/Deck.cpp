#include "Deck.h"

Deck::Deck()
{
    unsigned int cardId = addCardFamily(Card::Symbol::Spade, 0);
    cardId = addCardFamily(Card::Symbol::Heart, cardId);
    cardId = addCardFamily(Card::Symbol::Diamond, cardId);
    addCardFamily(Card::Symbol::Club, cardId);
}

Deck::~Deck()
{

}

unsigned int Deck::addCardFamily(Card::Symbol a_symbol, unsigned int a_startCardId)
{
    unsigned int id = a_startCardId;

    m_cards.push_back(std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Two)));
    m_cards.push_back(std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Three)));
    m_cards.push_back(std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Four)));
    m_cards.push_back(std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Five)));
    m_cards.push_back(std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Six)));
    m_cards.push_back(std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Seven)));
    m_cards.push_back(std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Eight)));
    m_cards.push_back(std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Nine)));
    m_cards.push_back(std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Ten)));
    m_cards.push_back(std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Jack)));
    m_cards.push_back(std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Queen)));
    m_cards.push_back(std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::King)));
    m_cards.push_back(std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Ace)));

    return id;
}
