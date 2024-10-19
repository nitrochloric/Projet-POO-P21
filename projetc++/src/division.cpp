#include "division.h"
#include <iostream>
using namespace std;

division::division()
{
    //ctor
}

division::~division()
{
    //dtor
}

void division::afficher(){
    cout << "(";
    this->m_opg->afficher();
    cout << "/";
    this->m_opd->afficher();
    cout << ")";
}

void division::afficher_pinv(){
    this->m_opg->afficher_pinv();
    cout << " ";
    this->m_opd->afficher_pinv();
    cout << " / ";
}

float division::calculer(){
    return this->m_opg->calculer() / this->m_opd->calculer();
}
