#ifndef soustraction_H
#define soustraction_H

#include "operateur.h"


class soustraction : public operateur
{
    public:
        soustraction();
        soustraction(expression* arg1, expression* arg2){m_opg = arg1; m_opd = arg2;}
        virtual ~soustraction();

        void afficher() override ;
        void afficher_pinv() override ;
        float calculer() override ;

    protected:

    private:
};

#endif // soustraction_H
