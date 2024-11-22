#include "div.h"
#include <iostream>
using namespace std;

divd::divd()
{
    //ctor
}

divd::~divd()
{
    //dtor
}

void divd::afficher(){
    cout << "(";
    this->m_opg->afficher();
    cout << "/";
    this->m_opd->afficher();
    cout << ")";
}

void divd::afficher_pinv(){
    this->m_opg->afficher_pinv();
    cout << " ";
    this->m_opd->afficher_pinv();
    cout << " / ";
}

float divd::calculer(){
    return this->m_opg->calculer() / this->m_opd->calculer();
}
