#include "CombinaisonTableModel.h"

#include <Maths.h>
#include <iostream>
#include <HierarchicalHeaderView.h>

#include <chrono>
#include <ctime>

#define Spade 0
#define Hearth 1
#define Diamond 2
#define Club 3

#define Two 0
#define Three 1
#define Four 2
#define Five 3
#define Six 4
#define Seven 5
#define Eight 6
#define Nine 7
#define Ten 8
#define Jack 9
#define Queen 10
#define King 11
#define Ace 12

CombinaisonTableModel::CombinaisonTableModel()
{
    std::chrono::time_point <std::chrono::system_clock> start = std::chrono::system_clock::now();

    unsigned long handCount = (unsigned long) Maths::binomialCoeff(52, 2);
    unsigned long boardCount = (unsigned long) Maths::binomialCoeff(50, 5);

    double val1d = Maths::binomialCoeff(52, 2);
    unsigned long val1ul = (unsigned long) val1d;

    double val2d = Maths::binomialCoeff(50, 5);
    unsigned long val2ul = (unsigned long) val2d;

    double multd = val1d * val2d;
    double multul = val1ul * val2ul;

    std::cout << "(" << std::to_string(val1d) << ", " << std::to_string(val1ul) << ") (" << std::to_string(val2d) << ", " << std::to_string(val2ul) << ") (" << std::to_string(multd) << ", " << std::to_string(multul) << ") " << std::endl;

    std::cout << " " << std::to_string(Maths::binomialCoeff(50, 5)) << std::endl;
    std::cout << std::to_string(handCount) << " " << std::to_string(Maths::binomialCoeff(52, 2)) << " hands" << std::endl;
    std::cout << std::to_string(boardCount * handCount) << " " << std::to_string(Maths::binomialCoeff(52, 2) * Maths::binomialCoeff(50, 5)) << " boards" << std::endl;

    unsigned long totalBoard = 0;
    unsigned long totalHand = 0;

    unsigned int symbols [] = {Spade, Hearth, Diamond, Club};
    unsigned int values [] = {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};
    unsigned int symbolCount = 4;
    unsigned int valueCount = 13;
    unsigned int cardCount = symbolCount * valueCount;

    std::pair <unsigned int, unsigned int> cards [52];

    for(unsigned int symbolIndex = 0; symbolIndex < symbolCount; ++ symbolIndex)
    {
        for(unsigned int valueIndex = 0; valueIndex < valueCount; ++ valueIndex)
        {
            cards[valueCount * symbolIndex + valueIndex].first = symbols[symbolIndex];
            cards[valueCount * symbolIndex + valueIndex].second = values[valueIndex];
        }
    }

    unsigned int hand1 = 0;
    unsigned int hand2 = 1;

    for(unsigned int handIndex = 0; handIndex < handCount; ++ handIndex)
    {
        unsigned int board1 = 0;
        while(board1 == hand1 || board1 == hand2) ++ board1;

        unsigned int board2 = board1 + 1;
        while(board2 == hand1 || board2 == hand2) ++ board2;

        unsigned int board3 = board2 + 1;
        while(board3 == hand1 || board3 == hand2) ++ board3;

        unsigned int board4 = board3 + 1;
        while(board4 == hand1 || board4 == hand2) ++ board4;

        unsigned int board5 = board4 + 1;
        while(board5 == hand1 || board5 == hand2) ++ board5;

        for(unsigned int boardIndex = 0; boardIndex < boardCount; ++ boardIndex)
        {
            ++ board5;
            while(board5 == hand1 || board5 == hand2) ++ board5;

            if(board5 >= cardCount)
            {
                ++ board4;
                while(board4 == hand1 || board4 == hand2) ++ board4;

                if(board4 >= cardCount - 1)
                {
                    ++ board3;
                    while(board3 == hand1 || board3 == hand2) ++ board3;

                    if(board3 >= cardCount - 2)
                    {
                        ++ board2;
                        while(board2 == hand1 || board2 == hand2) ++ board2;

                        if(board2 >= cardCount - 3)
                        {
                            ++ board1;
                            while(board1 == hand1 || board1 == hand2) ++ board1;

                            board2 = board1 + 1;
                            while(board2 == hand1 || board2 == hand2) ++ board2;
                        }

                        board3 = board2 + 1;
                        while(board3 == hand1 || board3 == hand2) ++ board3;
                    }

                    board4 = board3 + 1;
                    while(board4 == hand1 || board4 == hand2) ++ board4;
                }

                board5 = board4 + 1;
                while(board5 == hand1 || board5 == hand2) ++ board5;
            }

            ++ totalBoard;
        }

        ++ hand2;
        ++ totalHand;

        if(hand2 > cardCount - 1)
        {
            ++ hand1;
            hand2 = hand1 + 1;

            if(hand1 >= cardCount - 1)
                std::cout << "[" << hand1 << ", " << hand2 << "] hum hum" << std::endl;
        }
    }

    std::chrono::time_point <std::chrono::system_clock> end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "[hands " << std::to_string(totalHand) << ", boards " << std::to_string(totalBoard) << "] finished computation at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";

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
            for(int k = 1; k <= 10; ++k)
            {
                m_hands[i].probaPerCombinaison[m_combinaisons[j]->getType()].push_back(computeProba(m_combinaisons[j]->getType(), k, m_hands[i].card1Value, m_hands[i].card2Value, m_hands[i].assorted));
            }
        }
    }

    fillHeaderModel(_horizontalHeaderModel);

    //computeBrelanProba(1, 2, 2);
    //computeBrelanProba2(2, 2);
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

        for(int j = 1; j <= 10; ++ j)
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
    return 10 * m_combinaisons.size();
}

QVariant CombinaisonTableModel::data ( const QModelIndex & index, int role) const
{
    if(role == Qt::DisplayRole)
    {
        unsigned int combinaisonIndex = index.column() / 10;
        unsigned int playerCountIndex = index.column() % 10;

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
        //case Combinaison::Type::BRELAN : proba = computeBrelanProba(a_playerCount, a_card1Value, a_card2Value); break;
        /*case Combinaison::Type::DOUBLE_PAIRE : proba = computeDoublePairProba(a_playerCount, a_card1Value, a_card2Value); break;
        case Combinaison::Type::PAIRE : proba = computePairProba(a_playerCount, a_card1Value, a_card2Value); break;
        case Combinaison::Type::HAUTEUR : proba = 100.f; break;*/
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

    double distrubutionToOtherCount = a_playerCount > 1 ? Maths::binomialCoeff(50, cardDistributedToOtherCount) : 0;
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

            double totalInitialPathsProba = 0.f;
            double totalProcessedInitialPathCount = 0.f;

            for(int distributedCardOfThisValueToOthers = 0; distributedCardOfThisValueToOthers <= cardOfThisValueLeft; ++ distributedCardOfThisValueToOthers)
            {
                LOG2("== distributedCardOfThisValueToOthers", distributedCardOfThisValueToOthers)

                double pathProba = 0.f;
                double pathCardOfThisValueLeft = cardOfThisValueLeft - distributedCardOfThisValueToOthers;
                LOG2("== pathCardOfThisValueLeft", pathCardOfThisValueLeft)

                double requestedCardOfThisValueForBrelan = a_card1Value == a_card2Value ? 1. : 2.;
                LOG2("== requestedCardOfThisValueForBrelan", requestedCardOfThisValueForBrelan)

                double pathDistributionToOtherCount = 0.;

                if(distributedCardOfThisValueToOthers <= cardDistributedToOtherCount)
                {
                    if(a_playerCount > 1)
                    {
                        pathDistributionToOtherCount = (distributedCardOfThisValueToOthers > 0 ? Maths::binomialCoeff(cardOfThisValueLeft, distributedCardOfThisValueToOthers) : 1.f) * ((cardDistributedToOtherCount - distributedCardOfThisValueToOthers > 0) ? Maths::binomialCoeff(52 - 2 - cardOfThisValueLeft, cardDistributedToOtherCount - distributedCardOfThisValueToOthers) : 1.);
                        LOG2("=== pathDistributionToOtherCount", pathDistributionToOtherCount)

                        pathProba = pathDistributionToOtherCount / distrubutionToOtherCount;
                        LOG2("=== initial path proba", pathProba)
                    }
                    else
                    {
                        pathDistributionToOtherCount = 0.;
                        LOG2("=== pathDistributionToOtherCount", pathDistributionToOtherCount)

                        pathProba = 1.f;
                        LOG2("=== initial path proba", pathProba)
                    }

                    totalInitialPathsProba += pathProba;
                    totalProcessedInitialPathCount += pathDistributionToOtherCount;

                    if(requestedCardOfThisValueForBrelan <= pathCardOfThisValueLeft)
                    {
                        double boardWithBrelanCount1 = Maths::binomialCoeff(pathCardOfThisValueLeft, requestedCardOfThisValueForBrelan);
                        double boardWithBrelanCount2 = Maths::binomialCoeff(cardNotDistributedCount - pathCardOfThisValueLeft, 5 - requestedCardOfThisValueForBrelan);
                        double boardWithBrelanCount = boardWithBrelanCount1 * boardWithBrelanCount2;
                        LOG2("==== boardWithBrelanCount1", boardWithBrelanCount1)
                        LOG2("==== boardWithBrelanCount2", boardWithBrelanCount2)
                        LOG2("==== boardWithBrelanCount", boardWithBrelanCount)

                        double boardProba = (float) boardWithBrelanCount / (float) boardCount;
                        LOG2("==== boardProba", boardProba)

                        pathProba *= boardProba;
                        LOG2("==== final path proba", pathProba)
                    }
                    else
                    {
                        pathProba = 0.f;
                        LOG1("==== No way")
                    }
                }
                else
                    LOG1("== Impossible path")

                probaToTouchBrelanWithThisCard += pathProba;
            }

            //if(totalProcessedInitialPathCount != distrubutionToOtherCount)
            //    std::cout << "Hum hum .... " << totalProcessedInitialPathCount << "/" << distrubutionToOtherCount << " = " << totalInitialPathsProba << std::endl;

            totalProbability += probaToTouchBrelanWithThisCard;
        }
        else
            LOG1("= Pair detected - no more iteration")
    }

    LOG2("totalProbability", totalProbability)
    LOG2("totalProbability", Maths::roundProba(totalProbability * 100.f))
    return Maths::roundProba(totalProbability * 100.f);
}

float CombinaisonTableModel::computeBrelanProba2(unsigned int a_card1Value, unsigned int a_card2Value)
{
    float proba = 0.f;

    double totalBoardCount = Maths::binomialCoeff(50, 5);
    double boardCount = Maths::binomialCoeff(2, 1) * Maths::binomialCoeff(48, 4);

    proba = boardCount / totalBoardCount;
    proba = Maths::roundProba(proba * 100.f);

    LOG2(">>>>>>>>>> Proba : ", proba)
    return proba;
}

float CombinaisonTableModel::computePairProba(unsigned int a_playerCount, unsigned int a_card1Value, unsigned int a_card2Value)
{
    if(a_card1Value == a_card2Value)
        return 100.f;

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

            double probaToTouchPairWithThisCard = 0.f;

            double cardOfThisValueLeft = 3.;
            LOG2("= cardOfThisValueLeft", cardOfThisValueLeft)

            double totalInitialPathsProba = 0.f;
            double totalProcessedInitialPathCount = 0.f;

            for(int distributedCardOfThisValueToOthers = 0; distributedCardOfThisValueToOthers <= cardOfThisValueLeft; ++ distributedCardOfThisValueToOthers)
            {
                LOG2("== distributedCardOfThisValueToOthers", distributedCardOfThisValueToOthers)

                double pathProba = 0.f;
                double pathCardOfThisValueLeft = cardOfThisValueLeft - distributedCardOfThisValueToOthers;
                LOG2("== pathCardOfThisValueLeft", pathCardOfThisValueLeft)

                double requestedCardOfThisValueForPair = 1.f;
                LOG2("== requestedCardOfThisValueForPair", requestedCardOfThisValueForPair)

                if(distributedCardOfThisValueToOthers <= cardDistributedToOtherCount)
                {
                    double pathDistributionToOtherCount = (distributedCardOfThisValueToOthers > 0 ? Maths::binomialCoeff(cardOfThisValueLeft, distributedCardOfThisValueToOthers) : 1.f) * ((cardDistributedToOtherCount - distributedCardOfThisValueToOthers > 0) ? Maths::binomialCoeff(52 - 2 - cardOfThisValueLeft, cardDistributedToOtherCount - distributedCardOfThisValueToOthers) : 1.);
                    LOG2("=== pathDistributionToOtherCount", pathDistributionToOtherCount)

                    pathProba = pathDistributionToOtherCount / distrubutionToOtherCount;
                    LOG2("=== initial path proba", pathProba)

                    totalInitialPathsProba += pathProba;
                    totalProcessedInitialPathCount += pathDistributionToOtherCount;

                    if(requestedCardOfThisValueForPair <= pathCardOfThisValueLeft)
                    {
                        double boardWithPairCount1 = Maths::binomialCoeff(pathCardOfThisValueLeft, requestedCardOfThisValueForPair);
                        double boardWithPairCount2 = Maths::binomialCoeff(cardNotDistributedCount - pathCardOfThisValueLeft, 5 - requestedCardOfThisValueForPair);
                        double boardWithPairCount = boardWithPairCount1 * boardWithPairCount2;
                        LOG2("==== boardWithPairCount1", boardWithPairCount1)
                        LOG2("==== boardWithPairCount2", boardWithPairCount2)
                        LOG2("==== boardWithPairCount", boardWithPairCount)

                        double boardProba = (float) boardWithPairCount / (float) boardCount;
                        LOG2("==== boardProba", boardProba)

                        pathProba *= boardProba;
                        LOG2("==== final path proba", pathProba)
                    }
                    else
                    {
                        pathProba = 0.f;
                        LOG1("==== No way")
                    }
                }
                else
                    LOG1("== Impossible path")

                probaToTouchPairWithThisCard += pathProba;
            }

            //if(totalProcessedInitialPathCount != distrubutionToOtherCount)
            //    std::cout << "Hum hum .... " << totalProcessedInitialPathCount << "/" << distrubutionToOtherCount << " = " << totalInitialPathsProba << std::endl;

            totalProbability += probaToTouchPairWithThisCard;
        }
        else
            LOG1("= Pair detected - no more iteration")
    }

    LOG2("totalProbability", totalProbability)
    LOG2("totalProbability", Maths::roundProba(totalProbability * 100.f))
    return Maths::roundProba(totalProbability * 100.f);
}


float CombinaisonTableModel::computeDoublePairProba(unsigned int a_playerCount, unsigned int a_card1Value, unsigned int a_card2Value)
{
    if(a_card1Value == a_card2Value)
        return 100.f;

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

            double probaToTouchPairWithThisCard = 0.f;

            double cardOfThisValueLeft = 3.;
            LOG2("= cardOfThisValueLeft", cardOfThisValueLeft)

            double totalInitialPathsProba = 0.f;
            double totalProcessedInitialPathCount = 0.f;

            for(int distributedCardOfThisValueToOthers = 0; distributedCardOfThisValueToOthers <= cardOfThisValueLeft; ++ distributedCardOfThisValueToOthers)
            {
                LOG2("== distributedCardOfThisValueToOthers", distributedCardOfThisValueToOthers)

                double pathProba = 0.f;
                double pathCardOfThisValueLeft = cardOfThisValueLeft - distributedCardOfThisValueToOthers;
                LOG2("== pathCardOfThisValueLeft", pathCardOfThisValueLeft)

                double requestedCardOfThisValueForPair = 1.f;
                LOG2("== requestedCardOfThisValueForPair", requestedCardOfThisValueForPair)

                if(distributedCardOfThisValueToOthers <= cardDistributedToOtherCount)
                {
                    double pathDistributionToOtherCount = (distributedCardOfThisValueToOthers > 0 ? Maths::binomialCoeff(cardOfThisValueLeft, distributedCardOfThisValueToOthers) : 1.f) * ((cardDistributedToOtherCount - distributedCardOfThisValueToOthers > 0) ? Maths::binomialCoeff(52 - 2 - cardOfThisValueLeft, cardDistributedToOtherCount - distributedCardOfThisValueToOthers) : 1.);
                    LOG2("=== pathDistributionToOtherCount", pathDistributionToOtherCount)

                    pathProba = pathDistributionToOtherCount / distrubutionToOtherCount;
                    LOG2("=== initial path proba", pathProba)

                    totalInitialPathsProba += pathProba;
                    totalProcessedInitialPathCount += pathDistributionToOtherCount;

                    if(requestedCardOfThisValueForPair <= pathCardOfThisValueLeft)
                    {
                        double boardWithPairCount1 = Maths::binomialCoeff(pathCardOfThisValueLeft, requestedCardOfThisValueForPair);
                        double boardWithPairCount2 = Maths::binomialCoeff(cardNotDistributedCount - pathCardOfThisValueLeft, 5 - requestedCardOfThisValueForPair);
                        double boardWithPairCount = boardWithPairCount1 * boardWithPairCount2;
                        LOG2("==== boardWithPairCount1", boardWithPairCount1)
                        LOG2("==== boardWithPairCount2", boardWithPairCount2)
                        LOG2("==== boardWithPairCount", boardWithPairCount)

                        double boardProba = (float) boardWithPairCount / (float) boardCount;
                        LOG2("==== boardProba", boardProba)

                        pathProba *= boardProba;
                        LOG2("==== final path proba", pathProba)
                    }
                    else
                    {
                        pathProba = 0.f;
                        LOG1("==== No way")
                    }
                }
                else
                    LOG1("== Impossible path")

                probaToTouchPairWithThisCard += pathProba;
            }

            //if(totalProcessedInitialPathCount != distrubutionToOtherCount)
            //    std::cout << "Hum hum .... " << totalProcessedInitialPathCount << "/" << distrubutionToOtherCount << " = " << totalInitialPathsProba << std::endl;

            totalProbability += probaToTouchPairWithThisCard;
        }
        else
            LOG1("= Pair detected - no more iteration")
    }

    LOG2("totalProbability", totalProbability)
    LOG2("totalProbability", Maths::roundProba(totalProbability * 100.f))
    return Maths::roundProba(totalProbability * 100.f);
}
