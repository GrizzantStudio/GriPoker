#ifndef GAMECARDSTABLEMODEL_H
#define GAMECARDSTABLEMODEL_H

#include <QAbstractTableModel>
#include <string>
#include <vector>
#include <memory>

class Card;

class GameCardsTableModel : public QAbstractTableModel
{
private :

    std::vector <std::shared_ptr <Card>> m_cards;

public:
    GameCardsTableModel();
    ~GameCardsTableModel();

private :

    int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags ( const QModelIndex & index ) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    Qt::DropActions supportedDropActions() const;
    QStringList mimeTypes() const;
};

#endif // GAMECARDSTABLEMODEL_H
