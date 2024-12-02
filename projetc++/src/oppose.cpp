#include "oppose.h"
#include <iostream>
using namespace std;

oppose::~oppose()
{
    //dtor
}

void oppose::afficher() {
    cout << "-(";
    m_opg->afficher();
    cout << ")";
}

void oppose::afficher_pinv() {
    m_opg->afficher_pinv();
    cout << " - ";
}

float oppose::calculer() {
    return -m_opg->calculer();
}
