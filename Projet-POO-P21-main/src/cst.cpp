#include "include/cst.h"
#include <iostream>
using namespace std;

cst::cst()
{
    //ctor
}

cst::~cst()
{
    //dtor
}

void cst::afficher(std::ostream& os) {
    os << m_valeur;
}

void cst::afficher_pinv(std::ostream& os){
    os << m_valeur;
}

float cst::calculer(){
    return m_valeur;
}

float cst::evaluer(const table_symboles& table) const {
    return m_valeur;
}

expression* cst::simplifier() {
    return this; // Les constantes ne peuvent pas être simplifiées
}
