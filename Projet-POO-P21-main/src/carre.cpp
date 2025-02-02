#include "include/carre.h"
#include <iostream>
using namespace std;

carre::carre()
{
    //ctor
}

carre::~carre()
{
    //dtor
}

void carre::afficher(std::ostream& os) {
    os << "(";
    m_opg->afficher(os);
    os << ")^2";
}

void carre::afficher_pinv(std::ostream& os) {
    m_opg->afficher_pinv(os);
    os << " ^2 ";
}

float carre::calculer() {
    float value = m_opg->calculer();
    return value * value;
}

float carre::evaluer(const table_symboles& table) const {
    float value = m_opg->evaluer(table);
    return value * value;
}
