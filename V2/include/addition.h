#ifndef ADDITION_H
#define ADDITION_H

#include "operateur.h"
#include "constante.h"

class addition : public operateur {
public:
    addition(Expression* eg, Expression* ed);
    virtual ~addition();
    void afficher();
    float calcul();
    Expression* simplifier() override; // Méthode de simplification

protected:

private:
};

#endif // ADDITION_H
