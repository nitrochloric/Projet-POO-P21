#include "include/oppose.h"
#include <iostream>
using namespace std;

oppose::~oppose()
{
    //dtor
}

void oppose::afficher(std::ostream& os) {
    os << "-(";
    m_opg->afficher(os);
    os << ")";
}

void oppose::afficher_pinv(std::ostream& os) {
    m_opg->afficher_pinv(os);
    os << " - ";
}

float oppose::calculer() {
    return -m_opg->calculer();
}

float oppose::evaluer(const table_symboles& table) const {
    return -m_opg->evaluer(table);
}
