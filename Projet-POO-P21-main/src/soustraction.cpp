#include "include/soustraction.h"
#include "include/cst.h"
#include <iostream>
using namespace std;

soustraction::soustraction()
{
    //ctor
}

soustraction::~soustraction()
{
    //dtor
}

void soustraction::afficher(std::ostream& os){
    os << "(";
    this->m_opg->afficher(os);
    os << "-";
    this->m_opd->afficher(os);
    os << ")";
}

void soustraction::afficher_pinv(std::ostream& os){
    this->m_opg->afficher_pinv(os);
    os << " ";
    this->m_opd->afficher_pinv(os);
    os << " - ";
}

float soustraction::calculer(){
    return this->m_opg->calculer() - this->m_opd->calculer();
}

float soustraction::evaluer(const table_symboles& table) const {
    return this->m_opg->evaluer(table) - this->m_opd->evaluer(table);
}

expression* soustraction::simplifier() {
    expression* gauche = m_opg->simplifier();  // Simplifier l'opérande gauche
    expression* droite = m_opd->simplifier();  // Simplifier l'opérande droite

    // Vérifier si les deux opérandes sont des constantes
    if (dynamic_cast<cst*>(gauche) && dynamic_cast<cst*>(droite)) {
        return new cst(gauche->calculer() - droite->calculer());
    }

    // Si un des côtés est une cst et l'autre est une soustraction impliquant une cst
    if (dynamic_cast<cst*>(gauche) && dynamic_cast<soustraction*>(droite)) {
        soustraction* sub_droite = dynamic_cast<soustraction*>(droite);
        if (dynamic_cast<cst*>(sub_droite->m_opg)) {
            float difference = gauche->calculer() - sub_droite->m_opg->calculer();
            return new soustraction(new cst(difference), sub_droite->m_opd);
        }
    }

    if (dynamic_cast<cst*>(droite) && dynamic_cast<soustraction*>(gauche)) {
        soustraction* sub_gauche = dynamic_cast<soustraction*>(gauche);
        if (dynamic_cast<cst*>(sub_gauche->m_opg)) {
            float difference = sub_gauche->m_opg->calculer() - droite->calculer();
            return new soustraction(new cst(difference), sub_gauche->m_opd);
        }
    }

    // Si les simplifications plus profondes ne s'appliquent pas, retourner la soustraction originale
    return new soustraction(gauche, droite);  // Retourner la soustraction simplifiée
}
