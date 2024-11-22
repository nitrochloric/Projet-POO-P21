#ifndef ADD_H
#define ADD_H

#include "operateur.h"


class add : public operateur
{
    public:
        add();
        add(expression* arg1, expression* arg2){m_opg = arg1; m_opd = arg2;}
        virtual ~add();

        void afficher() override ;
        void afficher_pinv() override ;
        float calculer() override ;

    protected:

    private:
};

#endif // ADD_H
