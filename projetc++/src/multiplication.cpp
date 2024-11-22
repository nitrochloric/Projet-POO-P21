#include "multiplication.h"
#include <iostream>
using namespace std;

multiplication::multiplication()
{
    //ctor
}

multiplication::~multiplication()
{
    //dtor
}

void multiplication::afficher(){
    cout << "(";
    this->m_opg->afficher();
    cout << "*";
    this->m_opd->afficher();
    cout << ")";
}

void multiplication::afficher_pinv(){
    this->m_opg->afficher_pinv();
    cout << " ";
    this->m_opd->afficher_pinv();
    cout << " * ";
}

float multiplication::calculer(){
    return this->m_opg->calculer() * this->m_opd->calculer();
}
