#ifndef INVERSE_H
#define INVERSE_H

#include "include/operateur.h"

class inverse : public operateur
{
public:
    inverse();
    inverse(expression* arg) {m_opg=arg;}
    virtual ~inverse();

    void afficher(std::ostream& os = std::cout) override;
    void afficher_pinv(std::ostream& os = std::cout) override;
    float calculer() override;
    expression* simplifier() override {return this;}
    float evaluer(const table_symboles& table) const override;
    protected:

    private:

};

#endif // INVERSE_H
