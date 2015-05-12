#include "CardpediaTableModel.h"

#include <QPixmap>
#include <iostream>
#include <QDragMoveEvent>

#include <Card.h>

CardpediaTableModel::CardpediaTableModel()
{
    unsigned int cardId = 0;
    for(int col = 0; col < 4; ++ col)
    {
        for(int row = 0; row < 13; ++ row)
        {
            Card::Value value = Card::Value::Undefined;

            switch(row)
            {
                case 0 : value = Card::Value::Ace; break;
                case 1 : value = Card::Value::King; break;
                case 2 : value = Card::Value::Queen; break;
                case 3 : value = Card::Value::Jack; break;
                case 4 : value = Card::Value::Ten; break;
                case 5 : value = Card::Value::Nine; break;
                case 6 : value = Card::Value::Eight; break;
                case 7 : value = Card::Value::Seven; break;
                case 8 : value = Card::Value::Six; break;
                case 9 : value = Card::Value::Five; break;
                case 10 : value = Card::Value::Four; break;
                case 11 : value = Card::Value::Three; break;
                case 12 : value = Card::Value::Two; break;
            }

            Card::Symbol symbol = Card::Symbol::Undefined;

            switch(col)
            {
                case 0 : symbol = Card::Symbol::Spade; break;
                case 1 : symbol = Card::Symbol::Heart; break;
                case 2 : symbol = Card::Symbol::Diamond; break;
                case 3 : symbol = Card::Symbol::Club; break;
            }


            std::shared_ptr <Card> card(new Card(cardId, symbol, value));

            m_cards.push_back(card);
            ++ cardId;

        }
    }
}

CardpediaTableModel::~CardpediaTableModel()
{

}

int CardpediaTableModel::rowCount ( const QModelIndex & parent ) const
{
    return 13;
}

int CardpediaTableModel::columnCount ( const QModelIndex & parent ) const
{
    return 4;
}

QVariant CardpediaTableModel::data ( const QModelIndex & index, int role ) const
{
    if(role == Qt::DisplayRole)
    {
    }
    else if(role == Qt::DecorationRole)
    {
        return *(m_cards[index.column() * 13 + index.row()]->getPixmap().get());
    }

    return QVariant();
}

Qt::ItemFlags CardpediaTableModel::flags ( const QModelIndex & index ) const
{
    return Qt::ItemIsEnabled | Qt::ItemIsDragEnabled | Qt::ItemIsSelectable;
}

Qt::DropActions CardpediaTableModel::supportedDropActions() const
 {
     return Qt::CopyAction;
 }

QStringList CardpediaTableModel::mimeTypes() const
{
    QStringList types;
    types << "image/card";
    return types;
}

QMimeData * CardpediaTableModel::mimeData(const QModelIndexList &indexes) const
{
    QMimeData *mimeData = new QMimeData();
    QByteArray encodedData;

    QDataStream stream(&encodedData, QIODevice::WriteOnly);

    if (indexes[0].isValid())
    {
        std::string encodedCard = m_cards[indexes[0].column() * 13 + indexes[0].row()]->encodeAsString();
        stream << QString(encodedCard.c_str());
    }

    mimeData->setData("image/card", encodedData);
    return mimeData;
}

