#ifndef OPPOSE_H
#define OPPOSE_H

#include "operateur.h"

class oppose : public operateur
{
public:
    oppose(expression* arg){m_opg=arg;}
    virtual ~oppose();

    void afficher() override;
    void afficher_pinv() override;
    float calculer() override;

    protected:

    private:
};

#endif // OPPOSE_H
