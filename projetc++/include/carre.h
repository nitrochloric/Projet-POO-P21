#ifndef CARRE_H
#define CARRE_H

#include "operateur.h"

class carre : public operateur
{
public:
    carre();
    carre(expression* arg) {m_opg=arg;}
    virtual ~carre();

    void afficher() override;
    void afficher_pinv() override;
    float calculer() override;

    protected:

    private:
};

#endif // CARRE_H
