#include "Game.h"
#include "Deck.h"

Game::Game(PlayerCount a_playerCount)
    : m_playerCount(a_playerCount)
{
    m_deck.reset(new Deck());
}

Game::~Game()
{

}

