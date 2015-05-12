#include "Game.h"
#include "Deck.h"

Game::Game(PlayerCount a_playerCount)
    : m_playerCount(a_playerCount)
{
    m_deck.reset(new Deck());
}

Game::Game(PlayerCount a_playerCount, const std::shared_ptr <Deck> & a_deck)
    : m_playerCount(a_playerCount)
    , m_deck(a_deck)
{
}

Game::~Game()
{

}

unsigned int Game::playerCountAsUInt(PlayerCount a_playerCount)
{
    switch(a_playerCount)
    {
        case PlayerCount::TWO : return 2;
        case PlayerCount::THREE : return 3;
        case PlayerCount::FOUR : return 4;
        case PlayerCount::FIVE : return 5;
        case PlayerCount::SiX : return 6;
        case PlayerCount::SEVEN : return 7;
        case PlayerCount::EIGHT : return 8;
        case PlayerCount::NINE : return 9;
        case PlayerCount::TEN : return 10;
    }

    return 0;
}
