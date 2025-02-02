#ifndef OPPOSE_H
#define OPPOSE_H

#include "include/operateur.h"

class oppose : public operateur
{
public:
    oppose(expression* arg){m_opg=arg;}
    virtual ~oppose();

    void afficher(std::ostream& os = std::cout) override;
    void afficher_pinv(std::ostream& os = std::cout) override;
    float calculer() override;
    expression* simplifier() override {return this;}
    float evaluer(const table_symboles& table) const override;
    protected:

    private:
};

#endif // OPPOSE_H
