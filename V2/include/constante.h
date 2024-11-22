#ifndef CONSTANTE_H
#define CONSTANTE_H
#include "Expression.h"

class constante : public Expression {
public:
    constante(float v);
    virtual ~constante();
    void afficher();
    float calcul();
    Expression* simplifier() override; // Méthode de simplification

    float Getvaleur() { return m_valeur; }
    void Setvaleur(float val) { m_valeur = val; }

protected:

private:
    float m_valeur;
};

#endif // CONSTANTE_H
