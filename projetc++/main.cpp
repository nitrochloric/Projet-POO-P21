#include <iostream>
#include "addition.h"
#include "soustraction.h"
#include "multiplication.h"
#include "division.h"
#include "cst.h"
#include "operateur.h"
#include "variable.h"

using namespace std;

int main()
{
    // Déclaration de quelques constantes et variables pour les tests
    cst c1(9.0);  // cst 5
    cst c2(9.0);  // cst 2
    cst c3(10.0);  // cst 4
    cst c4(-3.0); // cst -3
    cst c5(20.0); // cst 20
    variable x("x");    // variable x
    variable a("a");    // variable a
    variable b("b");    // variable b


    // === Test Addition ===
    addition add1(&c1, &c2);  // (5 + 2)
    cout << "expression Addition: ";
    add1.afficher();  // Affiche (5 + 2)
    cout << endl;
    cout << "Resultat du calcul Addition: " << add1.calculer() << endl;  // 5 + 2 = 7

    // Simplification de l'addition (ici, pas de simplification car les constantes sont déjà optimales)
    expression* simplifieeAdd = add1.simplifier();
    cout << "expression Addition simplifiee: ";
    simplifieeAdd->afficher();  // Affiche 7
    cout << endl;

    // expression complexe (4 + (5 + x))
    addition complexAdd(&c1, &x);  // (5 + x)
    addition complexAdd2(&c3, &complexAdd); // (4 + (5 + x)) => simplifiable en (9 + x)
    cout << "expression Addition complexe: ";
    complexAdd2.afficher();  // Affiche (4 + (5 + x))
    cout << endl;

    // Test de simplification de l'addition complexe
    expression* simplifieeComplexeAdd = complexAdd2.simplifier();
    cout << "expression Addition simplifiee complexe: ";
    simplifieeComplexeAdd->afficher();  // Affiche (9 + x)
    cout << endl;


    // === Test Soustraction ===
    soustraction sub1(&c1, &c2);  // (5 - 2)
    cout << "expression Soustraction: ";
    sub1.afficher();  // Affiche (5 - 2)
    cout << endl;
    cout << "Resultat du calcul Soustraction: " << sub1.calculer() << endl;  // 5 - 2 = 3

    // Simplification de la soustraction (ici, pas de simplification car tout est constant)
    expression* simplifieeSub = sub1.simplifier();
    cout << "expression Soustraction simplifiee: ";
    simplifieeSub->afficher();  // Affiche (3)
    cout << endl;

    // expression complexe (4 - (5 - x))
    soustraction complexSub(&c1, &x);  // (5 - x)
    soustraction complexSub2(&c3, &complexSub); // (4 - (5 - x)) => (4 - (5 - x))
    cout << "expression Soustraction complexe: ";
    complexSub2.afficher();  // Affiche (4 - (5 - x))
    cout << endl;

    // Test de simplification de la soustraction complexe
    expression* simplifieeComplexeSub = complexSub2.simplifier();
    cout << "expression Soustraction simplifiee complexe: ";
    simplifieeComplexeSub->afficher();  // Affiche (4 - (5 - x)) (pas de simplification possible ici)
    cout << endl;


    // === Test Multiplication ===
    multiplication mul1(&c1, &c2);  // (5 * 2)
    cout << "expression Multiplication: ";
    mul1.afficher();  // Affiche (5 * 2)
    cout << endl;
    cout << "Resultat du calcul Multiplication: " << mul1.calculer() << endl;  // 5 * 2 = 10

    // Simplification de la multiplication
    expression* simplifieeMul = mul1.simplifier();
    cout << "expression Multiplication simplifiee: ";
    simplifieeMul->afficher();  // Affiche (10)
    cout << endl;

    // expression complexe (4 * (5 * x))
    multiplication complexMul(&c1, &x);  // (5 * x)
    multiplication complexMul2(&c3, &complexMul); // (4 * (5 * x)) => simplifiable en (20 * x)
    cout << "expression Multiplication complexe: ";
    complexMul2.afficher();  // Affiche (4 * (5 * x))
    cout << endl;

    // Test de simplification de la multiplication complexe
    expression* simplifieeComplexeMul = complexMul2.simplifier();
    cout << "expression Multiplication simplifiee complexe: ";
    simplifieeComplexeMul->afficher();  // Affiche (20 * x)
    cout << endl;

    // === Test Division ===
    division div1(&c5, &c2);  // (20 / 2)
    cout << "expression Division: ";
    div1.afficher();  // Affiche (20 / 2)
    cout << endl;
    cout << "Resultat du calcul Division: " << div1.calculer() << endl;  // 20 / 2 = 10

    // Simplification de la division
    expression* simplifieeDiv = div1.simplifier();
    cout << "expression Division simplifiee: ";
    simplifieeDiv->afficher();  // Affiche (10)
    cout << endl;

    // expression complexe ((4 + a) / b)
    addition complexAdd3(&c3, &a);  // (4 + a)
    division complexDiv(&complexAdd3, &b); // ((4 + a) / b)
    cout << "expression Division complexe: ";
    complexDiv.afficher();  // Affiche ((4 + a) / b)
    cout << endl;

    // Test de simplification de la division complexe
    expression* simplifieeComplexeDiv = complexDiv.simplifier();
    cout << "expression Division simplifiee complexe: ";
    simplifieeComplexeDiv->afficher();  // Affiche ((4 + a) / b) (pas de simplification possible ici)
    cout << endl;


    // Nettoyage de la mémoire (pour éviter les fuites)
    delete simplifieeAdd;
    delete simplifieeComplexeAdd;
    delete simplifieeSub;
    delete simplifieeComplexeSub;
    delete simplifieeMul;
    delete simplifieeComplexeMul;
    delete simplifieeDiv;
    delete simplifieeComplexeDiv;
    /*
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
    */
    return 0;
}
