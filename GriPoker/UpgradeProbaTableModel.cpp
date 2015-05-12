#include "UpgradeProbaTableModel.h"

#include <QColor>
#include <Maths.h>

#define TOTAL_CARD_COUNT 52.f
#define PREFLOP_CARD_LEFT_COUNT (TOTAL_CARD_COUNT - 2.f)
#define FLOP_CARD_LEFT_COUNT (PREFLOP_CARD_LEFT_COUNT - 3.f)
#define TURN_CARD_LEFT_COUNT (FLOP_CARD_LEFT_COUNT - 1.f)

UpgradeProbaTableModel::UpgradeProbaTableModel()
    : QAbstractTableModel()
{

}

UpgradeProbaTableModel::~UpgradeProbaTableModel()
{

}

int UpgradeProbaTableModel::rowCount ( const QModelIndex & parent ) const
{
    return 20;
}

int UpgradeProbaTableModel::columnCount ( const QModelIndex & parent ) const
{
    return 4;
}

QVariant UpgradeProbaTableModel::data ( const QModelIndex & index, int role ) const
{
    if(role == Qt::DisplayRole)
    {
        float outs = 20.f - (float) index.row();
        float turnProba = outs / FLOP_CARD_LEFT_COUNT * 100.f;
        float riverProba = outs / TURN_CARD_LEFT_COUNT * 100.f;
        float turnRiverProba = (Maths::binomialCoeff((int) FLOP_CARD_LEFT_COUNT, 2) - Maths::binomialCoeff((int) FLOP_CARD_LEFT_COUNT - outs, 2)) / (float) Maths::binomialCoeff((int) FLOP_CARD_LEFT_COUNT, 2) * 100.f;

        float turnProbaEstimation = outs * 2.f;
        float riverProbaEstimation = outs * 2.f;
        float turnRiverProbaEstimation = outs * 4.f;

        float turnProbaDelta = turnProbaEstimation - turnProba;
        float riverProbaDelta = riverProbaEstimation - riverProba;
        float turnRiverProbaDelta = turnRiverProbaEstimation - turnRiverProba;

        if(index.column() == 0) return (int) outs;
        if(index.column() == 1) return QString("%1% (%2%/%3%)").arg(Maths::roundProba(turnProba)).arg(Maths::roundProba(turnProbaEstimation)).arg(Maths::roundProba(turnProbaDelta));
        if(index.column() == 2) return QString("%1% (%2%/%3%)").arg(Maths::roundProba(riverProba)).arg(Maths::roundProba(riverProbaEstimation)).arg(Maths::roundProba(riverProbaDelta));
        if(index.column() == 3) return QString("%1% (%2%/%3%)").arg(Maths::roundProba(turnRiverProba)).arg(Maths::roundProba(turnRiverProbaEstimation)).arg(Maths::roundProba(turnRiverProbaDelta));
    }
    else if(role == Qt::BackgroundColorRole)
    {
       if(index.row() % 2 == 0) return QColor(255, 124, 62, 255);
       if(index.row() % 2 == 1) return QColor(62, 124, 255, 255);
    }

    return QVariant();
}

QVariant UpgradeProbaTableModel::headerData ( int section, Qt::Orientation orientation, int role ) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            if(section == 0) return "Outs";
            if(section == 1) return "Turn (Estimation/Delta)";
            if(section == 2) return "River (Estimation/Delta)";
            if(section == 3) return "Turn+River (Estimation/Delta)";
        }
    }

    return QVariant();
}

Qt::ItemFlags UpgradeProbaTableModel::flags ( const QModelIndex & index ) const
{
    return Qt::ItemIsEnabled;
}

