#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "operateur.h"

class multiplication : public operateur {
public:
    multiplication(Expression* eg, Expression* ed);
    virtual ~multiplication();
    void afficher();
    float calcul();
    Expression* simplifier() override; // Méthode de simplification

protected:

private:
};

#endif // MULTIPLICATION_H
