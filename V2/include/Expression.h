#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public:
    Expression();
    virtual ~Expression();
    virtual void afficher() = 0;
    virtual float calcul() = 0;
    virtual Expression* simplifier() = 0; // Méthode de simplification

protected:

private:
};

#endif // EXPRESSION_H
