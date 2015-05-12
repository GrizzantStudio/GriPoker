#ifndef CARDPEDIATABLEMODEL_H
#define CARDPEDIATABLEMODEL_H

#include <QAbstractTableModel>
#include <QMimeData>
#include <memory>
#include <vector>

class Card;
class QDragMoveEvent;

class CardpediaTableModel : public QAbstractTableModel
{
private :

    std::vector <std::shared_ptr <Card>> m_cards;

public:
    CardpediaTableModel();
    ~CardpediaTableModel();

private :

    int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags ( const QModelIndex & index ) const;
    Qt::DropActions supportedDropActions() const;
    QMimeData * mimeData(const QModelIndexList &indexes) const;
    QStringList mimeTypes() const;
};

#endif // CARDPEDIATABLEMODEL_H
