#include "Combinaison.h"

Combinaison::Combinaison(Type a_type)
    : m_type(a_type)
{
    switch(m_type)
    {
    case Type::SUITE_COULEUR_ROYALE :
        m_strength = 9;
        m_typeString = "Suite couleur royale";
        break;

    case Type::SUITE_COULEUR :
        m_strength = 8;
        m_typeString = "Suite couleur";
    break;

    case Type::CARREE :
        m_strength = 7;
        m_typeString = "Carrée";
    break;

    case Type::FULL :
        m_strength = 6;
        m_typeString = "Full";
    break;

    case Type::COULEUR :
        m_strength = 5;
        m_typeString = "Couleur";
    break;

    case Type::SUITE :
        m_strength = 4;
        m_typeString = "Suite";
    break;

    case Type::BRELAN :
        m_strength = 3;
        m_typeString = "Brelan";
    break;

    case Type::DOUBLE_PAIRE :
        m_strength = 2;
        m_typeString = "Double paire";
    break;

    case Type::PAIRE :
        m_strength = 1;
        m_typeString = "Paire";
    break;

    case Type::HAUTEUR :
        m_strength = 0;
        m_typeString = "Hauteur";
    break;
    }
}

Combinaison::~Combinaison()
{

}

Combinaison::Type Combinaison::getType()
{
    return m_type;
}

QString Combinaison::getTypeString()
{
    return m_typeString;
}

unsigned int Combinaison::getStrength()
{
    return m_strength;
}

QVector <QSharedPointer <Combinaison>> Combinaison::getAllCombinaisons()
{
    QVector <QSharedPointer<Combinaison>> combinaisons;
    combinaisons.push_back(QSharedPointer <Combinaison> (new Combinaison(Type::SUITE_COULEUR_ROYALE)));
    combinaisons.push_back(QSharedPointer <Combinaison> (new Combinaison(Type::SUITE_COULEUR)));
    combinaisons.push_back(QSharedPointer <Combinaison> (new Combinaison(Type::CARREE)));
    combinaisons.push_back(QSharedPointer <Combinaison> (new Combinaison(Type::FULL)));
    combinaisons.push_back(QSharedPointer <Combinaison> (new Combinaison(Type::COULEUR)));
    combinaisons.push_back(QSharedPointer <Combinaison> (new Combinaison(Type::SUITE)));
    combinaisons.push_back(QSharedPointer <Combinaison> (new Combinaison(Type::BRELAN)));
    combinaisons.push_back(QSharedPointer <Combinaison> (new Combinaison(Type::DOUBLE_PAIRE)));
    combinaisons.push_back(QSharedPointer <Combinaison> (new Combinaison(Type::PAIRE)));
    combinaisons.push_back(QSharedPointer <Combinaison> (new Combinaison(Type::HAUTEUR)));
    return combinaisons;
}
