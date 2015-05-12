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

    m_cards.push_back(std::pair <std::shared_ptr <Card>, bool> (std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Two)), true));
    m_cards.push_back(std::pair <std::shared_ptr <Card>, bool> (std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Three)), true));
    m_cards.push_back(std::pair <std::shared_ptr <Card>, bool> (std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Four)), true));
    m_cards.push_back(std::pair <std::shared_ptr <Card>, bool> (std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Five)), true));
    m_cards.push_back(std::pair <std::shared_ptr <Card>, bool> (std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Six)), true));
    m_cards.push_back(std::pair <std::shared_ptr <Card>, bool> (std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Seven)), true));
    m_cards.push_back(std::pair <std::shared_ptr <Card>, bool> (std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Eight)), true));
    m_cards.push_back(std::pair <std::shared_ptr <Card>, bool> (std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Nine)), true));
    m_cards.push_back(std::pair <std::shared_ptr <Card>, bool> (std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Ten)), true));
    m_cards.push_back(std::pair <std::shared_ptr <Card>, bool> (std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Jack)), true));
    m_cards.push_back(std::pair <std::shared_ptr <Card>, bool> (std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Queen)), true));
    m_cards.push_back(std::pair <std::shared_ptr <Card>, bool> (std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::King)), true));
    m_cards.push_back(std::pair <std::shared_ptr <Card>, bool> (std::shared_ptr <Card> (new Card(id ++, a_symbol, Card::Value::Ace)), true));

    return id;
}

std::vector <unsigned int> Deck::getAvailableCards()
{
    std::vector <unsigned int> availableCards;

    for(const auto & card : m_cards)
    {
        if(card.second)
        {
            availableCards.push_back(card.first->getId());
        }
    }

    return availableCards;
}

void Deck::setCardEnabled(unsigned int a_cardId, bool a_enabled)
{
    m_cards[a_cardId].second = a_enabled;
}
