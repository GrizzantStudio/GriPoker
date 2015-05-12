#ifndef GAME_H
#define GAME_H

#include <memory>

class Deck;

class Game
{
public :

    enum PlayerCount : int
    {
        ONE = 1,
        TWO = 2,
        THREE = 3,
        FOUR = 4,
        FIVE = 5,
        SiX = 6,
        SEVEN = 7,
        EIGHT = 8,
        NINE = 9,
        TEN = 10
    };

private :

    PlayerCount m_playerCount;
    std::shared_ptr <Deck> m_deck;

public:
    Game(PlayerCount a_playerCount);
    Game(PlayerCount a_playerCount, const std::shared_ptr <Deck> & a_deck);
    ~Game();

public :

    static unsigned int playerCountAsUInt(PlayerCount a_playerCount);
};

#endif // GAME_H
