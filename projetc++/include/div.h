#ifndef DIV_H
#define DIV_H

#include "operateur.h"


class divd : public operateur
{
    public:
        divd();
        divd(expression* arg1, expression* arg2){m_opg = arg1; m_opd = arg2;}
        virtual ~divd();

        void afficher() override ;
        void afficher_pinv() override ;
        float calculer() override ;

    protected:

    private:
};

#endif // DIV_H
