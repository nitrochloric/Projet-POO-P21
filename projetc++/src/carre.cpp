#include "carre.h"
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

void carre::afficher() {
    cout << "(";
    m_opg->afficher();
    cout << ")^2";
}

void carre::afficher_pinv() {
    m_opg->afficher_pinv();
    cout << " ^2 ";
}

float carre::calculer() {
    float value = m_opg->calculer();
    return value * value;
}
