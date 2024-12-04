#include "inverse.h"
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

void inverse::afficher() {
    cout << "1/(";
    m_opg->afficher();
    cout << ")";
}

void inverse::afficher_pinv() {
    cout << " 1/ ";
    m_opg->afficher_pinv();
}

float inverse::calculer() {
    return 1 / m_opg->calculer();
}
