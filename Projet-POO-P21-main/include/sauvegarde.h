#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H
#include "include/expression.h"
#include <iostream>
#include <fstream>
#include <string>

class SauvegardeExpression : public expression
{
    private:
        expression* m_root;
    public:
        SauvegardeExpression(expression* root = nullptr) : m_root(root) {}
        virtual ~SauvegardeExpression();

        void afficher(std::ostream& os = std::cout) override {}
        void afficher_pinv(std::ostream& os = std::cout) override {}
        float calculer() override {return 0.0;}
        expression* simplifier() override {return this;}
        float evaluer(const table_symboles& table) const override {return 0.0;}
        void sauvegarder(const std::string& filename) const;
        void charger(const std::string& filename);
        expression* get_expression(){return m_root;}
};

#endif // EXPRESSION_H
