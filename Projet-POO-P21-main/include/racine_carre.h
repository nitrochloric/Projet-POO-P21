#ifndef RACINE_CARRE_H
#define RACINE_CARRE_H

#include "include/operateur.h"

class racine_carre : public operateur
{
public:
    racine_carre();
    racine_carre(expression* arg) {m_opg=arg;}
    virtual ~racine_carre();

    void afficher(std::ostream& os = std::cout) override;
    void afficher_pinv(std::ostream& os = std::cout) override;
    float calculer() override;
    expression* simplifier() override {return this;}
    float evaluer(const table_symboles& table) const override;
    protected:

    private:
};

#endif // RACINE_CARRE_H
