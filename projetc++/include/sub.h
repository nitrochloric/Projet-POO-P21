#ifndef SUB_H
#define SUB_H

#include "operateur.h"


class sub : public operateur
{
    public:
        sub();
        sub(expression* arg1, expression* arg2){m_opg = arg1; m_opd = arg2;}
        virtual ~sub();

        void afficher() override ;
        void afficher_pinv() override ;
        float calculer() override ;

    protected:

    private:
};

#endif // SUB_H
