#include "Hand.h"
#include "HandWidget.h"

#include <iostream>

Hand::Hand()
    : m_firstCard(nullptr)
    , m_secondCard(nullptr)
    , m_handWidget(nullptr)
    , m_displayIsUpToDate(false)
{
}

Hand::~Hand()
{
}

const QPixmap & Hand::getDisplay()
{
    if(! m_displayIsUpToDate)
        updateDisplay();

    return m_display;
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
    m_displayIsUpToDate = false;
}

void Hand::setSecondCard(const std::shared_ptr <Card> & a_card)
{
    m_secondCard = a_card;
    m_displayIsUpToDate = false;
}

void Hand::updateDisplay()
{
    if(m_displayIsUpToDate)
        return;

    m_handWidget.reset(new HandWidget(m_firstCard, m_secondCard));

    m_display = m_handWidget->renderInPixmap();

    m_displayIsUpToDate = true;
}

