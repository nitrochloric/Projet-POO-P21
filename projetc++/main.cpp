#include <iostream>
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "cst.h"
#include "inverse.h"
#include "oppose.h"
#include "valeur_absolue.h"
#include "log_neperien.h"
#include "carre.h"
#include "racine_carre.h"

using namespace std;

int main()
{
    cst c1(2);
    cst c2(3);
    cst c3(5);
    cst c4(1);

    addition a1(&c1, &c2);
    multiplication m1(&a1, &c3);
    soustraction s1(&m1, &c4);
    division d1(&s1, &c3);

    inverse inv(&a1);
    oppose opp(&a1);
    valeur_absolue abs_val(&a1);
    log_neperien ln(&a1);
    carre sq(&a1);
    racine_carre sqrt_val(&a1);


    d1.afficher();
    cout << endl;
    d1.afficher_pinv();
    cout << endl << "result = " << d1.calculer() << endl;

    inv.afficher();
    cout << "Inverse: ";
    inv.afficher();
    cout << " = " << inv.calculer() << endl;

    cout << "Oppose: ";
    opp.afficher();
    cout << " = " << opp.calculer() << endl;

    cout << "Valeur absolue: ";
    abs_val.afficher();
    cout << " = " << abs_val.calculer() << endl;

    cout << "Log népérien: ";
    ln.afficher();
    cout << " = " << ln.calculer() << endl;

    cout << "Carré: ";
    sq.afficher();
    cout << " = " << sq.calculer() << endl;

    cout << "Racine carrée: ";
    sqrt_val.afficher();
    cout << " = " << sqrt_val.calculer() << endl;

    return 0;
}
