#include "cst.h"
#include <iostream>
using namespace std;

cst::cst()
{
    //ctor
}

cst::~cst()
{
    //dtor
}

void cst::afficher(){
    cout << m_valeur;
}

void cst::afficher_pinv(){
    cout << m_valeur;
}

float cst::calculer(){
    return m_valeur;
}

expression* cst::simplifier() {
    return this; // Les constantes ne peuvent pas être simplifiées
}
