#include "Dealer.h"

#include <Deck.h>
#include <iostream>
#include <Maths.h>
#include <Game.h>
#include <QDir>

void Dealer::getAllPossibleDistributions(const QString & a_outputDirectoryPath, Game::PlayerCount a_playerCount)
{
    std::shared_ptr <Deck> deck(new Deck());

    QDir dir(a_outputDirectoryPath);
    if(! dir.exists())
        QDir().mkdir(a_outputDirectoryPath);

    QString directoryPath = QString("%1/%2players").arg(a_outputDirectoryPath).arg((unsigned int) a_playerCount);

    QDir dir2(directoryPath);
    if(! dir2.exists())
        QDir().mkdir(directoryPath);

    gatherDistributions(directoryPath, a_playerCount, 0, 0, deck);
}

void Dealer::gatherDistributions(const QString & a_outputDirectoryPath, Game::PlayerCount a_playerCount, unsigned int a_turn, unsigned int a_player, std::shared_ptr <Deck> & a_ioDeck)
{
    //std::cout << "[Dealer::gatherDistributions (" << a_playerCount << ")] turn : " << a_turn << " player : " << a_player << std::endl;

    if(a_turn <= 1)
    {
        std::vector <unsigned int> possibleCards = a_ioDeck->getAvailableCards();

        for(unsigned int cardId : possibleCards)
        {
            QString directoryPath = QString("%1/%2").arg(a_outputDirectoryPath).arg(std::to_string(cardId).c_str());

           // std::cout << directoryPath.toStdString() << std::endl;

            QDir dir(directoryPath);
            if(! dir.exists())
                QDir().mkdir(directoryPath);

            a_ioDeck->setCardEnabled(cardId, false);

            if(a_player + 1 < (unsigned int) a_playerCount)
                gatherDistributions(directoryPath, a_playerCount, a_turn, a_player + 1, a_ioDeck);
            else
                gatherDistributions(directoryPath, a_playerCount, a_turn + 1, 0, a_ioDeck);

            a_ioDeck->setCardEnabled(cardId, true);
        }
    }
    else
    {
        //std::cout << "Registering game" << std::endl;
    }
}

void Dealer::getAllPossibleStartHands(std::vector <std::shared_ptr <Hand>> & a_outHands)
{
    a_outHands.clear();

    std::unique_ptr <Deck> deck(new Deck());

    std::cout << Maths::binomialCoeff(52, 2) << std::endl;

}

