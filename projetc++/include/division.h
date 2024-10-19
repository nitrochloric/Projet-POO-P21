#ifndef DIV_H
#define DIV_H

#include "operateur.h"


class division : public operateur
{
    public:
        division();
        division(expression* arg1, expression* arg2){m_opg = arg1; m_opd = arg2;}
        virtual ~division();

        void afficher() override ;
        void afficher_pinv() override ;
        float calculer() override ;

    protected:

    private:
};

#endif // DIV_H
