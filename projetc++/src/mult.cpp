#include "mult.h"
#include <iostream>
using namespace std;

mult::mult()
{
    //ctor
}

mult::~mult()
{
    //dtor
}

void mult::afficher(){
    cout << "(";
    this->m_opg->afficher();
    cout << "*";
    this->m_opd->afficher();
    cout << ")";
}

void mult::afficher_pinv(){
    this->m_opg->afficher_pinv();
    cout << " ";
    this->m_opd->afficher_pinv();
    cout << " * ";
}

float mult::calculer(){
    return this->m_opg->calculer() * this->m_opd->calculer();
}
