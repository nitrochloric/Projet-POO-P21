#include "addition.h"
#include <iostream>
using namespace std;

addition::addition(Expression* eg, Expression* ed) {
    m_opG = eg;
    m_opD = ed;
}

addition::~addition() {
    // dtor
}

void addition::afficher() {
    cout << "(";
    m_opG->afficher();
    cout << "+";
    m_opD->afficher();
    cout << ")";
}

float addition::calcul() {
    return m_opG->calcul() + m_opD->calcul();
}

Expression* addition::simplifier() {
    Expression* gauche = m_opG->simplifier();  // Simplifier l'opérande gauche
    Expression* droite = m_opD->simplifier();  // Simplifier l'opérande droite

    // Vérifier si les deux opérandes sont des constantes
    if (dynamic_cast<constante*>(gauche) && dynamic_cast<constante*>(droite)) {
        return new constante(gauche->calcul() + droite->calcul());
    }

    // Si un des côtés est une constante et l'autre est une addition impliquant une constante
    if (dynamic_cast<constante*>(gauche) && dynamic_cast<addition*>(droite)) {
        addition* add_droite = dynamic_cast<addition*>(droite);
        if (dynamic_cast<constante*>(add_droite->m_opG)) {
            float somme = gauche->calcul() + add_droite->m_opG->calcul();
            return new addition(new constante(somme), add_droite->m_opD);
        }
    }

    if (dynamic_cast<constante*>(droite) && dynamic_cast<addition*>(gauche)) {
        addition* add_gauche = dynamic_cast<addition*>(gauche);
        if (dynamic_cast<constante*>(add_gauche->m_opG)) {
            float somme = droite->calcul() + add_gauche->m_opG->calcul();
            return new addition(new constante(somme), add_gauche->m_opD);
        }
    }

    // Si les simplifications plus profondes ne s'appliquent pas, retourner l'addition originale
    return new addition(gauche, droite);  // Retourner l'addition simplifiée
}




