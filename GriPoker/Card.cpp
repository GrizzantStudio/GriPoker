#include "Card.h"

Card::Card(unsigned int a_id, Symbol a_symbol, Value a_value)
    : m_symbol(a_symbol)
    , m_value(a_value)
    , m_id(a_id)
{

}

Card::~Card()
{

}

Card::Symbol Card::getSymbol()
{
    return m_symbol;
}

Card::Value Card::getValue()
{
    return m_value;
}

unsigned int Card::getId()
{
    return m_id;
}
