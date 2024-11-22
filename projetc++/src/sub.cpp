#include "sub.h"
#include <iostream>
using namespace std;

sub::sub()
{
    //ctor
}

sub::~sub()
{
    //dtor
}

void sub::afficher(){
    cout << "(";
    this->m_opg->afficher();
    cout << "-";
    this->m_opd->afficher();
    cout << ")";
}

void sub::afficher_pinv(){
    this->m_opg->afficher_pinv();
    cout << " ";
    this->m_opd->afficher_pinv();
    cout << " - ";
}

float sub::calculer(){
    return this->m_opg->calculer() - this->m_opd->calculer();
}
