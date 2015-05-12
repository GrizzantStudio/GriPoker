#include "StartHandTableModel.h"

#include <QColor>
#include <QImage>
#include <QPixmap>
#include <Hand.h>
#include <Card.h>
#include <Dealer.h>

#include <iostream>

StartHandTableModel::StartHandTableModel()
    : QAbstractTableModel()
{
    std::shared_ptr <Card> card1(new Card(0, Card::Symbol::Club, Card::Value::King));
    std::shared_ptr <Card> card2(new Card(1, Card::Symbol::Heart, Card::Value::Queen));

    m_hand.reset(new Hand());
    m_hand->setFirstCard(card1);
    m_hand->setSecondCard(card2);
/*
    std::cout << "start" << std::endl;

    Dealer::getAllPossibleDistributions(QString("../distributions"), Game::PlayerCount::TWO);
    Dealer::getAllPossibleDistributions(QString("../distributions"), Game::PlayerCount::THREE);
    Dealer::getAllPossibleDistributions(QString("../distributions"), Game::PlayerCount::FOUR);
    Dealer::getAllPossibleDistributions(QString("../distributions"), Game::PlayerCount::FIVE);
    Dealer::getAllPossibleDistributions(QString("../distributions"), Game::PlayerCount::SiX);
    Dealer::getAllPossibleDistributions(QString("../distributions"), Game::PlayerCount::SEVEN);
    Dealer::getAllPossibleDistributions(QString("../distributions"), Game::PlayerCount::EIGHT);
    Dealer::getAllPossibleDistributions(QString("../distributions"), Game::PlayerCount::NINE);
    Dealer::getAllPossibleDistributions(QString("../distributions"), Game::PlayerCount::TEN);*/
}

StartHandTableModel::~StartHandTableModel()
{

}

int StartHandTableModel::rowCount ( const QModelIndex & parent ) const
{
    return 2;
}

int StartHandTableModel::columnCount ( const QModelIndex & parent ) const
{
    return 10 ;
}

QVariant StartHandTableModel::data ( const QModelIndex & index, int role ) const
{
    if(role == Qt::DisplayRole)
    {
    }
    else if(role == Qt::DecorationRole)
    {
        if(index.row() == 0 && index.column() == 0)
        {
            return m_hand->getDisplay();
        }

        if(index.row() == 0 && index.column() == 1)
        {
            return QPixmap(":/images/3spade.png");
        }
    }
    else if(role == Qt::BackgroundColorRole)
    {
       //if(index.row() % 2 == 0) return QColor(255, 124, 62, 255);
       //if(index.row() % 2 == 1) return QColor(62, 124, 255, 255);
    }

    return QVariant();
}

QVariant StartHandTableModel::headerData ( int section, Qt::Orientation orientation, int role ) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            if(section == 0) return "Hand";
            if(section == 1) return "2 joueurs";
            if(section == 2) return "3 joueurs";
            if(section == 3) return "4 joueurs";
            if(section == 4) return "5 joueurs";
            if(section == 5) return "6 joueurs";
            if(section == 6) return "7 joueurs";
            if(section == 7) return "8 joueurs";
            if(section == 8) return "9 joueurs";
            if(section == 9) return "10 joueurs";
        }
    }

    return QVariant();
}

Qt::ItemFlags StartHandTableModel::flags ( const QModelIndex & index ) const
{
    return Qt::ItemIsEnabled;
}
