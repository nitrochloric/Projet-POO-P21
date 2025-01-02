#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <Expression.h>
#include <iostream>

using namespace std;


class Constante : public Expression
{
    public:
        Constante();
        inline void afficher() { cout << m_valeur << endl;}
        inline float calculer() { return m_valeur;};
        virtual ~Constante();

    protected:

    private:
        float m_valeur;
};

#endif // CONSTANTE_H
