#include "soustraction.h"
#include "constante.h"
#include "addition.h"
#include "Variable.h"
#include <iostream>
using namespace std;

soustraction::soustraction(Expression* eg, Expression* ed) {
    m_opG = eg;
    m_opD = ed;
}

soustraction::~soustraction() {
    // dtor
}

void soustraction::afficher() {
    cout << "(";
    m_opG->afficher();
    cout << "-";
    m_opD->afficher();
    cout << ")";
}

float soustraction::calcul() {
    return m_opG->calcul() - m_opD->calcul();
}


Expression* soustraction::simplifier() {
    Expression* gauche = m_opG->simplifier();  // Simplifier l'opérande gauche
    Expression* droite = m_opD->simplifier();  // Simplifier l'opérande droite

    // Vérifier si les deux opérandes sont des constantes
    if (dynamic_cast<constante*>(gauche) && dynamic_cast<constante*>(droite)) {
        return new constante(gauche->calcul() - droite->calcul());
    }

    // Si un des côtés est une constante et l'autre est une soustraction impliquant une constante
    if (dynamic_cast<constante*>(gauche) && dynamic_cast<soustraction*>(droite)) {
        soustraction* sub_droite = dynamic_cast<soustraction*>(droite);
        if (dynamic_cast<constante*>(sub_droite->m_opG)) {
            float difference = gauche->calcul() - sub_droite->m_opG->calcul();
            return new soustraction(new constante(difference), sub_droite->m_opD);
        }
    }

    if (dynamic_cast<constante*>(droite) && dynamic_cast<soustraction*>(gauche)) {
        soustraction* sub_gauche = dynamic_cast<soustraction*>(gauche);
        if (dynamic_cast<constante*>(sub_gauche->m_opG)) {
            float difference = sub_gauche->m_opG->calcul() - droite->calcul();
            return new soustraction(new constante(difference), sub_gauche->m_opD);
        }
    }

    // Si les simplifications plus profondes ne s'appliquent pas, retourner la soustraction originale
    return new soustraction(gauche, droite);  // Retourner la soustraction simplifiée
}

