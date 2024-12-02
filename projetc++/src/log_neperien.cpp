#include "log_neperien.h"
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

void log_neperien::afficher() {
    cout << "ln(";
    m_opg->afficher();
    cout << ")";
}

void log_neperien::afficher_pinv() {
    m_opg->afficher_pinv();
    cout << " ln ";
}

float log_neperien::calculer() {
    return log(m_opg->calculer());
}
