#ifndef addition_H
#define addition_H

#include "operateur.h"
#include "cst.h"

class addition : public operateur
{
    public:
        addition();
        addition(expression* arg1, expression* arg2){m_opg = arg1; m_opd = arg2;}
        virtual ~addition();

        void afficher() override ;
        void afficher_pinv() override ;
        float calculer() override ;
		expression* simplifier() override;
    protected:

    private:
};

#endif // addition_H
