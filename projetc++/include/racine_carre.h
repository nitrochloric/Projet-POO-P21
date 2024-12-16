#ifndef RACINE_CARRE_H
#define RACINE_CARRE_H

#include "operateur.h"

class racine_carre : public operateur
{
public:
    racine_carre();
    racine_carre(expression* arg) {m_opg=arg;}
    virtual ~racine_carre();

    void afficher() override;
    void afficher_pinv() override;
    float calculer() override;

    protected:

    private:
};

#endif // RACINE_CARRE_H
