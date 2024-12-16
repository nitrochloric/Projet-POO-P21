#include "soustraction.h"
#include <iostream>
using namespace std;

soustraction::soustraction()
{
    //ctor
}

soustraction::~soustraction()
{
    //dtor
}

void soustraction::afficher(){
    cout << "(";
    this->m_opg->afficher();
    cout << "-";
    this->m_opd->afficher();
    cout << ")";
}

void soustraction::afficher_pinv(){
    this->m_opg->afficher_pinv();
    cout << " ";
    this->m_opd->afficher_pinv();
    cout << " - ";
}

float soustraction::calculer(){
    return this->m_opg->calculer() - this->m_opd->calculer();
}
