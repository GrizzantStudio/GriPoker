#ifndef HAND_H
#define HAND_H

#include <Card.h>
#include <memory>
#include <QPixmap>

class HandWidget;

class Hand
{
private :

    std::shared_ptr <Card> m_firstCard;
    std::shared_ptr <Card> m_secondCard;
    std::unique_ptr <HandWidget> m_handWidget;
    bool m_displayIsUpToDate;
    QPixmap m_display;

public:
    Hand();
    ~Hand();

public :

    const QPixmap & getDisplay();

public :

    const std::shared_ptr <Card> & getFirstCard() const;
    const std::shared_ptr <Card> & getSecondCard() const;
    void setFirstCard(const std::shared_ptr <Card> & a_card);
    void setSecondCard(const std::shared_ptr <Card> & a_card);

private :

    void updateDisplay();
};

#endif // HAND_H
