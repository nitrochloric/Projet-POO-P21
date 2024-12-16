#include "valeur_absolue.h"
#include <iostream>
#include <cmath>
using namespace std;

valeur_absolue::~valeur_absolue()
{
    //dtor
}

void valeur_absolue::afficher() {
    cout << "|";
    m_opg->afficher();
    cout << "|";
}

void valeur_absolue::afficher_pinv() {
    m_opg->afficher_pinv();
    cout << " | | ";
}

float valeur_absolue::calculer() {
    return fabs(m_opg->calculer());
}
