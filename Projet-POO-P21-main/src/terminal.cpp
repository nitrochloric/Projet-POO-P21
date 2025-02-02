#include "include/terminal.h"
#include "include/variable.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;


expression* Fexpression_AddExpTerminalPinv(){
    int i = 0;
    string Vs_entre;
    vector<expression*> Fvect_expr_liste;
    int Vi_liste_index;
    int Vb_exit = 0;
    cst* Vcst_val;
    while(not Vb_exit){
        cout << "entrer val ou operateur : " ;
        cin >> Vs_entre;
        Vi_liste_index = Fvect_expr_liste.size() -1;
        if ((Vs_entre[0] - '0' <= 9 && Vs_entre[0] - '0' >= 0) || Vs_entre[0] == '-'){
            Vcst_val = new cst();
            Vcst_val->Setvaleur(stof(Vs_entre));
            Fvect_expr_liste.push_back(Vcst_val);
        }else
        if (Vs_entre == "+"){
            Fvect_expr_liste.push_back(new addition(Fvect_expr_liste.at(Vi_liste_index-1),Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "*"){
            Fvect_expr_liste.push_back(new multiplication(Fvect_expr_liste.at(Vi_liste_index-1),Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "/"){
            Fvect_expr_liste.push_back(new division(Fvect_expr_liste.at(Vi_liste_index-1),Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "inv"){
            Fvect_expr_liste.push_back(new inverse(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "opp"){
            Fvect_expr_liste.push_back(new oppose(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "abs"){
            Fvect_expr_liste.push_back(new valeur_absolue(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "ln"){
            Fvect_expr_liste.push_back(new log_neperien(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "^"){
            Fvect_expr_liste.push_back(new carre(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "sqrt"){
            Fvect_expr_liste.push_back(new racine_carre(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if(Vs_entre == "p"){
            Vb_exit = 1;
        }else
        if(Vs_entre == "x" || Vs_entre == "y"){
            Fvect_expr_liste.push_back(new variable(Vs_entre));
        }
        i = 0;
        printf("\n");
        while(i < Fvect_expr_liste.size()){
            printf("(");
            Fvect_expr_liste.at(i)->afficher_pinv(cout);
            i++;
            printf(") ");
        }
        printf("\n");
    }
    return Fvect_expr_liste.back();
}


expression* Fexpression_AddExpTerminalDC(){
    int i = 0;
    string Vs_entre;
    vector<expression*> Fvect_expr_liste;
    int Vi_liste_index;
    int Vb_exit = 0;
    cst* Vcst_val;
    while(not Vb_exit){
        cout << "entrer val ou operateur : " ;
        cin >> Vs_entre;
        Vi_liste_index = Fvect_expr_liste.size() -1;
        if ((Vs_entre[0] - '0' <= 9 && Vs_entre[0] - '0' >= 0) || Vs_entre[0] == '_'){
            if(Vs_entre[0] == '_'){
                Vs_entre[0] = '-';
            }
            Vcst_val = new cst();
            Vcst_val->Setvaleur(stof(Vs_entre));
            Fvect_expr_liste.push_back(Vcst_val);
        }else
        if (Vs_entre == "+"){
            Fvect_expr_liste.push_back(new addition(Fvect_expr_liste.at(Vi_liste_index-1),Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "*"){
            Fvect_expr_liste.push_back(new multiplication(Fvect_expr_liste.at(Vi_liste_index-1),Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "/"){
            Fvect_expr_liste.push_back(new division(Fvect_expr_liste.at(Vi_liste_index-1),Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "inv"){
            Fvect_expr_liste.push_back(new inverse(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "opp"){
            Fvect_expr_liste.push_back(new oppose(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "abs"){
            Fvect_expr_liste.push_back(new valeur_absolue(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "ln"){
            Fvect_expr_liste.push_back(new log_neperien(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "^"){
            Fvect_expr_liste.push_back(new carre(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if (Vs_entre == "sqrt"){
            Fvect_expr_liste.push_back(new racine_carre(Fvect_expr_liste.at(Vi_liste_index)));
            Fvect_expr_liste.erase(Fvect_expr_liste.end()-2);
        }else
        if(Vs_entre == "p"){
            Vb_exit = 1;
        }else
        if(Vs_entre == "x" || Vs_entre == "y"){
            Fvect_expr_liste.push_back(new variable(Vs_entre));
        }
        i = 0;
        printf("\n");
        while(i < Fvect_expr_liste.size()){
            printf("(");
            Fvect_expr_liste.at(i)->afficher_pinv(cout);
            i++;
            printf(") ");
        }
        printf("\n");
    }
    return Fvect_expr_liste.back();
}
