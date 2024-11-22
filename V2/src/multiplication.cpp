#include "multiplication.h"
#include <iostream>
#include "constante.h"
using namespace std;

multiplication::multiplication(Expression* eg, Expression* ed) {
    m_opG = eg;
    m_opD = ed;
}

multiplication::~multiplication() {
    // dtor
}

void multiplication::afficher() {
    m_opG->afficher();
    cout << "*";
    m_opD->afficher();
}

float multiplication::calcul() {
    return m_opG->calcul() * m_opD->calcul();
}


Expression* multiplication::simplifier() {
    Expression* gauche = m_opG->simplifier();  // Simplifier l'opérande gauche
    Expression* droite = m_opD->simplifier();  // Simplifier l'opérande droite

    // Vérifier si les deux opérandes sont des constantes
    if (dynamic_cast<constante*>(gauche) && dynamic_cast<constante*>(droite)) {
        return new constante(gauche->calcul() * droite->calcul());
    }

    // Cas où un des opérandes est 1, car multiplier par 1 ne change rien
    if (dynamic_cast<constante*>(gauche) && gauche->calcul() == 1) {
        return droite;  // Retourner juste l'opérande droite
    }
    if (dynamic_cast<constante*>(droite) && droite->calcul() == 1) {
        return gauche;  // Retourner juste l'opérande gauche
    }

    // Cas où un des opérandes est 0, car multiplier par 0 donne toujours 0
    if (dynamic_cast<constante*>(gauche) && gauche->calcul() == 0) {
        return new constante(0);
    }
    if (dynamic_cast<constante*>(droite) && droite->calcul() == 0) {
        return new constante(0);
    }

    // Simplification de multiplication imbriquée avec une constante
    if (dynamic_cast<constante*>(gauche) && dynamic_cast<multiplication*>(droite)) {
        multiplication* mul_droite = dynamic_cast<multiplication*>(droite);
        if (dynamic_cast<constante*>(mul_droite->m_opG)) {
            float produit = gauche->calcul() * mul_droite->m_opG->calcul();
            return new multiplication(new constante(produit), mul_droite->m_opD);
        }
    }

    if (dynamic_cast<constante*>(droite) && dynamic_cast<multiplication*>(gauche)) {
        multiplication* mul_gauche = dynamic_cast<multiplication*>(gauche);
        if (dynamic_cast<constante*>(mul_gauche->m_opG)) {
            float produit = droite->calcul() * mul_gauche->m_opG->calcul();
            return new multiplication(new constante(produit), mul_gauche->m_opD);
        }
    }

    // Si les simplifications plus profondes ne s'appliquent pas, retourner la multiplication originale
    return new multiplication(gauche, droite);  // Retourner la multiplication simplifiée
}
