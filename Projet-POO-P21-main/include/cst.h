#ifndef CST_H
#define CST_H

#include "include/expression.h"
#include "include/table_symboles.h"

class cst : public expression
{
    public:
        cst();
        cst(float arg){m_valeur = arg;}
        virtual ~cst();

        float Getvaleur() { return m_valeur; }
        void Setvaleur(float val) { m_valeur = val; }

        float m_valeur;

        void afficher(std::ostream& os = std::cout) override ;
        void afficher_pinv(std::ostream& os = std::cout) override ;
        float calculer() override ;
        expression* simplifier() override;
        float evaluer(const table_symboles& table) const override;
    protected:

    private:
};

#endif // CST_H
