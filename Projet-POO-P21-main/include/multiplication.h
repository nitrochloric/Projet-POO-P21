#ifndef multiplication_H
#define multiplication_H

#include "include/operateur.h"


class multiplication : public operateur
{
    public:
        multiplication();
        multiplication(expression* arg1, expression* arg2){m_opg = arg1; m_opd = arg2;}
        virtual ~multiplication();

        void afficher(std::ostream& os = std::cout) override ;
        void afficher_pinv(std::ostream& os = std::cout) override ;
        float calculer() override ;
        expression* simplifier() override;
        float evaluer(const table_symboles& table) const override;
    protected:

    private:
};

#endif // multiplication_H
