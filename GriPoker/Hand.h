#ifndef HAND_H
#define HAND_H

#include <Card.h>
#include <memory>

class Hand
{
private :

    std::shared_ptr <Card> m_firstCard;
    std::shared_ptr <Card> m_secondCard;

public:
    Hand();
    ~Hand();

public :

    const std::shared_ptr <Card> & getFirstCard() const;
    const std::shared_ptr <Card> & getSecondCard() const;
    void setFirstCard(const std::shared_ptr <Card> & a_card);
    void setSecondCard(const std::shared_ptr <Card> & a_card);
};

#endif // HAND_H
