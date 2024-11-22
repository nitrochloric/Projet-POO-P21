#include "division.h"
#include <iostream>
#include "constante.h"

#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"

using namespace std;

division::division(Expression* eg, Expression* ed) {
    m_opG = eg;
    m_opD = ed;
}

division::~division() {
    // Destructeur
}

void division::afficher() {
    cout << "(";
    m_opG->afficher();
    cout << "/";
    m_opD->afficher();
    cout << ")";
}

float division::calcul() {
    return m_opG->calcul() / m_opD->calcul();
}



Expression* division::simplifier() {
    Expression* num = m_opG->simplifier();  // Simplifier le numérateur
    Expression* denom = m_opD->simplifier(); // Simplifier le dénominateur

    // Vérifier si le numérateur est une addition
    if (addition* add = dynamic_cast<addition*>(num)) {
        Expression* gauche = add->getGauche()->simplifier();
        Expression* droite = add->getDroite()->simplifier();

        // Créer les nouvelles divisions
        Expression* div1 = new division(gauche, denom);
        Expression* div2 = new division(droite, denom);

        // Retourner l'addition des deux nouvelles divisions
        return new addition(div1, div2);
    }

    // Si la simplification plus profonde ne s'applique pas, retourner la division originale
    return new division(num, denom);  // Retourner la division simplifiée
}
