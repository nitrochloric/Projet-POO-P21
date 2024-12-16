#ifndef SOUSTRACTION_H
#define SOUSTRACTION_H

#include "operateur.h"

class soustraction : public operateur {
public:
    soustraction(Expression* eg, Expression* ed);
    virtual ~soustraction();
    void afficher();
    float calcul();
    Expression* simplifier() override; // Méthode de simplification

protected:

private:
};

#endif // SOUSTRACTION_H
