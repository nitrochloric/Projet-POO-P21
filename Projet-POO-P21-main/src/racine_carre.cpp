#include "include/racine_carre.h"
#include <iostream>
#include <cmath>
using namespace std;

racine_carre::racine_carre()
{
    //ctor
}

racine_carre::~racine_carre()
{
    //dtor
}

void racine_carre::afficher(std::ostream& os) {
    os << "sqrt(";
    m_opg->afficher(os);
    os << ")";
}

void racine_carre::afficher_pinv(std::ostream& os) {
    m_opg->afficher_pinv(os);
    os << " sqrt ";
}

float racine_carre::calculer() {
    return sqrt(m_opg->calculer());
}

float racine_carre::evaluer(const table_symboles& table) const {
    return sqrt(m_opg->evaluer(table));
}
