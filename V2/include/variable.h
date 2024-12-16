#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"
#include <string>
#include <iostream>

class Variable : public Expression {
public:
    Variable(std::string nom) : m_nom(nom) {}
    virtual ~Variable() {}

    void afficher() {
        std::cout << m_nom;
    }

    float calcul() {
        throw std::runtime_error("Variable non définie");
    }

    Expression* simplifier() override {
        return this; // Les variables ne peuvent pas être simplifiées
    }

private:
    std::string m_nom;
};

#endif // VARIABLE_H
