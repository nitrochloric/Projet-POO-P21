#include "addition.h"
#include <iostream>
using namespace std;

addition::addition()
{
    //ctor
}

addition::~addition()
{
    //dtor
}

void addition::afficher(){
    cout << "(";
    this->m_opg->afficher();
    cout << "+";
    this->m_opd->afficher();
    cout << ")";
}

void addition::afficher_pinv(){
    this->m_opg->afficher_pinv();
    cout << " ";
    this->m_opd->afficher_pinv();
    cout << " + ";
}

float addition::calculer(){
    return this->m_opg->calculer() + this->m_opd->calculer();
}

expression* addition::simplifier() {
    expression* gauche = m_opg->simplifier();  // Simplifier l'opérande gauche
    expression* droite = m_opd->simplifier();  // Simplifier l'opérande droite

    // Vérifier si les deux opérandes sont des constantes
    if (dynamic_cast<cst*>(gauche) && dynamic_cast<cst*>(droite)) {
        return new cst(gauche->calculer() + droite->calculer());
    }

    // Si un des côtés est une cst et l'autre est une addition impliquant une cst
    if (dynamic_cast<cst*>(gauche) && dynamic_cast<addition*>(droite)) {
        addition* add_droite = dynamic_cast<addition*>(droite);
        if (dynamic_cast<cst*>(add_droite->m_opg)) {
            float somme = gauche->calculer() + add_droite->m_opg->calculer();
            return new addition(new cst(somme), add_droite->m_opd);
        }
    }

    if (dynamic_cast<cst*>(droite) && dynamic_cast<addition*>(gauche)) {
        addition* add_gauche = dynamic_cast<addition*>(gauche);
        if (dynamic_cast<cst*>(add_gauche->m_opg)) {
            float somme = droite->calculer() + add_gauche->m_opg->calculer();
            return new addition(new cst(somme), add_gauche->m_opd);
        }
    }

    // Si les simplifications plus profondes ne s'appliquent pas, retourner l'addition originale
    return new addition(gauche, droite);  // Retourner l'addition simplifiée
}
