#ifndef MULT_H
#define MULT_H

#include "operateur.h"


class mult : public operateur
{
    public:
        mult();
        mult(expression* arg1, expression* arg2){m_opg = arg1; m_opd = arg2;}
        virtual ~mult();

        void afficher() override ;
        void afficher_pinv() override ;
        float calculer() override ;

    protected:

    private:
};

#endif // MULT_H
