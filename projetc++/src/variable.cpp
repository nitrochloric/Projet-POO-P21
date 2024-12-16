#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>  // Pour std::cout
#include <stdexcept> // Pour std::runtime_error
#include "variable.h"

#include "expression.h"
#include <string>

class variable : public expression {
public:
    variable(const std::string& nom) : m_nom(nom) {}
    virtual ~variable() {}

    void afficher() override {
        std::cout << m_nom; // Affiche le nom de la variable (ex : x)
    }

    float calculer() override {
        throw std::runtime_error("Impossible de calculer une variable directement.");
    }

    expression* simplifier() override {
        return this; // Les variables ne se simplifient pas.
    }

private:
    std::string m_nom; // Nom de la variable (ex: "x", "a")
};

#endif // VARIABLE_H
