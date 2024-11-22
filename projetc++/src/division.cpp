#include "division.h"
#include <iostream>
#include "cst.h"

#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"					  
using namespace std;

division::division()
{
    //ctor
}

division::~division()
{
    //dtor
}

void division::afficher(){
    cout << "(";
    this->m_opg->afficher();
    cout << "/";
    this->m_opd->afficher();
    cout << ")";
}

void division::afficher_pinv(){
    this->m_opg->afficher_pinv();
    cout << " ";
    this->m_opd->afficher_pinv();
    cout << " / ";
}

float division::calculer(){
    return this->m_opg->calculer() / this->m_opd->calculer();
}

expression* division::simplifier() {
    expression* num = m_opg->simplifier();  // Simplifier le numérateur
    expression* denom = m_opd->simplifier(); // Simplifier le dénominateur

    // Vérifier si le numérateur est une addition
    if (addition* add = dynamic_cast<addition*>(num)) {
        expression* gauche = add->Getopg()->simplifier();
        expression* droite = add->Getopd()->simplifier();

        // Créer les nouvelles divisions
        expression* div1 = new division(gauche, denom);
        expression* div2 = new division(droite, denom);

        // Retourner l'addition des deux nouvelles divisions
        return new addition(div1, div2);
    }

    // Si la simplification plus profonde ne s'applique pas, retourner la division originale
    return new division(num, denom);  // Retourner la division simplifiée
}