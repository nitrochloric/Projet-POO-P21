#include "include/log_neperien.h"
#include <iostream>
#include <cmath>
using namespace std;

log_neperien::log_neperien()
{
    //ctor
}

log_neperien::~log_neperien()
{
    //dtor
}

void log_neperien::afficher(std::ostream& os) {
    os << "ln(";
    m_opg->afficher(os);
    os << ")";
}

void log_neperien::afficher_pinv(std::ostream& os) {
    m_opg->afficher_pinv(os);
    os << " ln ";
}

float log_neperien::calculer() {
    return log(m_opg->calculer());
}

float log_neperien::evaluer(const table_symboles& table) const {
    return log(m_opg->evaluer(table));
}
