#ifndef COMBINAISON_H
#define COMBINAISON_H

#include <QString>
#include <QVector>
#include <QSharedPointer>

class Combinaison
{
public :

    enum class Type
    {
        SUITE_COULEUR_ROYALE,
        SUITE_COULEUR,
        CARREE,
        FULL,
        COULEUR,
        SUITE,
        BRELAN,
        DOUBLE_PAIRE,
        PAIRE,
        HAUTEUR
    };

private :

    Type m_type;
    unsigned int m_strength;
    QString m_typeString;

private :
    Combinaison(Type a_type);

public :
    ~Combinaison();

public :

    Type getType();
    unsigned int getStrength();
    QString getTypeString();

public :

    static QVector <QSharedPointer <Combinaison>> getAllCombinaisons();
};

#endif // COMBINAISON_H
