#ifndef addition_H
#define addition_H

#include "include/operateur.h"


class addition : public operateur
{
    public:
        addition();
        addition(expression* arg1, expression* arg2){m_opg = arg1; m_opd = arg2;}
        virtual ~addition();

        void afficher(std::ostream& os = std::cout) override ;
        void afficher_pinv(std::ostream& os = std::cout) override ;
        float calculer() override ;
		expression* simplifier() override;
		float evaluer(const table_symboles& table) const override;
    protected:

    private:
};

#endif // addition_H
