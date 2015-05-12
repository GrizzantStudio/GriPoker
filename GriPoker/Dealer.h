#ifndef DEALER_H
#define DEALER_H

#include <Game.h>
#include <Hand.h>
#include <memory>
#include <vector>

class Dealer
{
public :

    static void getAllPossibleDistributions(const QString & a_outputDirectoryPath, Game::PlayerCount a_playerCount);
    static void getAllPossibleStartHands(std::vector <std::shared_ptr <Hand>> & a_outHands);

private :

    static void gatherDistributions(const QString & a_outputDirectoryPath, Game::PlayerCount a_playerCount, unsigned int a_turn, unsigned int a_player, std::shared_ptr <Deck> & a_ioDeck);

};

#endif // DEALER_H
