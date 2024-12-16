#include "constante.h"
#include <iostream>
using namespace std;

constante::constante(float v) {
    m_valeur = v;
}

constante::~constante() {
    // dtor
}

void constante::afficher() {
    cout << m_valeur;
}

float constante::calcul() {
    return m_valeur;
}

Expression* constante::simplifier() {
    return this; // Les constantes ne peuvent pas être simplifiées
}
