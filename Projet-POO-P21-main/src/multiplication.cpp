#include "include/multiplication.h"
#include "include/cst.h"
#include <iostream>
using namespace std;

multiplication::multiplication()
{
    //ctor
}

multiplication::~multiplication()
{
    //dtor
}

void multiplication::afficher(std::ostream& os) {
    os << "(";
    this->m_opg->afficher(os);
    os << "*";
    this->m_opd->afficher(os);
    os << ")";
}

void multiplication::afficher_pinv(std::ostream& os){
    this->m_opg->afficher_pinv(os);
    os << " ";
    this->m_opd->afficher_pinv(os);
    os << " * ";
}

float multiplication::calculer(){
    return this->m_opg->calculer() * this->m_opd->calculer();
}

float multiplication::evaluer(const table_symboles& table) const {
    return this->m_opg->evaluer(table) * this->m_opd->evaluer(table);
}

expression* multiplication::simplifier() {
    expression* gauche = m_opg->simplifier();  // Simplifier l'opérande gauche
    expression* droite = m_opd->simplifier();  // Simplifier l'opérande droite

    // Vérifier si les deux opérandes sont des constantes
    if (dynamic_cast<cst*>(gauche) && dynamic_cast<cst*>(droite)) {
        return new cst(gauche->calculer() * droite->calculer());
    }

    // Cas où un des opérandes est 1, car multiplier par 1 ne change rien
    if (dynamic_cast<cst*>(gauche) && gauche->calculer() == 1) {
        return droite;  // Retourner juste l'opérande droite
    }
    if (dynamic_cast<cst*>(droite) && droite->calculer() == 1) {
        return gauche;  // Retourner juste l'opérande gauche
    }

    // Cas où un des opérandes est 0, car multiplier par 0 donne toujours 0
    if (dynamic_cast<cst*>(gauche) && gauche->calculer() == 0) {
        return new cst(0);
    }
    if (dynamic_cast<cst*>(droite) && droite->calculer() == 0) {
        return new cst(0);
    }

    // Simplification de multiplication imbriquée avec une cst
    if (dynamic_cast<cst*>(gauche) && dynamic_cast<multiplication*>(droite)) {
        multiplication* mul_droite = dynamic_cast<multiplication*>(droite);
        if (dynamic_cast<cst*>(mul_droite->m_opg)) {
            float produit = gauche->calculer() * mul_droite->m_opg->calculer();
            return new multiplication(new cst(produit), mul_droite->m_opd);
        }
    }

    if (dynamic_cast<cst*>(droite) && dynamic_cast<multiplication*>(gauche)) {
        multiplication* mul_gauche = dynamic_cast<multiplication*>(gauche);
        if (dynamic_cast<cst*>(mul_gauche->m_opg)) {
            float produit = droite->calculer() * mul_gauche->m_opg->calculer();
            return new multiplication(new cst(produit), mul_gauche->m_opd);
        }
    }

    // Si les simplifications plus profondes ne s'appliquent pas, retourner la multiplication originale
    return new multiplication(gauche, droite);  // Retourner la multiplication simplifiée
}
