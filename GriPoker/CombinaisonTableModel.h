#ifndef COMBINAISONTABLEMODEL_H
#define COMBINAISONTABLEMODEL_H

#include <QAbstractTableModel>
#include <Combinaison.h>
#include <QSharedPointer>
#include <QVector>
#include <QString>
#include <QStandardItemModel>

class CombinaisonTableModel : public QAbstractTableModel
{
private :

    class Hand
    {
    public :
        int card1Value;
        int card2Value;
        QString card1ValueString;
        QString card2ValueString;
        bool assorted;

        QMap <Combinaison::Type, QVector<float>> probaPerCombinaison;
    };

private :

    QVector <QSharedPointer <Combinaison>> m_combinaisons;
    QVector <Hand> m_hands;

    QStandardItemModel _horizontalHeaderModel;

public:
    CombinaisonTableModel();
    ~CombinaisonTableModel();

private :

    void fillHeaderModel(QStandardItemModel& headerModel);
    float computeProba(Combinaison::Type a_combinaisonType, unsigned int a_playerCount, unsigned int a_card1Value, unsigned int a_card2Value, bool a_assorted);
    float computeBrelanProba(unsigned int a_playerCount, unsigned int a_card1Value, unsigned int a_card2Value);

public :

    int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const;

protected :

    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags ( const QModelIndex & index ) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
};

#endif // COMBINAISONTABLEMODEL_H
