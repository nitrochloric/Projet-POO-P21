#include "add.h"
#include <iostream>
using namespace std;

add::add()
{
    //ctor
}

add::~add()
{
    //dtor
}

void add::afficher(){
    cout << "(";
    this->m_opg->afficher();
    cout << "+";
    this->m_opd->afficher();
    cout << ")";
}

void add::afficher_pinv(){
    this->m_opg->afficher_pinv();
    cout << " ";
    this->m_opd->afficher_pinv();
    cout << " + ";
}

float add::calculer(){
    return this->m_opg->calculer() + this->m_opd->calculer();
}
