#include "Card.h"

#include <QPixmap>
#include <iostream>

Tmpl_Enum<std::string, Card::Symbol>::instances_list Tmpl_Enum <std::string, Card::Symbol>::s_instances;

const Card::Symbol Card::Symbol::Undefined("undefined");
const Card::Symbol Card::Symbol::Spade("spade");
const Card::Symbol Card::Symbol::Heart("heart");
const Card::Symbol Card::Symbol::Diamond("diamond");
const Card::Symbol Card::Symbol::Club("club");

Tmpl_Enum<std::string, Card::Value>::instances_list Tmpl_Enum <std::string, Card::Value>::s_instances;

const Card::Value Card::Value::Undefined("undefined");
const Card::Value Card::Value::Two("2");
const Card::Value Card::Value::Three("3");
const Card::Value Card::Value::Four("4");
const Card::Value Card::Value::Five("5");
const Card::Value Card::Value::Six("6");
const Card::Value Card::Value::Seven("7");
const Card::Value Card::Value::Eight("8");
const Card::Value Card::Value::Nine("9");
const Card::Value Card::Value::Ten("10");
const Card::Value Card::Value::Jack("j");
const Card::Value Card::Value::Queen("q");
const Card::Value Card::Value::King("k");
const Card::Value Card::Value::Ace("a");

Card::Card(unsigned int a_id, Symbol a_symbol, Value a_value)
    : m_symbol(a_symbol)
    , m_value(a_value)
    , m_id(a_id)
    , m_pixmap(nullptr)
    , m_isValid(true)
{
}

Card::Card(const Card & a_cardToCopy)
    : m_symbol(a_cardToCopy.m_symbol)
    , m_value(a_cardToCopy.m_value)
    , m_pixmap(nullptr)
{
    m_id = a_cardToCopy.m_id;
    m_isValid = a_cardToCopy.m_isValid;
}

Card::Card(const std::string a_encodedData)
    : m_symbol(Card::Symbol::Undefined)
    , m_value(Card::Value::Undefined)
    , m_isValid(false)
    , m_pixmap(nullptr)
{
    decodeAndSet(a_encodedData);
}

Card::~Card()
{

}

unsigned int Card::getId()
{
    return m_id;
}

std::shared_ptr <QPixmap> Card::getPixmap()
{
    if(! m_isValid)
        return nullptr;

    if(m_pixmap == nullptr)
        buildPixmap();

    return m_pixmap;
}

void Card::buildPixmap()
{
    std::string symbol = m_symbol.Get_Value();
    std::string value = m_value.Get_Value();

    std::string imageResource = std::string(":/images/") + value + symbol + ".png";
    m_pixmap.reset(new QPixmap(imageResource.c_str()));
}

std::string Card::encodeAsString()
{
    return m_value.Get_Value() + "|" + m_symbol.Get_Value();
}

void Card::decodeAndSet(const std::string & a_encodedData)
{
    size_t separatorPos = a_encodedData.find_first_of("|");

    if(separatorPos == std::string::npos)
    {
        m_isValid = false;
        return;
    }

    std::string valueString = a_encodedData.substr(0, separatorPos);
    std::string symbolString = a_encodedData.substr(separatorPos + 1);

    m_symbol = Card::Symbol::Undefined;

    if(symbolString == "spade") m_symbol = Card::Symbol::Spade;
    else if(symbolString == "heart") m_symbol = Card::Symbol::Heart;
    else if(symbolString == "diamond") m_symbol = Card::Symbol::Diamond;
    else if(symbolString == "club") m_symbol = Card::Symbol::Club;

    m_value = Card::Value::Undefined;

    if(valueString == "2") m_value = Card::Value::Two;
    else if(valueString == "3") m_value = Card::Value::Three;
    else if(valueString == "4") m_value = Card::Value::Four;
    else if(valueString == "5") m_value = Card::Value::Five;
    else if(valueString == "6") m_value = Card::Value::Six;
    else if(valueString == "7") m_value = Card::Value::Seven;
    else if(valueString == "8") m_value = Card::Value::Eight;
    else if(valueString == "9") m_value = Card::Value::Nine;
    else if(valueString == "10") m_value = Card::Value::Ten;
    else if(valueString == "j") m_value = Card::Value::Jack;
    else if(valueString == "q") m_value = Card::Value::Queen;
    else if(valueString == "k") m_value = Card::Value::King;
    else if(valueString == "a") m_value = Card::Value::Ace;

    m_id = 0;
    m_isValid = true;

}

bool Card::isValid()
{
    return m_isValid;
}
