#include "Hand.h"

Hand::Hand()
    : m_firstCard(nullptr)
    , m_secondCard(nullptr)
{
}

Hand::~Hand()
{
}

const std::shared_ptr <Card> & Hand::getFirstCard() const
{
    return m_firstCard;
}

const std::shared_ptr <Card> & Hand::getSecondCard() const
{
    return m_secondCard;
}

void Hand::setFirstCard(const std::shared_ptr <Card> & a_card)
{
    m_firstCard = a_card;
}

void Hand::setSecondCard(const std::shared_ptr <Card> & a_card)
{
    m_secondCard = a_card;
}

