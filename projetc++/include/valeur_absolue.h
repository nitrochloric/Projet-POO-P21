#ifndef VALEUR_ABSOLUE_H
#define VALEUR_ABSOLUE_H

#include "operateur.h"

class valeur_absolue : public operateur
{
public:
    valeur_absolue(expression* arg){m_opg=arg;}
    virtual ~valeur_absolue();

    void afficher() override;
    void afficher_pinv() override;
    float calculer() override;

    protected:

    private:
};

#endif // VALEUR_ABSOLUE_H
