#ifndef CARD_H
#define CARD_H

#include <memory>
#include <string>

#include <EnumFlags.h>

class QPixmap;

class Card
{
public :

    class Symbol : public Tmpl_Enum <std::string, Symbol>
    {
        private:

      explicit Symbol(const std::string & a_value)
            : Tmpl_Enum <std::string, Symbol>(a_value)
        {
        }

    public:

      static const Symbol Undefined;
      static const Symbol Spade;
      static const Symbol Heart;
      static const Symbol Diamond;
      static const Symbol Club;
    };

    class Value : public Tmpl_Enum <std::string, Value>
    {
        private:

      explicit Value(const std::string & a_value)
            : Tmpl_Enum <std::string, Value>(a_value)
        {
        }

    public:

      static const Value Undefined;
      static const Value Two;
      static const Value Three;
      static const Value Four;
      static const Value Five;
      static const Value Six;
      static const Value Seven;
      static const Value Eight;
      static const Value Nine;
      static const Value Ten;
      static const Value Jack;
      static const Value Queen;
      static const Value King;
      static const Value Ace;
    };

private :

    unsigned int m_id;
    Symbol m_symbol;
    Value m_value;
    std::shared_ptr <QPixmap> m_pixmap;
    bool m_isValid;

public:
    Card(unsigned int a_id, Symbol a_symbol, Value a_value);
    Card(const Card & a_cardToCopy);
    Card(const std::string a_encodedData);
    ~Card();

public :

    unsigned int getId();
    std::shared_ptr <QPixmap> getPixmap();
    std::string encodeAsString();
    bool isValid();

private :

    void buildPixmap();
    void decodeAndSet(const std::string & a_encodedData);
};

#endif // CARD_H
