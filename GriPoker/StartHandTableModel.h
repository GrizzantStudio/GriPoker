#ifndef STARTHANDTABLEMODEL_H
#define STARTHANDTABLEMODEL_H

#include <QAbstractTableModel>
#include <memory>
#include <Hand.h>


class StartHandTableModel : public QAbstractTableModel
{
private :

    std::unique_ptr <Hand> m_hand;

public:
    StartHandTableModel();
    ~StartHandTableModel();

private :
    int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags ( const QModelIndex & index ) const;
};

#endif // STARTHANDTABLEMODEL_H
