#ifndef TABLE_SYMBOLES_H
#define TABLE_SYMBOLES_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <stdexcept>

class table_symboles {
private:
    std::unordered_map<std::string, float> m_table;  // Associe un nom de variable à sa valeur

public:
    void ajouter_variable(const std::string& nom, float valeur) {
        m_table[nom] = valeur;
    }

    float obtenir_valeur(const std::string& nom) const {
        auto it = m_table.find(nom);
        if (it != m_table.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Erreur : La variable '" + nom + "' n'est pas définie.");
        }
    }
};

#endif // TABLE_SYMBOLES_H
