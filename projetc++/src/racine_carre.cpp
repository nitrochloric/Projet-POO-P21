#include "racine_carre.h"
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

void racine_carre::afficher() {
    cout << "sqrt(";
    m_opg->afficher();
    cout << ")";
}

void racine_carre::afficher_pinv() {
    m_opg->afficher_pinv();
    cout << " sqrt ";
}

float racine_carre::calculer() {
    return sqrt(m_opg->calculer());
}
