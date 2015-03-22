#ifndef UPGRADEPROBATABLEMODEL_H
#define UPGRADEPROBATABLEMODEL_H

#include <QAbstractTableModel>

class UpgradeProbaTableModel : public QAbstractTableModel
{
public:
    UpgradeProbaTableModel();
    ~UpgradeProbaTableModel();

private :
    int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags ( const QModelIndex & index ) const;

private :

    float roundProba(float a_proba) const;
    int binomialCoeff(int n, int k) const;
};

#endif // UPGRADEPROBATABLEMODEL_H
