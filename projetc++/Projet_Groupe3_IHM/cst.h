#ifndef CST_H
#define CST_H

#include "expression.h"


class cst : public expression
{
public:
    cst();
    cst(float arg){m_valeur = arg;}
    virtual ~cst();

     float Getvaleur() { return m_valeur; }
    void Setvaleur( float val) { m_valeur = val; }

     float m_valeur;

    void afficher() override ;
    void afficher_pinv() override ;
    float calculer() override ;


protected:

private:
};

#endif // CST_H
