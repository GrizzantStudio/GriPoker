#ifndef DEALER_H
#define DEALER_H

#include <Game.h>
#include <memory>
#include <vector>

class Dealer
{
public :

    static std::vector <std::shared_ptr <Game>> getAllPossibleDistributions(Game::PlayerCount a_playerCount);
};

#endif // DEALER_H
