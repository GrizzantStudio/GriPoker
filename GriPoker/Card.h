#ifndef CARD_H
#define CARD_H


class Card
{
public :

    enum class Symbol
    {
        Spade,
        Heart,
        Diamond,
        Club
    };

    enum class Value
    {
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        Ace
    };

private :

    unsigned int m_id;
    Symbol m_symbol;
    Value m_value;

public:
    Card(unsigned int a_id, Symbol a_symbol, Value a_value);
    ~Card();

public :

    Symbol getSymbol();
    Value getValue();
    unsigned int getId();
};

#endif // CARD_H
