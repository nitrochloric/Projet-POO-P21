#ifndef INVERSE_H
#define INVERSE_H

#include "operateur.h"

class inverse : public operateur
{
public:
    inverse();
    inverse(expression* arg) {m_opg=arg;}
    virtual ~inverse();

    void afficher() override;
    void afficher_pinv() override;
    float calculer() override;

    protected:

    private:

};

#endif // INVERSE_H
