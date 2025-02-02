#include "include/valeur_absolue.h"
#include <iostream>
#include <cmath>
using namespace std;

valeur_absolue::~valeur_absolue()
{
    //dtor
}

void valeur_absolue::afficher(std::ostream& os) {
    os << "|";
    m_opg->afficher(os);
    os << "|";
}

void valeur_absolue::afficher_pinv(std::ostream& os) {
    m_opg->afficher_pinv(os);
    os << " | | ";
}

float valeur_absolue::calculer() {
    return fabs(m_opg->calculer());
}

float valeur_absolue::evaluer(const table_symboles& table) const {
    return fabs(m_opg->evaluer(table));
}
