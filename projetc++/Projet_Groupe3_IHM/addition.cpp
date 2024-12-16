#include "addition.h"
#include <iostream>
using namespace std;

addition::addition()
{
    //ctor
}

addition::~addition()
{
    //dtor
}

void addition::afficher(){
    cout << "(";
    this->m_opg->afficher();
    cout << "+";
    this->m_opd->afficher();
    cout << ")";
}

void addition::afficher_pinv(){
    this->m_opg->afficher_pinv();
    cout << " ";
    this->m_opd->afficher_pinv();
    cout << " + ";
}

float addition::calculer(){
    return this->m_opg->calculer() + this->m_opd->calculer();
}
