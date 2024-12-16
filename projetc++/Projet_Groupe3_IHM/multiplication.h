#ifndef multiplication_H
#define multiplication_H

#include "operateur.h"


class multiplication : public operateur
{
public:
    multiplication();
    multiplication(expression* arg1, expression* arg2){m_opg = arg1; m_opd = arg2;}
    virtual ~multiplication();

    void afficher() override ;
    void afficher_pinv() override ;
    float calculer() override ;

protected:

private:
};

#endif // multiplication_H
