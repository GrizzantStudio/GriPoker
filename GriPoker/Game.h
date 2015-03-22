#ifndef GAME_H
#define GAME_H

#include <memory>

class Deck;

class Game
{
public :

    enum class PlayerCount
    {
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SiX,
        SEVEN,
        EIGHT,
        NINE,
        TEN
    };

private :

    PlayerCount m_playerCount;
    std::shared_ptr <Deck> m_deck;

public:
    Game(PlayerCount a_playerCount);
    ~Game();
};

#endif // GAME_H
