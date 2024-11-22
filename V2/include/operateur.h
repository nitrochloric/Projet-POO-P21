#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "Expression.h"


class operateur : public Expression
{
    public:
        operateur();
        virtual ~operateur();
        Expression* getGauche() const { return m_opG; } // Accesseur pour l'opérande gauche
        Expression* getDroite() const { return m_opD; } // Accesseur pour l'opérande droite

    protected:
        Expression* m_opG;
        Expression* m_opD;


    private:
};

#endif // OPERATEUR_H
