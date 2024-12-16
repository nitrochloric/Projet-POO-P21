#ifndef VARIABLE_H
#define VARIABLE_H

#include "expression.h"
#include <string>
#include <iostream>

class variable : public expression {
public:
    variable(std::string nom) : m_nom(nom) {}
    virtual ~variable() {}

    void afficher() {
        std::cout << m_nom;
    }

	void afficher_pinv(){
        std::cout << m_nom;
	}

    float calculer() {
        throw std::runtime_error("variable non définie");
    }

    expression* simplifier() override {
        return this; // Les variables ne peuvent pas être simplifiées
    }

private:
    std::string m_nom;
};

#endif // VARIABLE_H
