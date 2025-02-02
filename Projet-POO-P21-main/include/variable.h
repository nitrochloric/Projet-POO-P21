#ifndef VARIABLE_H
#define VARIABLE_H

#include "include/expression.h"
#include "include/table_symboles.h"
#include <string>
#include <iostream>

class variable : public expression {
public:
    variable(std::string nom) : m_nom(nom) {}
    virtual ~variable() {}

    std::string obtenir_nom() const { return m_nom; }

    void afficher(std::ostream& os = std::cout) override{
        os << m_nom;
    }

	void afficher_pinv(std::ostream& os = std::cout) override{
        os << m_nom;
	}

    float calculer() override{
        return 0.0;
    }

    expression* simplifier() override {
        return this; // Les variables ne peuvent pas être simplifiées
    }

    float evaluer(const table_symboles& table) const override{
        return table.obtenir_valeur(m_nom);
    }

private:
    std::string m_nom;
};

#endif // VARIABLE_H
