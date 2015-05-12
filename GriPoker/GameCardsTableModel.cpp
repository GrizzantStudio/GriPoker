#include "GameCardsTableModel.h"

#include <QPixmap>
#include <iostream>
#include <QMimeData>

#include <Card.h>

GameCardsTableModel::GameCardsTableModel()
{
    m_cards = std::vector <std::shared_ptr <Card>>(7, nullptr);
}

GameCardsTableModel::~GameCardsTableModel()
{

}


int GameCardsTableModel::rowCount ( const QModelIndex & parent ) const
{
    return 1;
}

int GameCardsTableModel::columnCount ( const QModelIndex & parent ) const
{
    return 7;
}

QVariant GameCardsTableModel::data ( const QModelIndex & index, int role ) const
{
    if(role == Qt::DecorationRole)
    {
        if(m_cards[index.column()] == nullptr)
            return QPixmap(":/images/empty.png");
        else
            return *(m_cards[index.column()]->getPixmap().get());
    }
    if(role == Qt::DisplayRole)
    {
    }

    return QVariant();
}

QVariant GameCardsTableModel::headerData ( int section, Qt::Orientation orientation, int role ) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            if(section == 0) return "Hand 1";
            if(section == 1) return "Hand 2";
            if(section == 2) return "Flop 1";
            if(section == 3) return "Flop 2";
            if(section == 4) return "Flop 3";
            if(section == 5) return "Turn";
            if(section == 6) return "River";
        }
    }

    return QVariant();
}

Qt::ItemFlags GameCardsTableModel::flags ( const QModelIndex & index ) const
{
    return Qt::ItemIsEnabled | Qt::ItemIsDropEnabled;
}

bool GameCardsTableModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    if (action == Qt::IgnoreAction)
        return true;

    if (!data->hasFormat("image/card"))
        return false;

    if (parent.row() == -1 || parent.column() == -1)
        return false;

     QByteArray encodedData = data->data("image/card");
     QDataStream stream(&encodedData, QIODevice::ReadOnly);

     QString text;
     stream >> text;

     std::shared_ptr <Card> card(new Card(text.toStdString()));

     if(! card->isValid())
     {
        std::cerr << "Card data decoding error." << std::endl;
        return false;
     }

     beginResetModel();
     m_cards[parent.column()] = card;
     endResetModel();
}

Qt::DropActions GameCardsTableModel::supportedDropActions() const
{
    return Qt::CopyAction;
}

QStringList GameCardsTableModel::mimeTypes() const
{
    QStringList types;
    types << "image/card";
    return types;
}

