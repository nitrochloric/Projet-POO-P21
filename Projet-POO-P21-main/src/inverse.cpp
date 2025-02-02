#include "include/inverse.h"
#include <iostream>
using namespace std;

inverse::inverse()
{
    //ctor
}

inverse::~inverse()
{
    //dtor
}

void inverse::afficher(std::ostream& os) {
    os << "1/(";
    m_opg->afficher(os);
    os << ")";
}

void inverse::afficher_pinv(std::ostream& os) {
    os << " 1/ ";
    m_opg->afficher_pinv(os);
}

float inverse::calculer() {
    return 1 / m_opg->calculer();
}

float inverse::evaluer(const table_symboles& table) const {
    return 1 / m_opg->evaluer(table);
}
