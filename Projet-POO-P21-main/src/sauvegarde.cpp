#include "include/sauvegarde.h"
#include <vector>
#include <sstream>
#include <cctype>
#include "include/cst.h"
#include "include/addition.h"
#include "include/soustraction.h"
#include "include/multiplication.h"
#include "include/division.h"
#include "include/carre.h"
#include "include/inverse.h"
#include "include/log_neperien.h"
#include "include/oppose.h"
#include "include/racine_carre.h"
#include "include/valeur_absolue.h"
#include "include/variable.h"

using namespace std;

SauvegardeExpression::~SauvegardeExpression() {
    delete m_root;  // Nettoie correctement la hiérarchie des expressions
}

void SauvegardeExpression::sauvegarder(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        m_root->afficher_pinv(file);
        file.close();
    } else {
        cerr << "Erreur : Impossible d'ouvrir le fichier." << endl;
    }
}

void SauvegardeExpression::charger(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier pour chargement." << endl;
        return;
    }
    int i = 0;
    string Vs_entre;
    vector<expression*> Fvect_expr_liste;
    int Vi_liste_index;
    int Vb_exit = 0;
    cst* Vcst_val;
    while(file >> Vs_entre){
        Vi_liste_index = Fvect_expr_liste.size() -1;
        if (Vs_entre[0] - '0' <= 9 && Vs_entre[0] - '0' >= 0 || Vs_entre[0] == '-'){
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
    }
    delete m_root;
    m_root = Fvect_expr_liste.back();
}
