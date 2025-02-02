#ifndef soustraction_H
#define soustraction_H

#include "include/operateur.h"


class soustraction : public operateur
{
    public:
        soustraction();
        soustraction(expression* arg1, expression* arg2){m_opg = arg1; m_opd = arg2;}
        virtual ~soustraction();

        void afficher(std::ostream& os = std::cout) override ;
        void afficher_pinv(std::ostream& os = std::cout) override ;
        float calculer() override ;
        expression* simplifier() override;
        float evaluer(const table_symboles& table) const override;
    protected:

    private:
};

#endif // soustraction_H
