#include "HandWidget.h"

#include <QHBoxLayout>
#include <QLabel>

#include "Card.h"

#include <iostream>

HandWidget::HandWidget(const std::shared_ptr <Card> & a_firstCard, const std::shared_ptr <Card> & a_secondCard)
    : QWidget(nullptr)
{
    QHBoxLayout * layout = new QHBoxLayout(this);
    setLayout(layout);

    m_card1.reset(new Card(*a_firstCard.get()));
    m_card2.reset(new Card(*a_secondCard.get()));

    std::shared_ptr <QPixmap> card1Image = m_card1->getPixmap();
    std::shared_ptr <QPixmap> card2Image = m_card2->getPixmap();

    QLabel * label1 = new QLabel(this);
    label1->setPixmap(*card1Image.get());
    layout->addWidget(label1);

    QLabel * label2 = new QLabel(this);
    label2->setPixmap(*card2Image.get());
    layout->addWidget(label2);

    adjustSize();
}

HandWidget::~HandWidget()
{
}

QPixmap HandWidget::renderInPixmap()
{
    QRect area(0, 0, width(), height());
    QPixmap pixmap(area.size());
    render(& pixmap, QPoint(), QRegion(area));
    return pixmap;
}
