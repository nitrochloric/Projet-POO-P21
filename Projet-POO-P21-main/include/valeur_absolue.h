#ifndef VALEUR_ABSOLUE_H
#define VALEUR_ABSOLUE_H

#include "include/operateur.h"

class valeur_absolue : public operateur
{
public:
    valeur_absolue(expression* arg){m_opg=arg;}
    virtual ~valeur_absolue();

    void afficher(std::ostream& os = std::cout) override;
    void afficher_pinv(std::ostream& os = std::cout) override;
    float calculer() override;
    expression* simplifier() override {return this;}
    float evaluer(const table_symboles& table) const override;
    protected:

    private:
};

#endif // VALEUR_ABSOLUE_H
