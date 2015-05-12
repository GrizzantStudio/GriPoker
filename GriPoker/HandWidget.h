#ifndef HANDWIDGET_H
#define HANDWIDGET_H

#include <QWidget>

#include <memory>

class Card;

class HandWidget : public QWidget
{
    Q_OBJECT

private :

    std::unique_ptr <Card> m_card1;
    std::unique_ptr <Card> m_card2;

public:
    explicit HandWidget(const std::shared_ptr <Card> & a_firstCard, const std::shared_ptr <Card> & a_secondCard);
    ~HandWidget();

public :

    QPixmap renderInPixmap();
};

#endif // HANDWIDGET_H
