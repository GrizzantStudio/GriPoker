#include "CombinaisonTableModel.h"

#include <Maths.h>
#include <iostream>
#include <HierarchicalHeaderView.h>

CombinaisonTableModel::CombinaisonTableModel()
{
    m_combinaisons = Combinaison::getAllCombinaisons();

    for(int i = 2; i <= 14; ++i)
    {
        for(int j = i; j <= 14; ++ j)
        {
            for(int k = 0; k < 2; ++ k)
            {
                if(k == 0 || (k == 1 && i != j))
                {
                    int first = i >= j ? i : j;
                    int second = i >= j ? j : i;

                    Hand hand;
                    hand.card1Value = first;
                    hand.card2Value = second;

                    if(first == 11)
                        hand.card1ValueString = QString("J");
                    else if(first == 12)
                        hand.card1ValueString = QString("Q");
                    else if(first == 13)
                        hand.card1ValueString = QString("K");
                    else if(first == 14)
                        hand.card1ValueString = QString("A");
                    else
                        hand.card1ValueString = QString("%1").arg(first);

                    if(second == 11)
                        hand.card2ValueString = QString("J");
                    else if(second == 12)
                        hand.card2ValueString = QString("Q");
                    else if(second == 13)
                        hand.card2ValueString = QString("K");
                    else if(second == 14)
                        hand.card2ValueString = QString("A");
                    else
                        hand.card2ValueString = QString("%1").arg(second);

                    hand.assorted = k == 1;

                    m_hands.push_back(hand);
                }
            }
        }
    }


    bool done = false;
    int size = m_hands.size();

    while(! done)
    {
        done = true;

        for(int i = 0 ; i < size - 1 ; i++)
        {
            if(m_hands[i].card1Value < m_hands[i+1].card1Value || (m_hands[i].card1Value == m_hands[i+1].card1Value && m_hands[i].card2Value < m_hands[i+1].card2Value))
            {
                Hand tmp = m_hands[i];
                m_hands[i] = m_hands[i + 1];
                m_hands[i + 1] = tmp;
                done = false;
            }
        }
        size --;
    }

    std::cout << m_hands.size() << " hands - " << Maths::binomialCoeff(52, 2) << " expected." << std::endl;

    for(int i = 0; i < m_hands.size(); ++ i)
    {
        for(int j = 0; j < m_combinaisons.size(); ++ j)
        {
            for(int k = 2; k <= 10; ++k)
            {
                m_hands[i].probaPerCombinaison[m_combinaisons[j]->getType()].push_back(computeProba(m_combinaisons[j]->getType(), k, m_hands[i].card1Value, m_hands[i].card2Value, m_hands[i].assorted));
            }
        }
    }

    fillHeaderModel(_horizontalHeaderModel);

    computeBrelanProba(2, 2, 3);
    //std::cout << Maths::binomialCoeff(45, 3) << std::endl;
    //std::cout << Maths::binomialCoeff(3, 2) << std::endl;
}

CombinaisonTableModel::~CombinaisonTableModel()
{

}

void CombinaisonTableModel::fillHeaderModel(QStandardItemModel& headerModel)
{
    QList<QStandardItem*> l;

    for(int i = 0; i < m_combinaisons.size(); ++ i)
    {
        QStandardItem * combinaisonItem = new QStandardItem(m_combinaisons[i]->getTypeString());
        l.push_back(combinaisonItem);
        headerModel.appendColumn(l);

        l.clear();

        for(int j = 2; j <= 10; ++ j)
        {
            QStandardItem * cell = new QStandardItem(QString("%1").arg(j));
            l.push_back(cell);

            combinaisonItem->appendColumn(l);

            l.clear();
        }
    }
}


int CombinaisonTableModel::rowCount ( const QModelIndex & parent) const
{
    return m_hands.size();
}

int CombinaisonTableModel::columnCount ( const QModelIndex & parent) const
{
    return 9 * m_combinaisons.size();
}

QVariant CombinaisonTableModel::data ( const QModelIndex & index, int role) const
{
    if(role == Qt::DisplayRole)
    {
        unsigned int combinaisonIndex = index.column() / 9;
        unsigned int playerCountIndex = index.column() % 9;

        float proba = m_hands[index.row()].probaPerCombinaison[m_combinaisons[combinaisonIndex]->getType()][playerCountIndex];
        return QString("%1 %").arg(proba);
    }
    if(role == HierarchicalHeaderView::HorizontalHeaderDataRole)
    {
        QVariant v;
        v.setValue((QObject*)&_horizontalHeaderModel);
        return v;
    }

    return QVariant();
}

Qt::ItemFlags CombinaisonTableModel::flags ( const QModelIndex & index ) const
{
    return Qt::ItemIsEnabled || Qt::ItemIsSelectable;
}

QVariant CombinaisonTableModel::headerData ( int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            if(section == 0)
                return QString("Main");
            else
                return m_combinaisons[section - 1]->getTypeString().replace(' ', '\n');
        }
        if(orientation == Qt::Vertical)
        {
            return QString("%1 %2 %3").arg(m_hands[section].card1ValueString).arg(m_hands[section].card2ValueString).arg(m_hands[section].assorted ? "s" : "");
        }
    }

    return QVariant();
}

float CombinaisonTableModel::computeProba(Combinaison::Type a_combinaisonType, unsigned int a_playerCount, unsigned int a_card1Value, unsigned int a_card2Value, bool a_assorted)
{
    float proba = 0.f;

    switch(a_combinaisonType)
    {
       // case Combinaison::Type::BRELAN : proba = computeBrelanProba(a_playerCount, a_card1Value, a_card2Value); break;
        default : proba = 0.f;
    }

    return proba;
}

#define LOG_ENABLED
#if defined(LOG_ENABLED)
    #define LOG2(X,Y) std::cout << QString("%1 : %2").arg(X).arg(Y).toStdString() << std::endl;
    #define LOG1(X) std::cout << QString("%1").arg(X).toStdString() << std::endl;
#else
    #define LOG2(X,Y) (void *)0;
    #define LOG1(X) (void *)0;
#endif

float CombinaisonTableModel::computeBrelanProba(unsigned int a_playerCount, unsigned int a_card1Value, unsigned int a_card2Value)
{
    double totalProbability = 0.f;

    double cardDistributedToOtherCount = 2 * (a_playerCount - 1);
    LOG2("cardDistributedToOtherCount", cardDistributedToOtherCount)

    double cardNotDistributedCount = 52 - cardDistributedToOtherCount - 2;
    LOG2("cardNotDistributedCount", cardNotDistributedCount)

    double distrubutionToOtherCount = Maths::binomialCoeff(50, cardDistributedToOtherCount);
    LOG2("distrubutionToOtherCount", distrubutionToOtherCount)

    double boardCount = Maths::binomialCoeff(cardNotDistributedCount, 5);
    LOG2("boardCount : ", boardCount)

    for(int card = 0; card < 2; ++ card)
    {
        if(card == 0 || (card == 1 && a_card1Value != a_card2Value))
        {
            LOG2("= Iteration for card value", a_card1Value)

            double probaToTouchBrelanWithThisCard = 0.f;

            double cardOfThisValueLeft = a_card1Value == a_card2Value ? 2. : 3.;
            LOG2("= cardOfThisValueLeft", cardOfThisValueLeft)

            for(int distributedCardOfThisValueToOthers = 0; distributedCardOfThisValueToOthers <= cardOfThisValueLeft; ++ distributedCardOfThisValueToOthers)
            {
                LOG2("== distributedCardOfThisValueToOthers", distributedCardOfThisValueToOthers)

                double pathProba = 0.f;
                double pathCardOfThisValueLeft = cardOfThisValueLeft - distributedCardOfThisValueToOthers;
                LOG2("== pathCardOfThisValueLeft", pathCardOfThisValueLeft)

                double requestedCardOfThisValueForBrelan = a_card1Value == a_card2Value ? 1. : 2.;
                LOG2("== requestedCardOfThisValueForBrelan", requestedCardOfThisValueForBrelan)

                if(distributedCardOfThisValueToOthers <= cardDistributedToOtherCount && requestedCardOfThisValueForBrelan <= pathCardOfThisValueLeft)
                {
                    double pathDistributionToOtherCount = (distributedCardOfThisValueToOthers > 0 ? Maths::binomialCoeff(cardOfThisValueLeft, distributedCardOfThisValueToOthers) : 1.f) * Maths::binomialCoeff(52 - 2 - cardOfThisValueLeft, cardDistributedToOtherCount - distributedCardOfThisValueToOthers);
                    LOG2("=== pathDistributionToOtherCount", pathDistributionToOtherCount)

                    pathProba = pathDistributionToOtherCount / distrubutionToOtherCount;
                    LOG2("=== initial path proba", pathProba)

                    double boardWithBrelanCount1 = Maths::binomialCoeff(pathCardOfThisValueLeft, requestedCardOfThisValueForBrelan);
                    double boardWithBrelanCount2 = Maths::binomialCoeff(cardNotDistributedCount - pathCardOfThisValueLeft, 5 - pathCardOfThisValueLeft);
                    double boardWithBrelanCount = boardWithBrelanCount1 * boardWithBrelanCount2;
                    LOG2("=== boardWithBrelanCount1", boardWithBrelanCount1)
                    LOG2("=== boardWithBrelanCount2", boardWithBrelanCount2)
                    LOG2("=== boardWithBrelanCount", boardWithBrelanCount)

                    double boardProba = (float) boardWithBrelanCount / (float) boardCount;
                    LOG2("=== boardProba", boardProba)

                    pathProba *= boardProba;
                    LOG2("=== final path proba", pathProba)
                }
                else
                    LOG1("== Impossible path")

                probaToTouchBrelanWithThisCard += pathProba;
            }

            totalProbability += probaToTouchBrelanWithThisCard;
        }
        else
            LOG1("= Pair detected - no more iteration")
    }

    LOG2("totalProbability", totalProbability)
    LOG2("totalProbability", Maths::roundProba(totalProbability * 100.f))
    return Maths::roundProba(totalProbability * 100.f);
}
