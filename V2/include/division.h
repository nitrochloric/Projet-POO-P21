#ifndef DIVISION_H
#define DIVISION_H

#include "operateur.h"

class division : public operateur {
public:
    division(Expression* eg, Expression* ed);
    virtual ~division();
    void afficher();
    float calcul();
    Expression* simplifier() override; // Méthode de simplification

protected:

private:
};

#endif // DIVISION_H
