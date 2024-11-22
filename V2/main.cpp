#include <iostream>
#include "constante.h"
#include "addition.h"
#include "division.h"
#include "operateur.h"
#include "soustraction.h"
#include "multiplication.h"
#include "Variable.h"

using namespace std;

int main() {
    // Déclaration de quelques constantes et variables pour les tests
    constante c1(9.0);  // Constante 5
    constante c2(9.0);  // Constante 2
    constante c3(10.0);  // Constante 4
    constante c4(-3.0); // Constante -3
    constante c5(20.0); // Constante 20
    Variable x("x");    // Variable x
    Variable a("a");    // Variable a
    Variable b("b");    // Variable b


    // === Test Addition ===
    addition add1(&c1, &c2);  // (5 + 2)
    cout << "Expression Addition: ";
    add1.afficher();  // Affiche (5 + 2)
    cout << endl;
    cout << "Resultat du calcul Addition: " << add1.calcul() << endl;  // 5 + 2 = 7

    // Simplification de l'addition (ici, pas de simplification car les constantes sont déjà optimales)
    Expression* simplifieeAdd = add1.simplifier();
    cout << "Expression Addition simplifiee: ";
    simplifieeAdd->afficher();  // Affiche 7
    cout << endl;

    // Expression complexe (4 + (5 + x))
    addition complexAdd(&c1, &x);  // (5 + x)
    addition complexAdd2(&c3, &complexAdd); // (4 + (5 + x)) => simplifiable en (9 + x)
    cout << "Expression Addition complexe: ";
    complexAdd2.afficher();  // Affiche (4 + (5 + x))
    cout << endl;

    // Test de simplification de l'addition complexe
    Expression* simplifieeComplexeAdd = complexAdd2.simplifier();
    cout << "Expression Addition simplifiee complexe: ";
    simplifieeComplexeAdd->afficher();  // Affiche (9 + x)
    cout << endl;


    // === Test Soustraction ===
    soustraction sub1(&c1, &c2);  // (5 - 2)
    cout << "Expression Soustraction: ";
    sub1.afficher();  // Affiche (5 - 2)
    cout << endl;
    cout << "Resultat du calcul Soustraction: " << sub1.calcul() << endl;  // 5 - 2 = 3

    // Simplification de la soustraction (ici, pas de simplification car tout est constant)
    Expression* simplifieeSub = sub1.simplifier();
    cout << "Expression Soustraction simplifiee: ";
    simplifieeSub->afficher();  // Affiche (3)
    cout << endl;

    // Expression complexe (4 - (5 - x))
    soustraction complexSub(&c1, &x);  // (5 - x)
    soustraction complexSub2(&c3, &complexSub); // (4 - (5 - x)) => (4 - (5 - x))
    cout << "Expression Soustraction complexe: ";
    complexSub2.afficher();  // Affiche (4 - (5 - x))
    cout << endl;

    // Test de simplification de la soustraction complexe
    Expression* simplifieeComplexeSub = complexSub2.simplifier();
    cout << "Expression Soustraction simplifiee complexe: ";
    simplifieeComplexeSub->afficher();  // Affiche (4 - (5 - x)) (pas de simplification possible ici)
    cout << endl;


    // === Test Multiplication ===
    multiplication mul1(&c1, &c2);  // (5 * 2)
    cout << "Expression Multiplication: ";
    mul1.afficher();  // Affiche (5 * 2)
    cout << endl;
    cout << "Resultat du calcul Multiplication: " << mul1.calcul() << endl;  // 5 * 2 = 10

    // Simplification de la multiplication
    Expression* simplifieeMul = mul1.simplifier();
    cout << "Expression Multiplication simplifiee: ";
    simplifieeMul->afficher();  // Affiche (10)
    cout << endl;

    // Expression complexe (4 * (5 * x))
    multiplication complexMul(&c1, &x);  // (5 * x)
    multiplication complexMul2(&c3, &complexMul); // (4 * (5 * x)) => simplifiable en (20 * x)
    cout << "Expression Multiplication complexe: ";
    complexMul2.afficher();  // Affiche (4 * (5 * x))
    cout << endl;

    // Test de simplification de la multiplication complexe
    Expression* simplifieeComplexeMul = complexMul2.simplifier();
    cout << "Expression Multiplication simplifiee complexe: ";
    simplifieeComplexeMul->afficher();  // Affiche (20 * x)
    cout << endl;

    // === Test Division ===
    division div1(&c5, &c2);  // (20 / 2)
    cout << "Expression Division: ";
    div1.afficher();  // Affiche (20 / 2)
    cout << endl;
    cout << "Resultat du calcul Division: " << div1.calcul() << endl;  // 20 / 2 = 10

    // Simplification de la division
    Expression* simplifieeDiv = div1.simplifier();
    cout << "Expression Division simplifiee: ";
    simplifieeDiv->afficher();  // Affiche (10)
    cout << endl;

    // Expression complexe ((4 + a) / b)
    addition complexAdd3(&c3, &a);  // (4 + a)
    division complexDiv(&complexAdd3, &b); // ((4 + a) / b)
    cout << "Expression Division complexe: ";
    complexDiv.afficher();  // Affiche ((4 + a) / b)
    cout << endl;

    // Test de simplification de la division complexe
    Expression* simplifieeComplexeDiv = complexDiv.simplifier();
    cout << "Expression Division simplifiee complexe: ";
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

    return 0;
}
