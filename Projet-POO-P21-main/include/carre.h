#ifndef CARRE_H
#define CARRE_H

#include "include/operateur.h"

class carre : public operateur
{
public:
    carre();
    carre(expression* arg) {m_opg=arg;}
    virtual ~carre();

    void afficher(std::ostream& os = std::cout) override;
    void afficher_pinv(std::ostream& os = std::cout) override;
    float calculer() override;
    expression* simplifier() override {return this;}
    float evaluer(const table_symboles& table) const override;
    protected:

    private:
};

#endif // CARRE_H
