#ifndef CST_H
#define CST_H

#include "expression.h"


class cst : public expression
{
    public:
        cst();
        cst(float arg){m_valeur = arg;}
        virtual ~cst();

        unsigned int Getvaleur() { return m_valeur; }
        void Setvaleur(unsigned int val) { m_valeur = val; }

        unsigned int m_valeur;

        void afficher() override ;
        void afficher_pinv() override ;
        float calculer() override ;


    protected:

    private:
};

#endif // CST_H
