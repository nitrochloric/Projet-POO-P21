#include <iostream>
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "cst.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cst c1(2);
    cst c2(3);
    cst c3(5);
    cst c4(1);
    addition a1(&c1,&c2);
    multiplication m1(&a1,&c3);
    soustraction s1(&m1,&c4);
    division d1(&s1,&c3);
    d1.afficher();
    cout << endl;
    d1.afficher_pinv();
    cout << endl << "result = " << d1.calculer();
    return 0;
}
