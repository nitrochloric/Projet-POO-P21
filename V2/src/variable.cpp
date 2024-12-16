#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>  // Pour std::cout
#include <stdexcept> // Pour std::runtime_error
#include "Variable.h"

#include "Expression.h"
#include <string>

class Variable : public Expression {
public:
    Variable(const std::string& nom) : m_nom(nom) {}
    virtual ~Variable() {}

    void afficher() override {
        std::cout << m_nom; // Affiche le nom de la variable (ex : x)
    }

    float calcul() override {
        throw std::runtime_error("Impossible de calculer une variable directement.");
    }

    Expression* simplifier() override {
        return this; // Les variables ne se simplifient pas.
    }

private:
    std::string m_nom; // Nom de la variable (ex: "x", "a")
};

#endif // VARIABLE_H
